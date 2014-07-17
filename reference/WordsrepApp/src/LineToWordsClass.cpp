#include "LineToWordsClass.h"
#include <sstream>

void LineToWordsClass::resetInternalListOfWords() {
	words.resize(0);
	newWord = "";
}

LineToWordsClass::LineToWordsClass() {
	this->wordDelimiter = ' ';
}

void LineToWordsClass::setWordDelimiter(const char& newWordDelimiter) {
	this->wordDelimiter = newWordDelimiter;
}

std::vector<std::string> LineToWordsClass::splitLine(
		const std::string& textLine) {

	const int MAX_WORD_LENGTH { 20 };
	char tempbuff[50];

	resetInternalListOfWords();

	std::stringstream ss;

	//Copy string to stringstream
	ss << textLine;

	//Loop through stringstream looking for delimiter character
	while(ss.getline(tempbuff, MAX_WORD_LENGTH, wordDelimiter))
	{
		words.push_back(tempbuff);
	}

	return words;
}
