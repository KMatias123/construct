#include "./messages.h"
#include "./construct_types.h"
#include <boost/algorithm/string/join.hpp>
#include <boost/algorithm/string/split.hpp>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>

void invalidOperand(linemetadata* metadata, std::vector<std::string> line_split, size_t operand_index) {
  size_t length = 0;

  if (operand_index < 0) {
    throw std::invalid_argument("operand_index is less than 0");

  } else if (operand_index > 0) {
    length++;
  }

  for (int i = 0; i < operand_index; i++) {
    length += line_split[i].length();
  }

  std::string filler = std::string();

  for (int i = 0; i < length; i++) {
    filler.append(" ");
  }

  std::cerr << "Error: Invalid operand at line " << metadata->line <<
    " in file " << metadata->filename.c_str() << "\n\n" << line_split[0].c_str() << " " << line_split[1].c_str() <<
    " " << line_split[2].c_str() << " " << line_split[3].c_str() << "\n" << filler.c_str() << " ^\n";

  delete metadata;
  exit(EXIT_FAILURE);
}
