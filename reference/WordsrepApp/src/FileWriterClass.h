#ifndef FILEWRITERCLASS_H_
#define FILEWRITERCLASS_H_

#include "AbstractFileWriterInterface.h"
#include <iostream>
#include <fstream>

class FileWriterClass : public AbstractFileWriterInterface {
private:
  std::ofstream myFile;

public:
  int openFile(const std::string& fileName);
  int closeFile();
  void writeLine(const std::string& line);
  void lineFeed();
  void setEndOfData();

};

#endif /* FILEWRITERCLASS_H_ */
