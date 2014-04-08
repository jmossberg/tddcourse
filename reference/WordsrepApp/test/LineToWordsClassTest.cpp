#include "gmock/gmock.h"
#include "LineToWordsClass.h"

class LineToWordsClassTest : public ::testing::Test
{

};

TEST_F(LineToWordsClassTest, CanSplitLineWithTwoWords)
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

TEST_F(LineToWordsClassTest, CanSplitLineUsingDynamicWordDelimiter)
{
	//Setup
	char wordDelimiter = '#';
	LineToWordsClass lineToWordsClass(wordDelimiter);
	std::vector<std::string> words;

	//Exercise
	words = lineToWordsClass.splitLine("blue#red#green");

	//Verify
	ASSERT_EQ(3, words.size());
	ASSERT_EQ("blue", words[0]);
	ASSERT_EQ("red", words[1]);
	ASSERT_EQ("green", words[2]);
}
