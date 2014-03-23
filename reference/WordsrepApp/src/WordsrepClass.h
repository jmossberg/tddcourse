/*
 * WordsrepClass.h
 *
 *  Created on: Mar 21, 2014
 *      Author: tdd1
 */

#ifndef WORDSREPCLASS_H_
#define WORDSREPCLASS_H_

#include "AbstractFileReaderInterface.h"
#include "AbstractFileWriterInterface.h"
#include <string>
#include <vector>

class WordsrepClass {
public:
  std::vector<std::string> replaceMatchingWords(
	std::string oldWord, std::string newWord,
	std::vector<std::string> words);
  void processInputFile(int argc, const char* argv[], AbstractFileReaderInterface  * fileReader_p, AbstractFileWriterInterface * fileWriter_p);
};



#endif /* WORDSREPCLASS_H_ */
