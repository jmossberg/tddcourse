#ifndef LINETOWORDSCLASS_H_
#define LINETOWORDSCLASS_H_

#include <string>
#include <vector>

class LineToWordsClass {
public:
  LineToWordsClass();
  std::vector<std::string> splitLine(std::string textLine);
  void setWordDelimiter(char newWordDelimiter);

private:
  bool isNotDelimiter(char character);
  void addWord();
  void addCharacterToWord(char character);
  void resetInternalListOfWords();
  void addLastWordOnLine();

  std::vector<std::string> words;
  std::string newWord;
  char wordDelimiter;
};

#endif /* LINETOWORDSCLASS_H_ */
