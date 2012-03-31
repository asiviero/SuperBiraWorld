################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../mimimi/Box2D/Common/b2BlockAllocator.cpp \
../mimimi/Box2D/Common/b2Draw.cpp \
../mimimi/Box2D/Common/b2Math.cpp \
../mimimi/Box2D/Common/b2Settings.cpp \
../mimimi/Box2D/Common/b2StackAllocator.cpp \
../mimimi/Box2D/Common/b2Timer.cpp 

OBJS += \
./mimimi/Box2D/Common/b2BlockAllocator.o \
./mimimi/Box2D/Common/b2Draw.o \
./mimimi/Box2D/Common/b2Math.o \
./mimimi/Box2D/Common/b2Settings.o \
./mimimi/Box2D/Common/b2StackAllocator.o \
./mimimi/Box2D/Common/b2Timer.o 

CPP_DEPS += \
./mimimi/Box2D/Common/b2BlockAllocator.d \
./mimimi/Box2D/Common/b2Draw.d \
./mimimi/Box2D/Common/b2Math.d \
./mimimi/Box2D/Common/b2Settings.d \
./mimimi/Box2D/Common/b2StackAllocator.d \
./mimimi/Box2D/Common/b2Timer.d 


# Each subdirectory must supply rules for building sources it contributes
mimimi/Box2D/Common/%.o: ../mimimi/Box2D/Common/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


