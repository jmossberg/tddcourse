#include "LineToWordsClass.h"

std::vector<std::string> LineToWordsClass::splitLine(std::string textLine) {

	std::vector<std::string> words;
	std::string word("");
	unsigned int i;

	for(i = 0; i < textLine.size(); i++)
	{
		if(textLine[i] == ' ')
		{
			words.push_back(word);
			word = "";
		}
		else
		{
			word.push_back(textLine[i]);
		}
	}

	if(word.size() > 0)
	{
		words.push_back(word);
	}

	return words;
}





