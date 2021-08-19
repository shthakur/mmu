#ifndef Instruction_h
#define Instruction_h

#include <string>

struct Instruction {
  int read_or_write;
  int virtual_page;
  std::string line;
};

Instruction createInstruction(int, int, std::string);
#endif
