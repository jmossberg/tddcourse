#include "gmock/gmock.h"

#include "WordsrepClass.h"
#include "WordsToLineClass.h"
#include "LineToWordsClass.h"

#include "FileReaderMock.h"
#include "FileWriterMock.h"

using ::testing::Exactly;
using ::testing::Return;
using ::testing::InSequence;

class WordsrepClassTest : public ::testing::Test {
public:
	  FileReaderMock myFileReaderMock;
	  FileWriterMock myFileWriterMock;
	  WordsrepClass myWordsrepClass;

	  void setMockExpectations(std::string line1In, std::string line1Out, std::string line2In, std::string line2Out);
};

void WordsrepClassTest::setMockExpectations(std::string line1In, std::string line1Out, std::string line2In, std::string line2Out)
{
	//Set expectations on mock objects
	EXPECT_CALL(myFileReaderMock, openFile("a.txt"))
	.Times(Exactly(1))
	.WillOnce(Return(0));

	EXPECT_CALL(myFileWriterMock, openFile("b.txt"))
	.Times(Exactly(1))
	.WillOnce(Return(0));

	{
	InSequence s;

	EXPECT_CALL(myFileReaderMock, endOfData())
	.Times(Exactly(1))
	.WillOnce(Return(false));

	//Line 1
	EXPECT_CALL(myFileReaderMock, readLine())
	.Times(Exactly(1))
	.WillOnce(Return(line1In));

	EXPECT_CALL(myFileWriterMock, writeLine(line1Out))
	.Times(Exactly(1));

	EXPECT_CALL(myFileReaderMock, endOfData())
	.Times(Exactly(1))
	.WillOnce(Return(false));

	//Line 2
	EXPECT_CALL(myFileReaderMock, readLine())
	.Times(Exactly(1))
	.WillOnce(Return(line2In));

	EXPECT_CALL(myFileWriterMock, writeLine(line2Out))
	.Times(Exactly(1));

	EXPECT_CALL(myFileReaderMock, endOfData())
	.Times(Exactly(1))
	.WillOnce(Return(true));
	}

	EXPECT_CALL(myFileReaderMock, closeFile())
	.Times(Exactly(1))
	.WillOnce(Return(0));

	EXPECT_CALL(myFileWriterMock, closeFile())
	.Times(Exactly(1))
	.WillOnce(Return(0));
}

TEST_F(WordsrepClassTest, APassingTest) {
  ASSERT_TRUE(true);
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
  //Set expectations on mock objects
  std::string line1In("car house street");
  std::string line1Out("house house street");
  std::string line2In("space blue cow");
  std::string line2Out("space blue cow");

  setMockExpectations(line1In, line1Out, line2In, line2Out);

  int argc = 9;
  const char * argv[] = {"wordsrep", "--oldWord", "car", "--newWord", "house", "--inputFile", "a.txt", "--outputFile", "b.txt"};

  //Exercise & Verify
  myWordsrepClass.processInputFile(argc, argv, &myFileReaderMock, &myFileWriterMock);
}

TEST_F(WordsrepClassTest, PassesOnWordDelimiterArgument)
{
	//Set expectations on mock objects
	std::string line1In("car;house;street");
	std::string line1Out("house;house;street");
	std::string line2In("space;blue;cow");
	std::string line2Out("space;blue;cow");

	setMockExpectations(line1In, line1Out, line2In, line2Out);

	int argc = 11;
	const char * argv[] = {"wordsrep", "--oldWord", "car", "--newWord", "house", "--inputFile", "a.txt", "--outputFile", "b.txt", "--wordDelimiter", ";"};

	//Exercise & Verify
	myWordsrepClass.processInputFile(argc, argv, &myFileReaderMock, &myFileWriterMock);
}
