################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../mimimi/SuperBiraWorld/src/agent.cpp \
../mimimi/SuperBiraWorld/src/bounce.cpp \
../mimimi/SuperBiraWorld/src/directional.cpp \
../mimimi/SuperBiraWorld/src/friction.cpp \
../mimimi/SuperBiraWorld/src/generalDrawing.cpp \
../mimimi/SuperBiraWorld/src/gravity.cpp \
../mimimi/SuperBiraWorld/src/terrain.cpp \
../mimimi/SuperBiraWorld/src/timer.cpp \
../mimimi/SuperBiraWorld/src/userInput.cpp 

OBJS += \
./mimimi/SuperBiraWorld/src/agent.o \
./mimimi/SuperBiraWorld/src/bounce.o \
./mimimi/SuperBiraWorld/src/directional.o \
./mimimi/SuperBiraWorld/src/friction.o \
./mimimi/SuperBiraWorld/src/generalDrawing.o \
./mimimi/SuperBiraWorld/src/gravity.o \
./mimimi/SuperBiraWorld/src/terrain.o \
./mimimi/SuperBiraWorld/src/timer.o \
./mimimi/SuperBiraWorld/src/userInput.o 

CPP_DEPS += \
./mimimi/SuperBiraWorld/src/agent.d \
./mimimi/SuperBiraWorld/src/bounce.d \
./mimimi/SuperBiraWorld/src/directional.d \
./mimimi/SuperBiraWorld/src/friction.d \
./mimimi/SuperBiraWorld/src/generalDrawing.d \
./mimimi/SuperBiraWorld/src/gravity.d \
./mimimi/SuperBiraWorld/src/terrain.d \
./mimimi/SuperBiraWorld/src/timer.d \
./mimimi/SuperBiraWorld/src/userInput.d 


# Each subdirectory must supply rules for building sources it contributes
mimimi/SuperBiraWorld/src/%.o: ../mimimi/SuperBiraWorld/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


