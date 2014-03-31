#ifndef WORDSTOLINECLASS_H_
#define WORDSTOLINECLASS_H_

#include <string>
#include <vector>

class WordsToLineClass {
public:
  std::string concatenateWords(std::vector<std::string> words);

private:
  std::string addWordToLine(std::string line, std::string word);
  std::string removeLastSpaceFromLine(std::string line);

};

#endif /* WORDSTOLINECLASS_H_ */
