#ifndef AgingAlgo_h
#define AgingAlgo_h

#include "../modules/FrameTable.h"
#include "../modules/Entry.h"
#include "../modules/FileReader.h"
#include "BaseAlgo.h"
#include <vector>

class AgingAlgo : public BaseAlgo {
public:
  AgingAlgo(int type, FrameTable*);
  unsigned long *counts;
  int type;
  int getFrame(int, Entry*[], FrameTable*);
};

#endif
