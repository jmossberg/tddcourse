#include "gmock/gmock.h"
#include "WordsToLineClass.h"

TEST(WordsToLineClassTest, ConcatenateThreeWordsIntoLine)
{
  //Setup
  WordsToLineClass wordsToLineClass;

  std::vector<std::string> words;
  words.push_back("table");
  words.push_back("rocket");
  words.push_back("moon");

  std::string line;

  //Exercise
  line = wordsToLineClass.concatenateWords(words);

  //Verify
  ASSERT_EQ("table rocket moon", line);
}

TEST(WordsToLineClassTest, ConcatenateWordsUsingDynamicWordDelimiter)
{
	  //Setup
	  char wordDelimiter = ';';
	  WordsToLineClass wordsToLineClass;

	  std::vector<std::string> words;
	  words.push_back("table");
	  words.push_back("rocket");
	  words.push_back("moon");

	  std::string line;

	  //Exercise
	  wordsToLineClass.setWordDelimiter(wordDelimiter);
	  line = wordsToLineClass.concatenateWords(words);

	  //Verify
	  ASSERT_EQ("table;rocket;moon", line);
}
