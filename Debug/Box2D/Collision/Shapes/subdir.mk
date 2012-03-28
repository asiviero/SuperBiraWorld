################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Box2D/Collision/Shapes/b2ChainShape.cpp \
../Box2D/Collision/Shapes/b2CircleShape.cpp \
../Box2D/Collision/Shapes/b2EdgeShape.cpp \
../Box2D/Collision/Shapes/b2PolygonShape.cpp 

OBJS += \
./Box2D/Collision/Shapes/b2ChainShape.o \
./Box2D/Collision/Shapes/b2CircleShape.o \
./Box2D/Collision/Shapes/b2EdgeShape.o \
./Box2D/Collision/Shapes/b2PolygonShape.o 

CPP_DEPS += \
./Box2D/Collision/Shapes/b2ChainShape.d \
./Box2D/Collision/Shapes/b2CircleShape.d \
./Box2D/Collision/Shapes/b2EdgeShape.d \
./Box2D/Collision/Shapes/b2PolygonShape.d 


# Each subdirectory must supply rules for building sources it contributes
Box2D/Collision/Shapes/%.o: ../Box2D/Collision/Shapes/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


