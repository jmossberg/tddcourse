/*
 * LineToWordsMock.h
 *
 *  Created on: Apr 8, 2014
 *      Author: tdd1
 */

#ifndef LINETOWORDSMOCK_H_
#define LINETOWORDSMOCK_H_

#include "gmock/gmock.h"
#include "AbstractLineToWordsInterface.h"

class LineToWordsMock : public AbstractLineToWordsInterface {
public:
  MOCK_METHOD1(splitLine, std::vector<std::string>(std::string textLine));
  MOCK_METHOD1(setWordDelimiter, void(char newWordDelimiter));
};


#endif /* LINETOWORDSMOCK_H_ */
