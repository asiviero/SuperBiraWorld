################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Box2D/Dynamics/Contacts/b2ChainAndCircleContact.cpp \
../Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.cpp \
../Box2D/Dynamics/Contacts/b2CircleContact.cpp \
../Box2D/Dynamics/Contacts/b2Contact.cpp \
../Box2D/Dynamics/Contacts/b2ContactSolver.cpp \
../Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.cpp \
../Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.cpp \
../Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.cpp \
../Box2D/Dynamics/Contacts/b2PolygonContact.cpp 

OBJS += \
./Box2D/Dynamics/Contacts/b2ChainAndCircleContact.o \
./Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.o \
./Box2D/Dynamics/Contacts/b2CircleContact.o \
./Box2D/Dynamics/Contacts/b2Contact.o \
./Box2D/Dynamics/Contacts/b2ContactSolver.o \
./Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.o \
./Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.o \
./Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.o \
./Box2D/Dynamics/Contacts/b2PolygonContact.o 

CPP_DEPS += \
./Box2D/Dynamics/Contacts/b2ChainAndCircleContact.d \
./Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.d \
./Box2D/Dynamics/Contacts/b2CircleContact.d \
./Box2D/Dynamics/Contacts/b2Contact.d \
./Box2D/Dynamics/Contacts/b2ContactSolver.d \
./Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.d \
./Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.d \
./Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.d \
./Box2D/Dynamics/Contacts/b2PolygonContact.d 


# Each subdirectory must supply rules for building sources it contributes
Box2D/Dynamics/Contacts/%.o: ../Box2D/Dynamics/Contacts/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


