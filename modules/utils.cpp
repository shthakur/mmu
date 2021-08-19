#include "utils.h"
#include "constants.h"
#include "../algorithms/BaseAlgo.h"
#include "../algorithms/FIFOAlgo.h"
#include "../algorithms/NRUAlgo.h"
#include "../algorithms/RandomAlgo.h"
#include "../algorithms/AgingAlgo.h"
#include "../algorithms/SecondChanceAlgo.h"
#include "../algorithms/ClockAlgo.h"
#include "FileReader.h"
#include "FrameTable.h"
#include <iostream>
BaseAlgo* getAlgo(std::string type, FileReader &fileReader, FrameTable* frame_table) {
  BaseAlgo* algo;
  if (type[0] == 'f') {
    algo = new FIFOAlgo();
  } else if (type[0] == 'N') {
    algo = new NRUAlgo(fileReader);
  } else if (type[0] == 'r') {
    algo = new RandomAlgo(fileReader);
  } else if (type[0] == 'Y') {
    algo = new AgingAlgo(VIRTUAL, frame_table);
  } else if (type[0] == 'a') {
    algo = new AgingAlgo(PHYSICAL, frame_table);
  } else if (type[0] == 'X') {
    algo = new ClockAlgo(VIRTUAL, frame_table);
  } else if (type[0] == 'c') {
    algo = new ClockAlgo(PHYSICAL, frame_table);
  } else if (type[0] == 's') {
    algo = new SecondChanceAlgo();
  }
  return algo;
}
