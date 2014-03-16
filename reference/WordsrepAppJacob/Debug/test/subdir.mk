################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../test/ArgumentParserClassTest.cpp \
../test/LineToWordsClassTest.cpp \
../test/WordsToLineClassTest.cpp \
../test/WordsrepClassTest.cpp \
../test/main.cpp 

OBJS += \
./test/ArgumentParserClassTest.o \
./test/LineToWordsClassTest.o \
./test/WordsToLineClassTest.o \
./test/WordsrepClassTest.o \
./test/main.o 

CPP_DEPS += \
./test/ArgumentParserClassTest.d \
./test/LineToWordsClassTest.d \
./test/WordsToLineClassTest.d \
./test/WordsrepClassTest.d \
./test/main.d 


# Each subdirectory must supply rules for building sources it contributes
test/%.o: ../test/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/tdd1/workspace_jacobmossberg3/WordsrepAppJacob/external" -I"/home/tdd1/workspace_jacobmossberg3/WordsrepAppJacob/interface" -I"/home/tdd1/workspace_jacobmossberg3/WordsrepAppJacob/mock" -I"/home/tdd1/workspace_jacobmossberg3/WordsrepAppJacob/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


