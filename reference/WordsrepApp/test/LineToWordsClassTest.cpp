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
