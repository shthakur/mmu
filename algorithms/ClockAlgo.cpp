#include "ClockAlgo.h"
#include "../modules/FrameTable.h"
#include "../modules/FileReader.h"
#include "../modules/Entry.h"
#include "../modules/constants.h"
#include <iostream>

ClockAlgo::ClockAlgo(int type, FrameTable* frame_table) {
  this->type = type;
  hand = 0;
}

int ClockAlgo::getFrame(int index, Entry* page_table[], FrameTable* frame_table) {
  int frame = frame_table->getFreeFrame();
  int num_frames = frame_table->num_frames;
  if (frame != -1) {
    return frame;
  } else {
    if (type == VIRTUAL) {
      bool flag = false;

      while(!flag) {
        if (page_table[hand]->present == 1) {
          if (page_table[hand]->referenced == 0) {
            flag = true;
          } else {
            page_table[hand]->referenced = 0;
            hand++;
            if (hand >= 64) {
              hand = 0;
            }
          }
        } else {
          hand++;
          if (hand >= 64) {
            hand = 0;
          }
        }
      }

      int ret = hand;
      hand++;
      if (hand >= 64) {
        hand = 0;
      }
      return page_table[ret]->frame_index;

    } else {
      while(page_table[frame_table->mapping[hand]]->referenced == 1) {
        page_table[frame_table->mapping[hand]]->referenced = 0;
        hand++;
        if (hand >= num_frames) {
          hand = 0;
        }

      }
      int ret = hand;
      hand++;

      if (hand >= num_frames) {
        hand = 0;
      }

      return ret;
    }
  }

}
