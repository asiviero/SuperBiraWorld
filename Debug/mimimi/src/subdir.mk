################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../mimimi/src/agent.cpp \
../mimimi/src/bounce.cpp \
../mimimi/src/directional.cpp \
../mimimi/src/friction.cpp \
../mimimi/src/generalDrawing.cpp \
../mimimi/src/gravity.cpp \
../mimimi/src/terrain.cpp \
../mimimi/src/timer.cpp \
../mimimi/src/userInput.cpp 

OBJS += \
./mimimi/src/agent.o \
./mimimi/src/bounce.o \
./mimimi/src/directional.o \
./mimimi/src/friction.o \
./mimimi/src/generalDrawing.o \
./mimimi/src/gravity.o \
./mimimi/src/terrain.o \
./mimimi/src/timer.o \
./mimimi/src/userInput.o 

CPP_DEPS += \
./mimimi/src/agent.d \
./mimimi/src/bounce.d \
./mimimi/src/directional.d \
./mimimi/src/friction.d \
./mimimi/src/generalDrawing.d \
./mimimi/src/gravity.d \
./mimimi/src/terrain.d \
./mimimi/src/timer.d \
./mimimi/src/userInput.d 


# Each subdirectory must supply rules for building sources it contributes
mimimi/src/%.o: ../mimimi/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


