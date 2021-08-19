#ifndef ClockAlgo_h
#define ClockAlgo_h

#include "../modules/FrameTable.h"
#include "../modules/Entry.h"
#include "../modules/FileReader.h"
#include "BaseAlgo.h"
#include <vector>

class ClockAlgo : public BaseAlgo {
public:
  ClockAlgo(int type, FrameTable*);
  unsigned long *counts;
  int type;
  int hand;
  int getFrame(int, Entry*[], FrameTable*);
};

#endif
