#ifndef LINETOWORDSCLASS_H_
#define LINETOWORDSCLASS_H_

#include <string>
#include <vector>

class LineToWordsClass {
public:
  std::vector<std::string> splitLine(std::string textLine);

private:
  bool isNotSpace(char character);
  void addWord();
  void addCharacterToWord(char character);
  void resetInternalListOfWords();
  void addLastWordOnLine();

  std::vector<std::string> words;
  std::string newWord;
};

#endif /* LINETOWORDSCLASS_H_ */
