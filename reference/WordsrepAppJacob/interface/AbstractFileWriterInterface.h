/*
 * AbstractFileWriterInterface.h
 *
 *  Created on: Feb 25, 2014
 *      Author: tdd1
 */

#ifndef ABSTRACTFILEWRITERINTERFACE_H_
#define ABSTRACTFILEWRITERINTERFACE_H_

#include <string>

class AbstractFileWriterInterface {
public:
  virtual ~AbstractFileWriterInterface() {}
  virtual int openFile(std::string fileName) = 0;
  virtual int closeFile() = 0;
  virtual void writeLine(std::string newLine) = 0;
  virtual void setEndOfData() = 0;
};


#endif /* ABSTRACTFILEWRITERINTERFACE_H_ */
