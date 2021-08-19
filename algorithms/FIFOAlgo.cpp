#include "FIFOAlgo.h"
#include <queue>
#include "../modules/Entry.h"
#include "../modules/FrameTable.h"

FIFOAlgo::FIFOAlgo() {

}

int FIFOAlgo::getFrame(int pte_index, Entry* pt[], FrameTable* frame_table) {
  int frame = frame_table->getFreeFrame();
  if (frame != -1) {
    entry_q.push(frame);
    return frame;
  } else {
    frame = entry_q.front();
    entry_q.pop();
    entry_q.push(frame);
    return frame;
  }
}
