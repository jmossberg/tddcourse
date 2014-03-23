#ifndef FILEREADERCLASS_H_
#define FILEREADERCLASS_H_

#include "AbstractFileReaderInterface.h"
#include <iostream>
#include <fstream>

class FileReaderClass : public AbstractFileReaderInterface {
private:
std::ifstream myFile;

public:
  int openFile(std::string fileName);
  int closeFile();
  std::string readLine();
  bool endOfData();

};

#endif /* FILEREADERCLASS_H_ */
