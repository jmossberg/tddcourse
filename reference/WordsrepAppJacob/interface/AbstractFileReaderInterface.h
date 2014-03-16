/*
 * AbstractFileReaderInterface.h
 *
 *  Created on: Feb 25, 2014
 *      Author: tdd1
 */

#ifndef ABSTRACTFILEREADERINTERFACE_H_
#define ABSTRACTFILEREADERINTERFACE_H_

#include <string>

class AbstractFileReaderInterface {
public:
  virtual ~AbstractFileReaderInterface() {}
  virtual int openFile(std::string fileName) = 0;
  virtual int closeFile() = 0;
  virtual std::string readLine() = 0;
  virtual bool endOfData() = 0;
};


#endif /* ABSTRACTFILEREADERINTERFACE_H_ */
