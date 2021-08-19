#include "NRUAlgo.h"
#include "../modules/FrameTable.h"
#include "../modules/FileReader.h"
#include "../modules/Entry.h"
#include <iostream>

NRUAlgo::NRUAlgo(FileReader &reader) {
  count = 0;
  fileReader = &reader;
}

int NRUAlgo::getFrame(int index, Entry* page_table[], FrameTable* frame_table) {
  int frame = frame_table->getFreeFrame();

  if (frame != -1) {
    return frame;
  } else {
    count++;
    count = count % 10;
    Entry* entry;

    for(int i = 0; i < 4; i++) {
      classes[i].clear();
    }

    int num_frames = frame_table->num_frames;

    for(int i = 0; i < 64; i++) {
      if (!page_table[i]->present) {
        continue;
      } else {
        entry = page_table[i];

        int class_index = entry->referenced * 2 + entry->modified * 1;
        classes[class_index].push_back(entry->frame_index);
      }
    }

    int frame;

    for(int i = 0; i < 4; i++) {
      if (classes[i].size() > 0) {
        int random = fileReader->getRandom(classes[i].size());
        frame = classes[i][random];
        break;
      }
    }

    if (count == 0) {
      for(int i = 0; i < classes[2].size(); i++) {
        page_table[frame_table->mapping[classes[2][i]]]->referenced = 0;
      }

      for(int i = 0; i < classes[3].size(); i++) {
        page_table[frame_table->mapping[classes[3][i]]]->referenced = 0;
      }
    }
    return frame;
  }
}
