#include "WordsrepClass.h"
#include "FileReaderClass.h"
#include "FileWriterClass.h"

int main(int argc, const char * argv[])
{
  FileReaderClass fileReaderClass;
  FileWriterClass fileWriterClass;
  WordsrepClass wordsrepClass;

  wordsrepClass.processInputFile(argc, argv, &fileReaderClass, &fileWriterClass);

  return 0;
}
