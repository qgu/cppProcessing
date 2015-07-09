################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ADCDecoding.cpp \
../test_ADCDecoding.cpp \
../testing.cpp 

OBJS += \
./ADCDecoding.o \
./test_ADCDecoding.o \
./testing.o 

CPP_DEPS += \
./ADCDecoding.d \
./test_ADCDecoding.d \
./testing.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


