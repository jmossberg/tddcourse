#include "gmock/gmock.h"
#include "WordsrepClass.h"
#include "FileReaderMock.h"
#include "FileWriterMock.h"

using ::testing::Exactly;
using ::testing::Return;
using ::testing::InSequence;

class WordsrepClassTest : public ::testing::Test {

};

TEST_F(WordsrepClassTest, APassingTest) {
  ASSERT_TRUE(false);
}

TEST_F(WordsrepClassTest, ReplaceMatchingWordsWithNewWord)
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

TEST_F(WordsrepClassTest, InteractsCorrectlyWithFileInterfaces)
{
  //Setup
  FileReaderMock fileReaderMock;
  FileWriterMock fileWriterMock;
  WordsrepClass wordsrepClass;

  //Set expectations on mock objects
  EXPECT_CALL(fileReaderMock, openFile("a.txt"))
  .Times(Exactly(1))
  .WillOnce(Return(0));

  EXPECT_CALL(fileWriterMock, openFile("b.txt"))
  .Times(Exactly(1))
  .WillOnce(Return(0));

  {
    InSequence s;

    EXPECT_CALL(fileReaderMock, endOfData())
    .Times(Exactly(1))
    .WillOnce(Return(false));

    //Line 1
    EXPECT_CALL(fileReaderMock, readLine())
    .Times(Exactly(1))
    .WillOnce(Return("car house street"));

    EXPECT_CALL(fileWriterMock, writeLine("house house street"))
    .Times(Exactly(1));

    EXPECT_CALL(fileReaderMock, endOfData())
    .Times(Exactly(1))
    .WillOnce(Return(false));

    //Line 2
    EXPECT_CALL(fileReaderMock, readLine())
    .Times(Exactly(1))
    .WillOnce(Return("space blue cow"));

    EXPECT_CALL(fileWriterMock, writeLine("space blue cow"))
    .Times(Exactly(1));

    EXPECT_CALL(fileReaderMock, endOfData())
    .Times(Exactly(1))
    .WillOnce(Return(true));
  }

  EXPECT_CALL(fileReaderMock, closeFile())
  .Times(Exactly(1))
  .WillOnce(Return(0));

  EXPECT_CALL(fileWriterMock, closeFile())
  .Times(Exactly(1))
  .WillOnce(Return(0));

  int argc = 9;
  const char * argv[] = {"wordsrep", "--oldWord", "car", "--newWord", "house", "--inputFile", "a.txt", "--outputFile", "b.txt"};

  //Exercise & Verify
  wordsrepClass.processInputFile(argc, argv, &fileReaderMock, &fileWriterMock);
}
