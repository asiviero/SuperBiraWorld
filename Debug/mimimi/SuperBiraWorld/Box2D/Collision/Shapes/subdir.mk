################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../mimimi/SuperBiraWorld/Box2D/Collision/Shapes/b2ChainShape.cpp \
../mimimi/SuperBiraWorld/Box2D/Collision/Shapes/b2CircleShape.cpp \
../mimimi/SuperBiraWorld/Box2D/Collision/Shapes/b2EdgeShape.cpp \
../mimimi/SuperBiraWorld/Box2D/Collision/Shapes/b2PolygonShape.cpp 

OBJS += \
./mimimi/SuperBiraWorld/Box2D/Collision/Shapes/b2ChainShape.o \
./mimimi/SuperBiraWorld/Box2D/Collision/Shapes/b2CircleShape.o \
./mimimi/SuperBiraWorld/Box2D/Collision/Shapes/b2EdgeShape.o \
./mimimi/SuperBiraWorld/Box2D/Collision/Shapes/b2PolygonShape.o 

CPP_DEPS += \
./mimimi/SuperBiraWorld/Box2D/Collision/Shapes/b2ChainShape.d \
./mimimi/SuperBiraWorld/Box2D/Collision/Shapes/b2CircleShape.d \
./mimimi/SuperBiraWorld/Box2D/Collision/Shapes/b2EdgeShape.d \
./mimimi/SuperBiraWorld/Box2D/Collision/Shapes/b2PolygonShape.d 


# Each subdirectory must supply rules for building sources it contributes
mimimi/SuperBiraWorld/Box2D/Collision/Shapes/%.o: ../mimimi/SuperBiraWorld/Box2D/Collision/Shapes/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


