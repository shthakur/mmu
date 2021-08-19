#include <ctype.h>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <string>
#include <iostream>
#include "modules/Simulator.h"
#include "modules/Args.h"


int main (int argc, char *argv[]) {
  char *o_value;
  char *a_value;
  char *f_value;
  int index;
  int c;

  opterr = 0;

  // Parse args
  while ((c = getopt(argc, argv, "a:f:o:")) != -1)
    switch (c) {
      case 'a':
        a_value = optarg;
        break;
      case 'f':
        f_value = optarg;
        break;
      case 'o':
        o_value = optarg;
        break;
      case '?':
        if (optopt == 'a' || optopt == 'o' || optopt == 'f') {
          std::fprintf(stderr, "Option -%c requires an argument.\n", optopt);
        } else if (std::isprint(optopt)) {
          std::fprintf(stderr, "Unknown option `-%c'.\n", optopt);
        } else {
          std::fprintf(stderr, "Unknown option character `\\x%x'.\n",
                   optopt);
        }
        return 1;
      default:
        std::abort ();
  }

  char *input_file_name_arg = argv[optind];
  char *random_file_name_arg = argv[optind + 1];
  std::string algo_string(a_value), input_file_name(input_file_name_arg),
  random_file_name(random_file_name_arg), options(o_value);
  int num_frames = atoi(f_value);

  Args args = {};
  args.algo = algo_string;
  args.options = getArgsOptions(options);
  args.num_frames = num_frames;

  Simulator simulator(input_file_name, random_file_name, args);
  simulator.run();
  return 0;
}
