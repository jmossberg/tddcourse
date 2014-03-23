#ifndef FILEWRITERMOCK_H_
#define FILEWRITERMOCK_H_

#include "gmock/gmock.h"
#include "AbstractFileWriterInterface.h"

class FileWriterMock : public AbstractFileWriterInterface {
public:
  MOCK_METHOD1(openFile, int(std::string fileName));
  MOCK_METHOD0(closeFile, int());
  MOCK_METHOD1(writeLine, void(std::string newLine));
  MOCK_METHOD0(setEndOfData, void());
};

#endif /* FILEWRITERMOCK_H_ */
