################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Box2D/Common/b2BlockAllocator.cpp \
../Box2D/Common/b2Draw.cpp \
../Box2D/Common/b2Math.cpp \
../Box2D/Common/b2Settings.cpp \
../Box2D/Common/b2StackAllocator.cpp \
../Box2D/Common/b2Timer.cpp 

OBJS += \
./Box2D/Common/b2BlockAllocator.o \
./Box2D/Common/b2Draw.o \
./Box2D/Common/b2Math.o \
./Box2D/Common/b2Settings.o \
./Box2D/Common/b2StackAllocator.o \
./Box2D/Common/b2Timer.o 

CPP_DEPS += \
./Box2D/Common/b2BlockAllocator.d \
./Box2D/Common/b2Draw.d \
./Box2D/Common/b2Math.d \
./Box2D/Common/b2Settings.d \
./Box2D/Common/b2StackAllocator.d \
./Box2D/Common/b2Timer.d 


# Each subdirectory must supply rules for building sources it contributes
Box2D/Common/%.o: ../Box2D/Common/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


