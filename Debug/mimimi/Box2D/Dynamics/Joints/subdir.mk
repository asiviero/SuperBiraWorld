################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../mimimi/Box2D/Dynamics/Joints/b2DistanceJoint.cpp \
../mimimi/Box2D/Dynamics/Joints/b2FrictionJoint.cpp \
../mimimi/Box2D/Dynamics/Joints/b2GearJoint.cpp \
../mimimi/Box2D/Dynamics/Joints/b2Joint.cpp \
../mimimi/Box2D/Dynamics/Joints/b2MouseJoint.cpp \
../mimimi/Box2D/Dynamics/Joints/b2PrismaticJoint.cpp \
../mimimi/Box2D/Dynamics/Joints/b2PulleyJoint.cpp \
../mimimi/Box2D/Dynamics/Joints/b2RevoluteJoint.cpp \
../mimimi/Box2D/Dynamics/Joints/b2RopeJoint.cpp \
../mimimi/Box2D/Dynamics/Joints/b2WeldJoint.cpp \
../mimimi/Box2D/Dynamics/Joints/b2WheelJoint.cpp 

OBJS += \
./mimimi/Box2D/Dynamics/Joints/b2DistanceJoint.o \
./mimimi/Box2D/Dynamics/Joints/b2FrictionJoint.o \
./mimimi/Box2D/Dynamics/Joints/b2GearJoint.o \
./mimimi/Box2D/Dynamics/Joints/b2Joint.o \
./mimimi/Box2D/Dynamics/Joints/b2MouseJoint.o \
./mimimi/Box2D/Dynamics/Joints/b2PrismaticJoint.o \
./mimimi/Box2D/Dynamics/Joints/b2PulleyJoint.o \
./mimimi/Box2D/Dynamics/Joints/b2RevoluteJoint.o \
./mimimi/Box2D/Dynamics/Joints/b2RopeJoint.o \
./mimimi/Box2D/Dynamics/Joints/b2WeldJoint.o \
./mimimi/Box2D/Dynamics/Joints/b2WheelJoint.o 

CPP_DEPS += \
./mimimi/Box2D/Dynamics/Joints/b2DistanceJoint.d \
./mimimi/Box2D/Dynamics/Joints/b2FrictionJoint.d \
./mimimi/Box2D/Dynamics/Joints/b2GearJoint.d \
./mimimi/Box2D/Dynamics/Joints/b2Joint.d \
./mimimi/Box2D/Dynamics/Joints/b2MouseJoint.d \
./mimimi/Box2D/Dynamics/Joints/b2PrismaticJoint.d \
./mimimi/Box2D/Dynamics/Joints/b2PulleyJoint.d \
./mimimi/Box2D/Dynamics/Joints/b2RevoluteJoint.d \
./mimimi/Box2D/Dynamics/Joints/b2RopeJoint.d \
./mimimi/Box2D/Dynamics/Joints/b2WeldJoint.d \
./mimimi/Box2D/Dynamics/Joints/b2WheelJoint.d 


# Each subdirectory must supply rules for building sources it contributes
mimimi/Box2D/Dynamics/Joints/%.o: ../mimimi/Box2D/Dynamics/Joints/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


