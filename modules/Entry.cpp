#include "Entry.h"

Entry::Entry(int ind) {
  present = 0;
  modified = 0;
  referenced = 0;
  paged_out = 0;
  index = ind;
}

void Entry::reset() {
  present = 0;
  modified = 0;
  referenced = 0;
  paged_out = 0;
}

void Entry::changeFrameIndex(int index) {
  frame_index = index;
}
