/*
 * WordsToLineMock.h
 *
 *  Created on: Apr 8, 2014
 *      Author: tdd1
 */

#ifndef WORDSTOLINEMOCK_H_
#define WORDSTOLINEMOCK_H_

#include "gmock/gmock.h"
#include "AbstractWordsToLineInterface.h"

class WordsToLineMock : public AbstractWordsToLineInterface {
public:
  MOCK_METHOD1(concatenateWords, std::string(std::vector<std::string> words));
  MOCK_METHOD1(setWordDelimiter, void(char newWordDelimiter));
};


#endif /* WORDSTOLINEMOCK_H_ */
