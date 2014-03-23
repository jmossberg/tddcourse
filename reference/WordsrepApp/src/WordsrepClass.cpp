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

void WordsrepClass::processInputFile(int argc, const char* argv[],
AbstractFileReaderInterface* fileReader_p,
AbstractFileWriterInterface* fileWriter_p) {

  ArgumentParserClass argumentParserClass;
  WordsToLineClass wordsToLineClass;
  LineToWordsClass lineToWordsClass;

  std::string oldWord = argumentParserClass.getSwitchValue(argc, argv, "--oldWord");
  std::string newWord = argumentParserClass.getSwitchValue(argc, argv, "--newWord");
  std::string inputFile = argumentParserClass.getSwitchValue(argc, argv, "--inputFile");
  std::string outputFile = argumentParserClass.getSwitchValue(argc, argv, "--outputFile");

  fileReader_p->openFile(inputFile);
  fileWriter_p->openFile(outputFile);

  while(false == fileReader_p->endOfData())
  {
    std::string tempLine = fileReader_p->readLine();

    std::vector<std::string> words = lineToWordsClass.splitLine(tempLine);
    std::vector<std::string> newWords = this->replaceMatchingWords(oldWord, newWord, words);
    tempLine = wordsToLineClass.concatenateWords(newWords);

    fileWriter_p->writeLine(tempLine);
  }

  fileWriter_p->closeFile();
  fileReader_p->closeFile();

}
