#ifndef Args_h
#define Args_h

#include <string>

struct Options {
  bool print_output;
  bool print_pagetable_end;
  bool print_pagetable_always;
  bool print_frametable_end;
  bool print_frametable_always;
  bool print_summary;
  bool print_aging;
};

struct Args {
  std::string algo;
  Options options;
  int num_frames;
};
Options getArgsOptions(std::string options);
#endif
