#include "FileReaderClass.h"

int FileReaderClass::openFile(const std::string& fileName) {
  auto fileNameChar_p = fileName.c_str();
  this->myFile.open(fileNameChar_p, std::fstream::in);
  return 0;
}

std::string FileReaderClass::readLine() {
  const int MAXLENGTH = 500;
  char rad[MAXLENGTH+1];
  this->myFile.getline(rad, MAXLENGTH);
  return std::string(rad);
}

bool FileReaderClass::endOfData() {
  return this->myFile.eof();
}

int FileReaderClass::closeFile()
{
  this->myFile.close();
  return 0;
}
