#include "WordsToLineClass.h"

std::string WordsToLineClass::concatenateWords(std::vector<std::string>& words)
{
  std::string line("");

  for(auto& word: words)
  {
    line = addWordToLine(line, word);
  }

  line = removeLastDelimiterFromLine(line);

  return line;
}

std::string WordsToLineClass::addWordToLine(std::string& line, std::string& word) {
  line.append(word);
  line.push_back(wordDelimiter);
  return line;
}

WordsToLineClass::WordsToLineClass() {
	wordDelimiter = ' ';
}

void WordsToLineClass::setWordDelimiter(char& newWordDelimiter) {
	wordDelimiter = newWordDelimiter;
}

std::string WordsToLineClass::removeLastDelimiterFromLine(std::string& line) {
  if(line.size() > 0)
  {
    line.resize(line.size() - 1);
  }

  return line;
}
