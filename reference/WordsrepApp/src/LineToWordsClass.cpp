#include "LineToWordsClass.h"

std::vector<std::string> LineToWordsClass::splitLine(std::string textLine) {

  resetInternalListOfWords();

  std::string::iterator currentCharacter;
  for(currentCharacter = textLine.begin(); currentCharacter != textLine.end(); currentCharacter++)
  {
    if(isNotDelimiter(*currentCharacter))
    {
      addCharacterToWord(*currentCharacter);
    }
    else
    {
      addWord();
    }
  }

  addLastWordOnLine();

  return words;
}

void LineToWordsClass::addWord() {
	if(newWord.size() > 0)
	{
	  words.push_back(newWord);
	}
    newWord = "";
}

void LineToWordsClass::addCharacterToWord(char character) {
    newWord.push_back(character);
}

void LineToWordsClass::resetInternalListOfWords() {
	words.resize(0);
	newWord = "";
}

LineToWordsClass::LineToWordsClass() {
	this->wordDelimiter = ' ';
}

bool LineToWordsClass::isNotDelimiter(char character) {
	return this->wordDelimiter != character;
}

void LineToWordsClass::setWordDelimiter(char newWordDelimiter) {
	this->wordDelimiter = newWordDelimiter;
}

void LineToWordsClass::addLastWordOnLine() {
	addWord();
}
