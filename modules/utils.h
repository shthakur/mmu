#ifndef utils_h
#define utils_h

#include "../algorithms/BaseAlgo.h"
#include "FileReader.h"
#include "FrameTable.h"
#include <string>

BaseAlgo* getAlgo(std::string, FileReader&, FrameTable*);

#endif
