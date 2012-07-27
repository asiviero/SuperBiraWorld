################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Box2D/Dynamics/Joints/b2DistanceJoint.cpp \
../Box2D/Dynamics/Joints/b2FrictionJoint.cpp \
../Box2D/Dynamics/Joints/b2GearJoint.cpp \
../Box2D/Dynamics/Joints/b2Joint.cpp \
../Box2D/Dynamics/Joints/b2MouseJoint.cpp \
../Box2D/Dynamics/Joints/b2PrismaticJoint.cpp \
../Box2D/Dynamics/Joints/b2PulleyJoint.cpp \
../Box2D/Dynamics/Joints/b2RevoluteJoint.cpp \
../Box2D/Dynamics/Joints/b2RopeJoint.cpp \
../Box2D/Dynamics/Joints/b2WeldJoint.cpp \
../Box2D/Dynamics/Joints/b2WheelJoint.cpp 

OBJS += \
./Box2D/Dynamics/Joints/b2DistanceJoint.o \
./Box2D/Dynamics/Joints/b2FrictionJoint.o \
./Box2D/Dynamics/Joints/b2GearJoint.o \
./Box2D/Dynamics/Joints/b2Joint.o \
./Box2D/Dynamics/Joints/b2MouseJoint.o \
./Box2D/Dynamics/Joints/b2PrismaticJoint.o \
./Box2D/Dynamics/Joints/b2PulleyJoint.o \
./Box2D/Dynamics/Joints/b2RevoluteJoint.o \
./Box2D/Dynamics/Joints/b2RopeJoint.o \
./Box2D/Dynamics/Joints/b2WeldJoint.o \
./Box2D/Dynamics/Joints/b2WheelJoint.o 

CPP_DEPS += \
./Box2D/Dynamics/Joints/b2DistanceJoint.d \
./Box2D/Dynamics/Joints/b2FrictionJoint.d \
./Box2D/Dynamics/Joints/b2GearJoint.d \
./Box2D/Dynamics/Joints/b2Joint.d \
./Box2D/Dynamics/Joints/b2MouseJoint.d \
./Box2D/Dynamics/Joints/b2PrismaticJoint.d \
./Box2D/Dynamics/Joints/b2PulleyJoint.d \
./Box2D/Dynamics/Joints/b2RevoluteJoint.d \
./Box2D/Dynamics/Joints/b2RopeJoint.d \
./Box2D/Dynamics/Joints/b2WeldJoint.d \
./Box2D/Dynamics/Joints/b2WheelJoint.d 


# Each subdirectory must supply rules for building sources it contributes
Box2D/Dynamics/Joints/%.o: ../Box2D/Dynamics/Joints/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -g3 -Wall -c -fmessage-length=0 `sdl-config --cflags --libs` -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


