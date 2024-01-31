#include "messages.h"
#include <boost/algorithm/string/join.hpp>
#include <boost/algorithm/string/split.hpp>
#include <cstddef>
#include <cstdlib>
#include <string>

#define COLOR_RED "\033[0;31m"
#define COLOR_RESET "\033[0;0m"

// TODO: pass down filename in deconstruct.cpp and print it here.
void invalidOperand(std::string filename, std::vector<std::string> line_split, size_t line) {


  size_t length = line_split[0].length() + line_split[1].length() + 1;
  std::string* filler = new std::string;
  
  for (int i = 0; i < length; i++) {
    filler->append(" ");
  }
  

  fprintf(stderr, "%sError: %sInvalid operand at line %i\n\n%s %s %s%s %s%s\n%s %s^%s\n",
      COLOR_RED, COLOR_RESET, line, line_split[0].c_str(), line_split[1].c_str(), COLOR_RED, line_split[2].c_str(), COLOR_RESET, line_split[3].c_str(),
      filler->c_str(), COLOR_RED, COLOR_RESET);

  exit(EXIT_FAILURE);
}
