#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

#include "constants.h"
#include "FileReader.h"
#include "Instruction.h"

std::string END_OF_FILE = "end of file";

FileReader::FileReader(std::ifstream& fileOne, std::ifstream& fileTwo)
: input_file(fileOne), random_file(fileTwo) {
}

std::string FileReader::getNewLine() {
  std::string line;
  std::getline(input_file, line);

  if (input_file.eof()) {
    return END_FILE;
  } else {
    return line;
  }

}

void FileReader::resetRandom() {
  random_file.clear();
  random_file.seekg(0, std::ios::beg);
  std::string line;
  getline(random_file, line);
}

struct Instruction FileReader::getNextInstruction() {
  std::string line = getNewLine();

  if (line == END_FILE) {
    throw END_OF_FILE;
  }

  if (line[0] == '#') {
    return getNextInstruction();
  }
  std::istringstream token_stream(line);
  int rw, virtual_page;
  token_stream>>rw>>virtual_page;

  Instruction instr = createInstruction(rw, virtual_page, line);
  return instr;
}

int FileReader::getRandom(int burst) {
  std::string line;
  std::getline(random_file, line);

  if (random_file.eof()) {
    resetRandom();
    std::getline(random_file, line);
  }

  int token;
  std::istringstream token_stream(line);
  token_stream>>token;
  return token % burst;
}
