#ifndef FIFOAlgo_h
#define FIFOAlgo_h

#include "BaseAlgo.h"
#include "../modules/Entry.h"
#include "../modules/FrameTable.h"
#include <queue>


class FIFOAlgo: public BaseAlgo {
public:
  FIFOAlgo();
  int getFrame(int, Entry* pt[], FrameTable*);
  std::queue<int> entry_q;
};

#endif
