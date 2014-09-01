#include "gmock/gmock.h"
#include "ArgumentParserClass.h"

TEST(ArgumentParserClassTest, ValueOfArgumentSwitchCanBeRetrieved) {

  //Setup
  int argc { 3 };
  const char * argv1[] = {"wordsrep", "--oldWord", "car"};
  const char * argv2[] = {"wordsrep", "--oldWord", "space"};
  ArgumentParserClass argumentParserClass;

  //Exercise
  auto argumentSwitchValue1 = argumentParserClass.getSwitchValue(argc, argv1, "--oldWord");
  auto argumentSwitchValue2 = argumentParserClass.getSwitchValue(argc, argv2, "--oldWord");

  //Verify
  ASSERT_EQ("car", argumentSwitchValue1);
  ASSERT_EQ("space", argumentSwitchValue2);
}
