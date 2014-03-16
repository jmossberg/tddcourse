#include "ArgumentParserClass.h"

std::string ArgumentParserClass::getSwitchValue(int argc, const char* argv[],
		std::string switchName) {

	int i;

	for(i = 0; i < argc; i++)
	{
		if(0 == switchName.compare(argv[i]))
		{
			return argv[i + 1];
		}

	}

	return "";
}
