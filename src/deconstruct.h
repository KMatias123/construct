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

con_macro* parse_macro(linemetadata* metadata);
con_if* parse_if(linemetadata* metadata);
con_while* parse_while(linemetadata* metadata);
con_section* parse_section(linemetadata* metadata);
con_tag* parse_tag(linemetadata* metadata);
con_cmd* parse_cmd(linemetadata* metadata);
con_function* parse_function(linemetadata* metadata);
con_funcall* parse_funcall(linemetadata* metadata);
void parse_line(std::string line, con_token new_token, std::string path);
std::vector<con_token*> parse_construct(std::string code, std::string path);
