#ifndef RandomAlgo_h
#define RandomAlgo_h

#include "../modules/FrameTable.h"
#include "../modules/Entry.h"
#include "../modules/FileReader.h"
#include "BaseAlgo.h"
#include <vector>

class RandomAlgo : public BaseAlgo {
public:
  RandomAlgo(FileReader&);
  FileReader* fileReader;
  int getFrame(int, Entry*[], FrameTable*);
};

#endif
