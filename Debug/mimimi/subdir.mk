################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../mimimi/Render.cpp \
../mimimi/main.cpp 

OBJS += \
./mimimi/Render.o \
./mimimi/main.o 

CPP_DEPS += \
./mimimi/Render.d \
./mimimi/main.d 


# Each subdirectory must supply rules for building sources it contributes
mimimi/%.o: ../mimimi/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


