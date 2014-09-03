#ifndef WORDSREPCLASS_H_
#define WORDSREPCLASS_H_

#include <string>
#include <vector>

class WordsrepClass {
public:
	  std::vector<std::string> replaceMatchingWords(
		std::string& oldWord, std::string& newWord,
		std::vector<std::string>& words);
};


#endif /* WORDSREPCLASS_H_ */
