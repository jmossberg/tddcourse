/*
 * ArgumentParserClass.h
 *
 *  Created on: Feb 15, 2014
 *      Author: tdd1
 */

#ifndef ARGUMENTPARSERCLASS_H_
#define ARGUMENTPARSERCLASS_H_

#include <string>

class ArgumentParserClass {

public:
	std::string getSwitchValue(int argc, const char * argv[], std::string switchName);
};


#endif /* ARGUMENTPARSERCLASS_H_ */