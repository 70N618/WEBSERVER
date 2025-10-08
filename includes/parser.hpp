#ifndef PARSER_HPP
#define PARSER_HPP
#include <cstdint>
#include <string>
#include <vector>

struct Server
{
  std::vector <std::string> server_names;
  std::vector <std::string> uploads_dir;
  std::vector <std::string> indexes;
  std::vector <std::string> root;

  std::vector <std::string> err_pages;

  uint32_t client_max_body_size;
  bool auto_index;
};

void readFile(std::string file);
void parse(std::string line);

#endif


