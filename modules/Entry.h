#ifndef Entry_h
#define Entry_h

class Entry {
public:
  int index;
  bool present;
  bool modified;
  bool referenced;
  bool paged_out;
  int frame_index;
  Entry(int);
  void reset();
  void changeFrameIndex(int index);
};

#endif
