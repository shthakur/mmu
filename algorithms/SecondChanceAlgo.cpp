#include "SecondChanceAlgo.h"
#include <queue>
#include "../modules/Entry.h"
#include "../modules/FrameTable.h"

SecondChanceAlgo::SecondChanceAlgo() {

}

int SecondChanceAlgo::getFrame(int pte_index, Entry* page_table[], FrameTable* frame_table) {
  int frame = frame_table->getFreeFrame();
  if (frame != -1) {
    entry_q.push(page_table[pte_index]);
    return frame;
  } else {
    Entry *entry = entry_q.front();
    entry_q.pop();

    while(entry->referenced != 0) {
        entry->referenced = 0;
        entry_q.push(entry);
        entry = entry_q.front();
        entry_q.pop();
    }
    entry_q.push(page_table[pte_index]);
    return entry->frame_index;
  }
}
