#include "WordsrepClass.h"

std::vector<std::string> WordsrepClass::replaceMatchingWords(
std::string& oldWord, std::string& newWord,
std::vector<std::string>& words) {

  std::vector<std::string> newWords;

  for(auto& word: words)
  {
    if(word == oldWord)
    {
      newWords.push_back(newWord);
    }
    else
    {
      newWords.push_back(word);
    }
  }

  return newWords;
}
