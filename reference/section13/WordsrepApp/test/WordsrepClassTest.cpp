#include "gmock/gmock.h"
#include "WordsrepClass.h"

TEST(WordsrepClassTest, ReplaceMatchingWordsWithNewWord)
{
  //Setup
  WordsrepClass wordsrepClass;

  std::vector<std::string> words;
  words.push_back("table");
  words.push_back("rocket");
  words.push_back("moon");

  std::string oldWord("table");
  std::string newWord("sun");

  std::vector<std::string> newWords;

  //Exercise
  newWords = wordsrepClass.replaceMatchingWords(oldWord, newWord, words);

  //Verify
  ASSERT_EQ("sun",    newWords[0]);
  ASSERT_EQ("rocket", newWords[1]);
  ASSERT_EQ("moon",   newWords[2]);
}
