#ifndef ARGUMENTPARSERCLASS_H_
#define ARGUMENTPARSERCLASS_H_

#include <string>

class ArgumentParserClass {
public:
  std::string getSwitchValue(const int& argc, const char* argv[], const std::string& switchName);
};

#endif /* ARGUMENTPARSERCLASS_H_ */
