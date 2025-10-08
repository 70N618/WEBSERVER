#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

void parse(std::string line);

void readFile(std::string file)
{
  if (file.empty()) return;

  // Store content inside line
  std::string line;

  // File itself
  std::ifstream content(file);
  if (content.is_open())
  {
    while(std::getline(content,line))
    {
      if (line.compare("server") == 0 || line.compare("location") == 0)
        continue;
      parse(line);
    }
  }
  content.close();
}

void parse(std::string line)
{
  static int open_brackets = 0;
  std::string::iterator it_end= --line.end();
  std::cout << "End_char: " << *it_end << std::endl;


  if (line.find_first_of(";") == (0xffffffffffffffff))
  {
    // If semicolon is not present check for open brackets.
    if (*it_end == '{') open_brackets++;
    else if (*it_end == '}') open_brackets--;
  }
}
