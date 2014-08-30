#include "WordsToLineClass.h"

std::string WordsToLineClass::concatenateWords(std::vector<std::string> words)
{
  std::vector<std::string>::iterator it;
  std::string line("");

  for(it = words.begin(); it != words.end(); it++)
  {
    line.append(*it);
    line.append(" ");
  }

  if(line.size() > 0)
  {
    line.resize(line.size() - 1);
  }

  return line;
}
