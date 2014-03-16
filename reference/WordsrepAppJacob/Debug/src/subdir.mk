################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ArgumentParserClass.cpp \
../src/FileReaderClass.cpp \
../src/FileWriterClass.cpp \
../src/LineToWordsClass.cpp \
../src/WordsToLineClass.cpp \
../src/WordsrepClass.cpp 

OBJS += \
./src/ArgumentParserClass.o \
./src/FileReaderClass.o \
./src/FileWriterClass.o \
./src/LineToWordsClass.o \
./src/WordsToLineClass.o \
./src/WordsrepClass.o 

CPP_DEPS += \
./src/ArgumentParserClass.d \
./src/FileReaderClass.d \
./src/FileWriterClass.d \
./src/LineToWordsClass.d \
./src/WordsToLineClass.d \
./src/WordsrepClass.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/tdd1/workspace_jacobmossberg3/WordsrepAppJacob/interface" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


