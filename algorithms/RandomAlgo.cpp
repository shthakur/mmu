#include "RandomAlgo.h"
#include "../modules/FrameTable.h"
#include "../modules/FileReader.h"
#include "../modules/Entry.h"
#include <iostream>

RandomAlgo::RandomAlgo(FileReader &reader) {
  fileReader = &reader;
}

int RandomAlgo::getFrame(int index, Entry* page_table[], FrameTable* frame_table) {
  int frame = frame_table->getFreeFrame();

  if (frame != -1) {
    return frame;
  } else {
    int num_frames = frame_table->num_frames;
    int frame = fileReader->getRandom(num_frames);
  }
}
