#ifndef BaseAlgo_h
#define BaseAlgo_h

#include <string>
#include "../modules/Entry.h"
#include "../modules/FrameTable.h"
class BaseAlgo {
public:
  BaseAlgo();
  virtual int getFrame(int, Entry* pt[], FrameTable*) = 0;
};

#endif
