/*
 * main.cpp
 *
 *  Created on: Feb 10, 2014
 *      Author: tdd1
 */

#include "gmock/gmock.h"

int main(int argc, char* argv[]) {
	::testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}


