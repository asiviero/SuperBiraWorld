################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../mimimi/SuperBiraWorld/Box2D/Dynamics/Joints/b2DistanceJoint.cpp \
../mimimi/SuperBiraWorld/Box2D/Dynamics/Joints/b2FrictionJoint.cpp \
../mimimi/SuperBiraWorld/Box2D/Dynamics/Joints/b2GearJoint.cpp \
../mimimi/SuperBiraWorld/Box2D/Dynamics/Joints/b2Joint.cpp \
../mimimi/SuperBiraWorld/Box2D/Dynamics/Joints/b2MouseJoint.cpp \
../mimimi/SuperBiraWorld/Box2D/Dynamics/Joints/b2PrismaticJoint.cpp \
../mimimi/SuperBiraWorld/Box2D/Dynamics/Joints/b2PulleyJoint.cpp \
../mimimi/SuperBiraWorld/Box2D/Dynamics/Joints/b2RevoluteJoint.cpp \
../mimimi/SuperBiraWorld/Box2D/Dynamics/Joints/b2RopeJoint.cpp \
../mimimi/SuperBiraWorld/Box2D/Dynamics/Joints/b2WeldJoint.cpp \
../mimimi/SuperBiraWorld/Box2D/Dynamics/Joints/b2WheelJoint.cpp 

OBJS += \
./mimimi/SuperBiraWorld/Box2D/Dynamics/Joints/b2DistanceJoint.o \
./mimimi/SuperBiraWorld/Box2D/Dynamics/Joints/b2FrictionJoint.o \
./mimimi/SuperBiraWorld/Box2D/Dynamics/Joints/b2GearJoint.o \
./mimimi/SuperBiraWorld/Box2D/Dynamics/Joints/b2Joint.o \
./mimimi/SuperBiraWorld/Box2D/Dynamics/Joints/b2MouseJoint.o \
./mimimi/SuperBiraWorld/Box2D/Dynamics/Joints/b2PrismaticJoint.o \
./mimimi/SuperBiraWorld/Box2D/Dynamics/Joints/b2PulleyJoint.o \
./mimimi/SuperBiraWorld/Box2D/Dynamics/Joints/b2RevoluteJoint.o \
./mimimi/SuperBiraWorld/Box2D/Dynamics/Joints/b2RopeJoint.o \
./mimimi/SuperBiraWorld/Box2D/Dynamics/Joints/b2WeldJoint.o \
./mimimi/SuperBiraWorld/Box2D/Dynamics/Joints/b2WheelJoint.o 

CPP_DEPS += \
./mimimi/SuperBiraWorld/Box2D/Dynamics/Joints/b2DistanceJoint.d \
./mimimi/SuperBiraWorld/Box2D/Dynamics/Joints/b2FrictionJoint.d \
./mimimi/SuperBiraWorld/Box2D/Dynamics/Joints/b2GearJoint.d \
./mimimi/SuperBiraWorld/Box2D/Dynamics/Joints/b2Joint.d \
./mimimi/SuperBiraWorld/Box2D/Dynamics/Joints/b2MouseJoint.d \
./mimimi/SuperBiraWorld/Box2D/Dynamics/Joints/b2PrismaticJoint.d \
./mimimi/SuperBiraWorld/Box2D/Dynamics/Joints/b2PulleyJoint.d \
./mimimi/SuperBiraWorld/Box2D/Dynamics/Joints/b2RevoluteJoint.d \
./mimimi/SuperBiraWorld/Box2D/Dynamics/Joints/b2RopeJoint.d \
./mimimi/SuperBiraWorld/Box2D/Dynamics/Joints/b2WeldJoint.d \
./mimimi/SuperBiraWorld/Box2D/Dynamics/Joints/b2WheelJoint.d 


# Each subdirectory must supply rules for building sources it contributes
mimimi/SuperBiraWorld/Box2D/Dynamics/Joints/%.o: ../mimimi/SuperBiraWorld/Box2D/Dynamics/Joints/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


