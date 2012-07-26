################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/agent.cpp \
../src/agentData.cpp \
../src/bounce.cpp \
../src/camera.cpp \
../src/contactListener.cpp \
../src/directional.cpp \
../src/enemy.cpp \
../src/enemyData.cpp \
../src/friction.cpp \
../src/generalDrawing.cpp \
../src/gravity.cpp \
../src/m_move.cpp \
../src/terrain.cpp \
../src/timer.cpp \
../src/userInput.cpp 

OBJS += \
./src/agent.o \
./src/agentData.o \
./src/bounce.o \
./src/camera.o \
./src/contactListener.o \
./src/directional.o \
./src/enemy.o \
./src/enemyData.o \
./src/friction.o \
./src/generalDrawing.o \
./src/gravity.o \
./src/m_move.o \
./src/terrain.o \
./src/timer.o \
./src/userInput.o 

CPP_DEPS += \
./src/agent.d \
./src/agentData.d \
./src/bounce.d \
./src/camera.d \
./src/contactListener.d \
./src/directional.d \
./src/enemy.d \
./src/enemyData.d \
./src/friction.d \
./src/generalDrawing.d \
./src/gravity.d \
./src/m_move.d \
./src/terrain.d \
./src/timer.d \
./src/userInput.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


