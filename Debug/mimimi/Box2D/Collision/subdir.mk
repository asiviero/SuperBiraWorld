################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../mimimi/Box2D/Collision/b2BroadPhase.cpp \
../mimimi/Box2D/Collision/b2CollideCircle.cpp \
../mimimi/Box2D/Collision/b2CollideEdge.cpp \
../mimimi/Box2D/Collision/b2CollidePolygon.cpp \
../mimimi/Box2D/Collision/b2Collision.cpp \
../mimimi/Box2D/Collision/b2Distance.cpp \
../mimimi/Box2D/Collision/b2DynamicTree.cpp \
../mimimi/Box2D/Collision/b2TimeOfImpact.cpp 

OBJS += \
./mimimi/Box2D/Collision/b2BroadPhase.o \
./mimimi/Box2D/Collision/b2CollideCircle.o \
./mimimi/Box2D/Collision/b2CollideEdge.o \
./mimimi/Box2D/Collision/b2CollidePolygon.o \
./mimimi/Box2D/Collision/b2Collision.o \
./mimimi/Box2D/Collision/b2Distance.o \
./mimimi/Box2D/Collision/b2DynamicTree.o \
./mimimi/Box2D/Collision/b2TimeOfImpact.o 

CPP_DEPS += \
./mimimi/Box2D/Collision/b2BroadPhase.d \
./mimimi/Box2D/Collision/b2CollideCircle.d \
./mimimi/Box2D/Collision/b2CollideEdge.d \
./mimimi/Box2D/Collision/b2CollidePolygon.d \
./mimimi/Box2D/Collision/b2Collision.d \
./mimimi/Box2D/Collision/b2Distance.d \
./mimimi/Box2D/Collision/b2DynamicTree.d \
./mimimi/Box2D/Collision/b2TimeOfImpact.d 


# Each subdirectory must supply rules for building sources it contributes
mimimi/Box2D/Collision/%.o: ../mimimi/Box2D/Collision/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


