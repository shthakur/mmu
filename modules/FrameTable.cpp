#include "FrameTable.h"
#include <iostream>
#include <ctype.h>

FrameTable::FrameTable(int num_frames) {
  this->num_frames = num_frames;

  for(int i = 0; i < num_frames; i++) {
    mapping.push_back(-1);
  }
}

void FrameTable::printFrameTable() {
  for(int i = 0; i < num_frames; i++) {
    if (mapping[i] != -1) {
      std::cout<<mapping[i]<<" ";
    } else {
      std::cout<<"* ";
    }
  }
  std::cout<<std::endl;
}

int FrameTable::getFreeFrame() {
  int frame = -1;
  for(int i = 0; i < this->num_frames; i++) {
    if (mapping[i] == -1) {
      frame = i;
      break;
    }
  }

  return frame;
}
