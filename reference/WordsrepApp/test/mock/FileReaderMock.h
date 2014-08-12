#ifndef FILEREADERMOCK_H_
#define FILEREADERMOCK_H_

#include "gmock/gmock.h"
#include "AbstractFileReaderInterface.h"

class FileReaderMock : public AbstractFileReaderInterface {
public:
  MOCK_METHOD1(openFile, int(const std::string& fileName));
  MOCK_METHOD0(closeFile, int());
  MOCK_METHOD0(readLine, std::string());
  MOCK_METHOD0(endOfData, bool());
};

#endif /* FILEREADERMOCK_H_ */
