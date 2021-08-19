#ifndef Simulator_h
#define Simulator_h

#include <queue>
#include <string>
#include <vector>
#include "../algorithms/BaseAlgo.h"
#include "FileReader.h"
#include "Args.h"
#include "FrameTable.h"
#include "Entry.h"
#include "Stats.h"

class Simulator {
private:
  FileReader fileReader;
  BaseAlgo *pager;
  FrameTable* frame_table;
  Entry* page_table[64];
  std::ifstream input_file;
  std::ifstream random_file;
  std::string algo_type;
  Stats stats;
  int instruction_number;
  Args args;
  Options options;
public:
  Simulator(std::string, std::string, Args args);
  void bootstrap();
  void run();
  void simulate();
  void cycle();
  int getFrame(int);
  void printPageTable();
};

#endif
