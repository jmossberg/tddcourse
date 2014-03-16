################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../external/gmock-gtest-all.cc 

OBJS += \
./external/gmock-gtest-all.o 

CC_DEPS += \
./external/gmock-gtest-all.d 


# Each subdirectory must supply rules for building sources it contributes
external/%.o: ../external/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/tdd1/workspace_jacobmossberg3/WordsrepAppJacob/external" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


