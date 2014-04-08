/*
 * AbstractWordsToLineInterface.h
 *
 *  Created on: Apr 8, 2014
 *      Author: tdd1
 */

#ifndef ABSTRACTWORDSTOLINEINTERFACE_H_
#define ABSTRACTWORDSTOLINEINTERFACE_H_

#include <string>
#include <vector>

class AbstractWordsToLineInterface {
public:
  virtual ~AbstractWordsToLineInterface() {}
  virtual std::string concatenateWords(std::vector<std::string> words) = 0;
  virtual void setWordDelimiter(char newWordDelimiter) = 0;
};


#endif /* ABSTRACTWORDSTOLINEINTERFACE_H_ */
