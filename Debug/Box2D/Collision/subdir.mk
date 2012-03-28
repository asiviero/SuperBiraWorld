################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Box2D/Collision/b2BroadPhase.cpp \
../Box2D/Collision/b2CollideCircle.cpp \
../Box2D/Collision/b2CollideEdge.cpp \
../Box2D/Collision/b2CollidePolygon.cpp \
../Box2D/Collision/b2Collision.cpp \
../Box2D/Collision/b2Distance.cpp \
../Box2D/Collision/b2DynamicTree.cpp \
../Box2D/Collision/b2TimeOfImpact.cpp 

OBJS += \
./Box2D/Collision/b2BroadPhase.o \
./Box2D/Collision/b2CollideCircle.o \
./Box2D/Collision/b2CollideEdge.o \
./Box2D/Collision/b2CollidePolygon.o \
./Box2D/Collision/b2Collision.o \
./Box2D/Collision/b2Distance.o \
./Box2D/Collision/b2DynamicTree.o \
./Box2D/Collision/b2TimeOfImpact.o 

CPP_DEPS += \
./Box2D/Collision/b2BroadPhase.d \
./Box2D/Collision/b2CollideCircle.d \
./Box2D/Collision/b2CollideEdge.d \
./Box2D/Collision/b2CollidePolygon.d \
./Box2D/Collision/b2Collision.d \
./Box2D/Collision/b2Distance.d \
./Box2D/Collision/b2DynamicTree.d \
./Box2D/Collision/b2TimeOfImpact.d 


# Each subdirectory must supply rules for building sources it contributes
Box2D/Collision/%.o: ../Box2D/Collision/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


