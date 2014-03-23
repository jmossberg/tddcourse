#include "LineToWordsClass.h"

std::vector<std::string> LineToWordsClass::splitLine(std::string textLine) {

  resetInternalListOfWords();

  std::string::iterator currentCharacter;
  for(currentCharacter = textLine.begin(); currentCharacter != textLine.end(); currentCharacter++)
  {
    if(isNotSpace(*currentCharacter))
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

bool LineToWordsClass::isNotSpace(char character) {
	return  ' ' != character;
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

void LineToWordsClass::addLastWordOnLine() {
	addWord();
}
