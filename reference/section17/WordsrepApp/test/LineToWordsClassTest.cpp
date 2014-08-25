#include "gmock/gmock.h"
#include "LineToWordsClass.h"

TEST(LineToWordsClassTest, CanSplitLineWithTwoWords)
{
  //Setup
  LineToWordsClass lineToWordsClass;
  std::vector<std::string> words;

  //Exercise
  words = lineToWordsClass.splitLine("street sky");

  //Verify
  ASSERT_EQ(2, words.size());
  ASSERT_EQ("street", words[0]);
  ASSERT_EQ("sky", words[1]);
}

TEST(LineToWordsClassTest, CanSplitLineUsingDynamicWordDelimiter)
{
	//Setup
	char wordDelimiter = '#';
	LineToWordsClass lineToWordsClass;
	std::vector<std::string> words;

	//Exercise
	lineToWordsClass.setWordDelimiter(wordDelimiter);
	words = lineToWordsClass.splitLine("blue#red#green");

	//Verify
	ASSERT_EQ(3, words.size());
	ASSERT_EQ("blue", words[0]);
	ASSERT_EQ("red", words[1]);
	ASSERT_EQ("green", words[2]);
}
