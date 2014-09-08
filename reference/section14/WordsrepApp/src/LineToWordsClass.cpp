#include "LineToWordsClass.h"
#include <sstream>

std::vector<std::string> LineToWordsClass::splitLine(
		const std::string& textLine) {

  const int MAX_WORD_LENGTH { 20 };
  char tempbuff[50];

  std::vector<std::string> words;

  //The stringstream class is good at parsing text. We will use
  //it to split up the line into words.
  std::stringstream ss;

  //Copy string to stringstream
  ss << textLine;

  //Loop through stringstream looking for space delimiters
  //Extract characters from ss into tempbuff until either
  //the next character equals space or we have reached
  //MAX_WORD_LENGTH number of characters
  //The while loop will finish when there are no more words
  //found by getline
  while(ss.getline(tempbuff, MAX_WORD_LENGTH, ' '))
  {
  	words.push_back(tempbuff);
  }

  return words;
}
