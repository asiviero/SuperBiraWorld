################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../mimimi/SuperBiraWorld/Box2D/Dynamics/b2Body.cpp \
../mimimi/SuperBiraWorld/Box2D/Dynamics/b2ContactManager.cpp \
../mimimi/SuperBiraWorld/Box2D/Dynamics/b2Fixture.cpp \
../mimimi/SuperBiraWorld/Box2D/Dynamics/b2Island.cpp \
../mimimi/SuperBiraWorld/Box2D/Dynamics/b2World.cpp \
../mimimi/SuperBiraWorld/Box2D/Dynamics/b2WorldCallbacks.cpp 

OBJS += \
./mimimi/SuperBiraWorld/Box2D/Dynamics/b2Body.o \
./mimimi/SuperBiraWorld/Box2D/Dynamics/b2ContactManager.o \
./mimimi/SuperBiraWorld/Box2D/Dynamics/b2Fixture.o \
./mimimi/SuperBiraWorld/Box2D/Dynamics/b2Island.o \
./mimimi/SuperBiraWorld/Box2D/Dynamics/b2World.o \
./mimimi/SuperBiraWorld/Box2D/Dynamics/b2WorldCallbacks.o 

CPP_DEPS += \
./mimimi/SuperBiraWorld/Box2D/Dynamics/b2Body.d \
./mimimi/SuperBiraWorld/Box2D/Dynamics/b2ContactManager.d \
./mimimi/SuperBiraWorld/Box2D/Dynamics/b2Fixture.d \
./mimimi/SuperBiraWorld/Box2D/Dynamics/b2Island.d \
./mimimi/SuperBiraWorld/Box2D/Dynamics/b2World.d \
./mimimi/SuperBiraWorld/Box2D/Dynamics/b2WorldCallbacks.d 


# Each subdirectory must supply rules for building sources it contributes
mimimi/SuperBiraWorld/Box2D/Dynamics/%.o: ../mimimi/SuperBiraWorld/Box2D/Dynamics/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


