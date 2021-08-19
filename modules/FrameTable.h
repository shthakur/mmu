#ifndef FrameTable_h
#define FrameTable_h

#include "Entry.h"
#include <vector>

class FrameTable {
public:
  std::vector<int> mapping;
  int num_frames;
  FrameTable(int frames);
  void printFrameTable();
  int getFreeFrame();
};

#endif
