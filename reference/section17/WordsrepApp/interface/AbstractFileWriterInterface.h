#ifndef ABSTRACTFILEWRITERINTERFACE_H_
#define ABSTRACTFILEWRITERINTERFACE_H_

#include <string>

class AbstractFileWriterInterface {
public:
  virtual ~AbstractFileWriterInterface() {}
  virtual int openFile(const std::string& fileName) = 0;
  virtual int closeFile() = 0;
  virtual void writeLine(const std::string& newLine) = 0;
  virtual void lineFeed() = 0;
  virtual void setEndOfData() = 0;
};

#endif /* ABSTRACTFILEWRITERINTERFACE_H_ */
