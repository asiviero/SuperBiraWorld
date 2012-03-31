################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../mimimi/SuperBiraWorld/Box2D/Common/b2BlockAllocator.cpp \
../mimimi/SuperBiraWorld/Box2D/Common/b2Draw.cpp \
../mimimi/SuperBiraWorld/Box2D/Common/b2Math.cpp \
../mimimi/SuperBiraWorld/Box2D/Common/b2Settings.cpp \
../mimimi/SuperBiraWorld/Box2D/Common/b2StackAllocator.cpp \
../mimimi/SuperBiraWorld/Box2D/Common/b2Timer.cpp 

OBJS += \
./mimimi/SuperBiraWorld/Box2D/Common/b2BlockAllocator.o \
./mimimi/SuperBiraWorld/Box2D/Common/b2Draw.o \
./mimimi/SuperBiraWorld/Box2D/Common/b2Math.o \
./mimimi/SuperBiraWorld/Box2D/Common/b2Settings.o \
./mimimi/SuperBiraWorld/Box2D/Common/b2StackAllocator.o \
./mimimi/SuperBiraWorld/Box2D/Common/b2Timer.o 

CPP_DEPS += \
./mimimi/SuperBiraWorld/Box2D/Common/b2BlockAllocator.d \
./mimimi/SuperBiraWorld/Box2D/Common/b2Draw.d \
./mimimi/SuperBiraWorld/Box2D/Common/b2Math.d \
./mimimi/SuperBiraWorld/Box2D/Common/b2Settings.d \
./mimimi/SuperBiraWorld/Box2D/Common/b2StackAllocator.d \
./mimimi/SuperBiraWorld/Box2D/Common/b2Timer.d 


# Each subdirectory must supply rules for building sources it contributes
mimimi/SuperBiraWorld/Box2D/Common/%.o: ../mimimi/SuperBiraWorld/Box2D/Common/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


