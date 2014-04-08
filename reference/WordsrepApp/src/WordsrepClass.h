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
#include "AbstractLineToWordsInterface.h"
#include "AbstractWordsToLineInterface.h"
#include <string>
#include <vector>

class WordsrepClass {
public:
  std::vector<std::string> replaceMatchingWords(
	std::string oldWord, std::string newWord,
	std::vector<std::string> words);
  void processInputFile(int argc, const char* argv[], AbstractFileReaderInterface  * fileReader_p, AbstractFileWriterInterface * fileWriter_p);
  void processInputFile(int argc, const char* argv[], AbstractFileReaderInterface  * fileReader_p, AbstractFileWriterInterface * fileWriter_p,
		                                              AbstractLineToWordsInterface * lineToWords_p, AbstractWordsToLineInterface * wordsToLine_p);

private:
  AbstractLineToWordsInterface * myLineToWords_p;
  AbstractWordsToLineInterface * myWordsToLine_p;
};



#endif /* WORDSREPCLASS_H_ */
