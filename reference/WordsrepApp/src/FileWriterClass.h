#ifndef FILEWRITERCLASS_H_
#define FILEWRITERCLASS_H_

#include "AbstractFileWriterInterface.h"
#include <iostream>
#include <fstream>

class FileWriterClass : public AbstractFileWriterInterface {
private:
  std::ofstream myFile;

  int closeFile();

public:
  int openFile(std::string fileName);
  void writeLine(std::string line);
  void setEndOfData();

};

#endif /* FILEWRITERCLASS_H_ */
