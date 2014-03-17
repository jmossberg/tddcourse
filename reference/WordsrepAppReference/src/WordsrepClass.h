/*
 * WordsrepClass.h
 *
 *  Created on: Feb 24, 2014
 *      Author: tdd1
 */

#ifndef WORDSREPCLASS_H_
#define WORDSREPCLASS_H_

#include <string>
#include <vector>
#include "AbstractFileReaderInterface.h"
#include "AbstractFileWriterInterface.h"

class WordsrepClass
{
public:
	std::vector<std::string> replaceMatchingWords(
	  std::string oldWord, std::string newWord,
	  std::vector<std::string> words);
	void processInputFile(int argc, const char* argv[], AbstractFileReaderInterface  * fileReader_p, AbstractFileWriterInterface * fileWriter_p);
};


#endif /* WORDSREPCLASS_H_ */
