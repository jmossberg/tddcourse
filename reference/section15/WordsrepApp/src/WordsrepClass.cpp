#include "WordsrepClass.h"
#include "ArgumentParserClass.h"
#include "LineToWordsClass.h"
#include "WordsToLineClass.h"

std::vector<std::string> WordsrepClass::replaceMatchingWords(
std::string oldWord, std::string newWord,
std::vector<std::string> words) {

  std::vector<std::string>::iterator it;
  std::vector<std::string> newWords;

  for(it = words.begin(); it != words.end(); it++)
  {
    if((*it) == oldWord)
    {
      newWords.push_back(newWord);
    }
    else
    {
      newWords.push_back(*it);
    }
  }

  return newWords;
}

void WordsrepClass::processInputFile(int& argc, const char* argv[],
		AbstractFileReaderInterface& fileReader,
		AbstractFileWriterInterface& fileWriter) {

  ArgumentParserClass argumentParserClass;
  LineToWordsClass lineToWordsClass;
  WordsToLineClass wordsToLineClass;

  auto oldWord = argumentParserClass.getSwitchValue(argc, argv, "--oldWord");
  auto newWord = argumentParserClass.getSwitchValue(argc, argv, "--newWord");
  auto inputFile = argumentParserClass.getSwitchValue(argc, argv, "--inputFile");
  auto outputFile = argumentParserClass.getSwitchValue(argc, argv, "--outputFile");

  fileReader.openFile(inputFile);
  fileWriter.openFile(outputFile);

  isFirstLine = true;
  while(false == fileReader.endOfData())
  {
    auto tempLine = fileReader.readLine();

    auto words = lineToWordsClass.splitLine(tempLine);
    auto newWords = this->replaceMatchingWords(oldWord, newWord, words);
    tempLine = wordsToLineClass.concatenateWords(newWords);

    insertLineFeed(fileWriter);
    fileWriter.writeLine(tempLine);
  }

  fileWriter.closeFile();
  fileReader.closeFile();

}

void WordsrepClass::insertLineFeed(AbstractFileWriterInterface& fileWriter) {
  if(!isFirstLine) {
    fileWriter.lineFeed();
  }
  isFirstLine  = false;
}
