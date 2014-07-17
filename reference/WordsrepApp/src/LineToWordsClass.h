#ifndef LINETOWORDSCLASS_H_
#define LINETOWORDSCLASS_H_

#include <string>
#include <vector>

class LineToWordsClass {
public:
  LineToWordsClass();
  std::vector<std::string> splitLine(const std::string& textLine);
  void setWordDelimiter(const char& newWordDelimiter);

private:
  void resetInternalListOfWords();

  std::vector<std::string> words;
  std::string newWord;
  char wordDelimiter;
};

#endif /* LINETOWORDSCLASS_H_ */
