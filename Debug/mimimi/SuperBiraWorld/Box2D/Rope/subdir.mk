################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../mimimi/SuperBiraWorld/Box2D/Rope/b2Rope.cpp 

OBJS += \
./mimimi/SuperBiraWorld/Box2D/Rope/b2Rope.o 

CPP_DEPS += \
./mimimi/SuperBiraWorld/Box2D/Rope/b2Rope.d 


# Each subdirectory must supply rules for building sources it contributes
mimimi/SuperBiraWorld/Box2D/Rope/%.o: ../mimimi/SuperBiraWorld/Box2D/Rope/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


