#include "Instruction.h"


struct Instruction createInstruction(int rw, int virtual_page, std::string line) {
  struct Instruction instr = {};
  instr.read_or_write = rw;
  instr.virtual_page = virtual_page;
  instr.line = line;
  return instr;
}
