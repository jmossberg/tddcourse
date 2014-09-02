#include "ArgumentParserClass.h"

std::string ArgumentParserClass::getSwitchValue(const int& argc, const char* argv[], const std::string& switchName)
{
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
