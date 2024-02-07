#include "construct_debug.h"
#include "construct_types.h"
#include<boost/algorithm/string/classification.hpp>
#include<boost/algorithm/string/split.hpp>
#include<boost/algorithm/string.hpp>
#include<fstream>
#include<sstream>
#include<iostream>
#include<stack>
#include <string>

int get_line_indentation(std::string line);
CON_TOKENTYPE get_token_type(std::string line);
CON_COMPARISON str_to_comparison(std::string comp);

std::vector<con_token*> delinearize_tokens(std::vector<con_token*> tokens);

con_macro* parse_macro(std::string line);
con_if* parse_if(linemetadata* metadata);
con_while* parse_while(std::string line_st, int line);
con_section* parse_section(std::string line);
con_tag* parse_tag(std::string line);
con_cmd* parse_cmd(std::string line);
con_function* parse_function(std::string line);
con_funcall* parse_funcall(std::string line);
void parse_line(std::string line, con_token new_token, std::string path);
std::vector<con_token*> parse_construct(std::string code, std::string path);
