#ifndef NRUAlgo_h
#define NRUAlgo_h

#include "../modules/FrameTable.h"
#include "../modules/Entry.h"
#include "../modules/FileReader.h"
#include "BaseAlgo.h"
#include <vector>

class NRUAlgo : public BaseAlgo {
public:
  NRUAlgo(FileReader&);
  std::vector<int> classes[4];
  FileReader* fileReader;
  int count;
  int getFrame(int, Entry*[], FrameTable*);
};

#endif
