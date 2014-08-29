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

  char wordDelimiter;
};

#endif /* LINETOWORDSCLASS_H_ */
