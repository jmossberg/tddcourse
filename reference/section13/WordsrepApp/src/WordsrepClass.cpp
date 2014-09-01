#include "WordsrepClass.h"

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
