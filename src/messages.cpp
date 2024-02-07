#include "messages.h"
#include <boost/algorithm/string/join.hpp>
#include <boost/algorithm/string/split.hpp>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <format>

#define COLOR_RED "\033[0;31m"
#define COLOR_RESET "\033[0;0m"

// TODO: pass down filename in deconstruct.cpp and print it here.
// TODO: add startup arg/check if color_prompt = yes
void invalidOperand(std::string filename, std::vector<std::string> line_split, size_t line) {


  size_t length = line_split[0].length() + line_split[1].length() + 1;
  std::string* filler = new std::string;
  
  for (int i = 0; i < length; i++) {
    filler->append(" ");
  }

  std::string formatted = std::format("Error: Invalid operand at line {} in file {}\n\n{} {} {} {}\n{} ^\n",
      line, filename.c_str(), line_split[0].c_str(), line_split[1].c_str(),
      line_split[2].c_str(), line_split[3].c_str(), filler->c_str());
  
  std::cerr << formatted;

  exit(EXIT_FAILURE);
}
