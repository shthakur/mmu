#include <queue>
#include <fstream>
#include <cstddef>
#include <iostream>
#include <climits>
#include <cstdio>
#include <string>
#include "constants.h"
#include "Simulator.h"
#include "FileReader.h"
#include "Args.h"
#include "FrameTable.h"
#include "../algorithms/BaseAlgo.h"
#include "../algorithms/FIFOAlgo.h"
#include "utils.h"

// Constructor, set file reader and algo
Simulator::Simulator(std::string input_file_name,
std::string random_file_name, Args args)
: input_file(input_file_name), random_file(random_file_name),
fileReader(input_file, random_file), stats() {
  fileReader.resetRandom();
  options = args.options;
  this->args = args;
}

void Simulator::bootstrap() {
  frame_table = new FrameTable(args.num_frames);
  std::string algo = args.algo;
  pager = getAlgo(algo, fileReader, frame_table);
  instruction_number = 0;

  for(int i = 0; i < 64; i++) {
    page_table[i] = new Entry(i);
  }
}

void Simulator::run() {
  bootstrap();
  simulate();
  printPageTable();
  frame_table->printFrameTable();
  stats.printSummary();
}

void Simulator::simulate() {
    while(true) {
      try {
        cycle();
      } catch (const std::string& e) {
        break;
      }
    }
}

void Simulator::cycle() {
  Instruction instr = fileReader.getNextInstruction();
  stats.incrementInstructionCount();
  stats.incrementTotalCost();

  if (options.print_output) {
    std::cout<<"==> inst: "<<instr.line<<std::endl;
  }

  int index = instr.virtual_page;
  int rw = instr.read_or_write;
  int frame;
  if (page_table[index]->present) {
    page_table[index]->referenced = 1;

    if (rw == 1) {
      page_table[index]->modified = 1;
    }
  } else {
    frame = getFrame(index);

    if (frame_table->mapping[frame] != -1) {
      int page_table_index = frame_table->mapping[frame];
      Entry* entry = page_table[page_table_index];

      if (options.print_output) {
        std::cout<<instruction_number<<": UNMAP "<<frame_table->mapping[frame]<<" "<<frame<<std::endl;
      }
      stats.incrementUnmaps();

      entry->present = 0;
      if (entry->modified == 1) {
        entry->modified = 0;
        entry->paged_out = 1;
        if (options.print_output) {
          std::cout<<instruction_number<<": OUT "<<frame_table->mapping[frame]<<" "<<frame<<std::endl;
        }
        stats.incrementOuts();
      }

      entry = page_table[index];
      if (entry->paged_out == 1) {
        // entry->paged_out = 0;
        if (options.print_output) {
          std::cout<<instruction_number<<": IN "<<index<<" "<<frame<<std::endl;
        }
        stats.incrementIns();
      } else {
        if (options.print_output) {
          std::cout<<instruction_number<<": ZERO "<<frame<<std::endl;
        }
        stats.incrementZeros();
      }
    } else {
      if (options.print_output) {
        std::cout<<instruction_number<<": ZERO "<<frame<<std::endl;
      }
      stats.incrementZeros();
    }
    Entry* entry = page_table[index];
    entry->present = 1;
    entry->referenced = 1;
    entry->frame_index = frame;
    frame_table->mapping[frame] = index;

    if (rw == 1) {
      entry->modified = 1;
    }

    if (options.print_output) {
      std::cout<<instruction_number<<": MAP "<<frame_table->mapping[frame]<<" "<<frame<<std::endl;
    }
    stats.incrementMaps();

  }

  if (options.print_pagetable_always) {
    printPageTable();
  }

  if (options.print_frametable_always) {
    frame_table->printFrameTable();
  }

  instruction_number++;
}


void Simulator::printPageTable() {
  for(int i = 0; i < 64; i++){
    if (page_table[i]->present == 1) {
      std::cout<<i<<":";
      if (page_table[i]->referenced == 1) {
        std::cout<<"R";
      } else {
        std::cout<<"-";
      }
      if (page_table[i]->modified == 1) {
        std::cout<<"M";
      } else {
        std::cout<<"-";
      }
      if (page_table[i]->paged_out == 1) {
        std::cout<<"S ";
      } else{
        std::cout<<"- ";
      }
    } else {
      if (page_table[i]->paged_out == 1) {
        std::cout<<"# ";
      } else {
        std::cout<<"* ";
      }
    }
  }
  std::cout<<std::endl;;
}
int Simulator::getFrame(int index) {
  int frame = pager->getFrame(index, page_table, frame_table);
  return frame;
}
