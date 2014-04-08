/*
 * AbstractLineToWordsInterface.h
 *
 *  Created on: Apr 8, 2014
 *      Author: tdd1
 */

#ifndef ABSTRACTLINETOWORDSINTERFACE_H_
#define ABSTRACTLINETOWORDSINTERFACE_H_

#include <string>
#include <vector>

class AbstractLineToWordsInterface {
public:
  virtual ~AbstractLineToWordsInterface() {}
  virtual std::vector<std::string> splitLine(std::string textLine) = 0;
  virtual void setWordDelimiter(char newWordDelimiter) = 0;
};


#endif /* ABSTRACTLINETOWORDSINTERFACE_H_ */
