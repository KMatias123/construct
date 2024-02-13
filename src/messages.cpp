#include "messages.h"
#include <boost/algorithm/string/join.hpp>
#include <boost/algorithm/string/split.hpp>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

void invalidOperand(std::string* filename, std::vector<std::string> line_split, size_t* line) {
  size_t length = line_split[0].length() + line_split[1].length() + 1;
  std::string* filler = new std::string;

  for (int i = 0; i < length; i++) {
    filler->append(" ");
  }

  std::cerr << "Error: Invalid operand at line " << line << " in file " << filename->c_str() << "\n\n" << line_split[0].c_str() << " " << line_split[1].c_str() <<
    " " << line_split[2].c_str() << " " << line_split[3].c_str() << "\n" << filler->c_str() << " ^\n";

  delete filename;
  delete line;
  exit(EXIT_FAILURE);
}
