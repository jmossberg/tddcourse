#include "FileWriterClass.h"

int FileWriterClass::openFile(const std::string& fileName) {
  auto fileNameChar_p = fileName.c_str();
  this->myFile.open(fileNameChar_p);
  return 0;
}

int FileWriterClass::closeFile() {
  this->myFile.close();
  return 0;
}

void FileWriterClass::writeLine(const std::string& line) {
  this->myFile << line;
}

void FileWriterClass::lineFeed() {
	this->myFile << '\n';
}

void FileWriterClass::setEndOfData() {
  this->closeFile();
}
