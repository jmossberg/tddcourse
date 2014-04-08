#include "WordsToLineClass.h"

std::string WordsToLineClass::concatenateWords(std::vector<std::string> words)
{
  std::vector<std::string>::iterator it;
  std::string line("");

  for(it = words.begin(); it != words.end(); it++)
  {
    line = addWordToLine(line, *it);
  }

  line = removeLastSpaceFromLine(line);

  return line;
}

std::string WordsToLineClass::addWordToLine(std::string line, std::string word) {
  line.append(word);
  line.append(" ");
  return line;
}

WordsToLineClass::WordsToLineClass() {
	wordDelimiter = ' ';
}

WordsToLineClass::WordsToLineClass(char newWordDelimiter) {
	wordDelimiter = newWordDelimiter;
}

std::string WordsToLineClass::removeLastSpaceFromLine(std::string line) {
  if(line.size() > 0)
  {
    line.resize(line.size() - 1);
  }

  return line;
}
