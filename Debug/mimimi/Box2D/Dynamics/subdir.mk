################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../mimimi/Box2D/Dynamics/b2Body.cpp \
../mimimi/Box2D/Dynamics/b2ContactManager.cpp \
../mimimi/Box2D/Dynamics/b2Fixture.cpp \
../mimimi/Box2D/Dynamics/b2Island.cpp \
../mimimi/Box2D/Dynamics/b2World.cpp \
../mimimi/Box2D/Dynamics/b2WorldCallbacks.cpp 

OBJS += \
./mimimi/Box2D/Dynamics/b2Body.o \
./mimimi/Box2D/Dynamics/b2ContactManager.o \
./mimimi/Box2D/Dynamics/b2Fixture.o \
./mimimi/Box2D/Dynamics/b2Island.o \
./mimimi/Box2D/Dynamics/b2World.o \
./mimimi/Box2D/Dynamics/b2WorldCallbacks.o 

CPP_DEPS += \
./mimimi/Box2D/Dynamics/b2Body.d \
./mimimi/Box2D/Dynamics/b2ContactManager.d \
./mimimi/Box2D/Dynamics/b2Fixture.d \
./mimimi/Box2D/Dynamics/b2Island.d \
./mimimi/Box2D/Dynamics/b2World.d \
./mimimi/Box2D/Dynamics/b2WorldCallbacks.d 


# Each subdirectory must supply rules for building sources it contributes
mimimi/Box2D/Dynamics/%.o: ../mimimi/Box2D/Dynamics/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


