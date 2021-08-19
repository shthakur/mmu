#include "AgingAlgo.h"
#include "../modules/FrameTable.h"
#include "../modules/FileReader.h"
#include "../modules/Entry.h"
#include "../modules/constants.h"
#include <iostream>

AgingAlgo::AgingAlgo(int type, FrameTable* frame_table) {
  this->type = type;

  if (type == VIRTUAL) {
    counts = new unsigned long[64]();
  } else {
    counts = new unsigned long[frame_table->num_frames]();
  }
}

int AgingAlgo::getFrame(int index, Entry* page_table[], FrameTable* frame_table) {
  int frame = frame_table->getFreeFrame();
  if (frame != -1) {
    return frame;
  } else {
    if (type == VIRTUAL) {
        int frame;

        for(int i = 0; i < 64; i++) {
          if (page_table[i]->present) {
            frame = i;
            break;
          }
        }
        for(int i = 0; i < 64; i++) {
          if (page_table[i]->present) {
            counts[i] = counts[i] >> 1;

            if (page_table[i]->referenced == 1) {
              counts[i] |= (unsigned long long)1 << 31;
              page_table[i]->referenced = 0;
            }

            if (counts[i] < counts[frame]) {
              frame = i;
            }
          }
        }

        counts[frame] = 0;

        return page_table[frame]->frame_index;
    } else {
      int frame = 0;
      for(int i = 0; i < frame_table->num_frames; i++) {
        counts[i] = counts[i] >> 1;

        if (page_table[frame_table->mapping[i]]->referenced) {
          counts[i] |= (unsigned long long)1 << 31;
          page_table[frame_table->mapping[i]]->referenced = 0;
        }

        if (counts[i] < counts[frame]) {
          frame = i;
        }
      }
      counts[frame] = 0;
      return frame;
    }
  }

}
