#ifndef WORDSTOLINECLASS_H_
#define WORDSTOLINECLASS_H_

#include <string>
#include <vector>

class WordsToLineClass {
public:
  WordsToLineClass();
  std::string concatenateWords(std::vector<std::string>& words);
  void setWordDelimiter(char& newWordDelimiter);

private:
  std::string addWordToLine(std::string& line, std::string& word);
  std::string removeLastDelimiterFromLine(std::string& line);

  char wordDelimiter;
};

#endif /* WORDSTOLINECLASS_H_ */
