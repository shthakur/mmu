#ifndef FileReader_h
#define FileReader_h

#include <fstream>
#include <string>
#include "Instruction.h"

class FileReader {
  std::ifstream& input_file;
  std::ifstream& random_file;
  std::string getNewLine();
public:
  FileReader(std::ifstream&, std::ifstream&);
  void resetRandom();
  Instruction getNextInstruction();
  int getRandom(int);
};

#endif
