#include "Args.h"

Options getArgsOptions(std::string options) {
  Options opt;
  for(int i = 0; i < options.length(); i++) {
    switch(options[i]) {
      case 'O':
        opt.print_output = true;
        break;
      case 'P':
        opt.print_pagetable_end = true;
        break;
      case 'F':
        opt.print_frametable_end = true;
        break;
      case 'S':
        opt.print_summary = true;
        break;
      case 'p':
        opt.print_pagetable_always = true;
        break;
      case 'f':
        opt.print_frametable_always = true;
        break;
      case 'a':
        opt.print_aging = true;
        break;
    }
  }

  return opt;
}
