################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Box2D/Dynamics/b2Body.cpp \
../Box2D/Dynamics/b2ContactManager.cpp \
../Box2D/Dynamics/b2Fixture.cpp \
../Box2D/Dynamics/b2Island.cpp \
../Box2D/Dynamics/b2World.cpp \
../Box2D/Dynamics/b2WorldCallbacks.cpp 

OBJS += \
./Box2D/Dynamics/b2Body.o \
./Box2D/Dynamics/b2ContactManager.o \
./Box2D/Dynamics/b2Fixture.o \
./Box2D/Dynamics/b2Island.o \
./Box2D/Dynamics/b2World.o \
./Box2D/Dynamics/b2WorldCallbacks.o 

CPP_DEPS += \
./Box2D/Dynamics/b2Body.d \
./Box2D/Dynamics/b2ContactManager.d \
./Box2D/Dynamics/b2Fixture.d \
./Box2D/Dynamics/b2Island.d \
./Box2D/Dynamics/b2World.d \
./Box2D/Dynamics/b2WorldCallbacks.d 


# Each subdirectory must supply rules for building sources it contributes
Box2D/Dynamics/%.o: ../Box2D/Dynamics/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


