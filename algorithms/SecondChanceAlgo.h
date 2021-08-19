#ifndef SecondChanceAlgo_h
#define SecondChanceAlgo_h

#include "BaseAlgo.h"
#include "../modules/Entry.h"
#include "../modules/FrameTable.h"
#include <queue>


class SecondChanceAlgo: public BaseAlgo {
public:
  SecondChanceAlgo();
  int getFrame(int, Entry* pt[], FrameTable*);
  std::queue<Entry*> entry_q;
};

#endif
