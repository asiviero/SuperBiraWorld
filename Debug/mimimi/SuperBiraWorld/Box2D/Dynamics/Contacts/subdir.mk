################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../mimimi/SuperBiraWorld/Box2D/Dynamics/Contacts/b2ChainAndCircleContact.cpp \
../mimimi/SuperBiraWorld/Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.cpp \
../mimimi/SuperBiraWorld/Box2D/Dynamics/Contacts/b2CircleContact.cpp \
../mimimi/SuperBiraWorld/Box2D/Dynamics/Contacts/b2Contact.cpp \
../mimimi/SuperBiraWorld/Box2D/Dynamics/Contacts/b2ContactSolver.cpp \
../mimimi/SuperBiraWorld/Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.cpp \
../mimimi/SuperBiraWorld/Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.cpp \
../mimimi/SuperBiraWorld/Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.cpp \
../mimimi/SuperBiraWorld/Box2D/Dynamics/Contacts/b2PolygonContact.cpp 

OBJS += \
./mimimi/SuperBiraWorld/Box2D/Dynamics/Contacts/b2ChainAndCircleContact.o \
./mimimi/SuperBiraWorld/Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.o \
./mimimi/SuperBiraWorld/Box2D/Dynamics/Contacts/b2CircleContact.o \
./mimimi/SuperBiraWorld/Box2D/Dynamics/Contacts/b2Contact.o \
./mimimi/SuperBiraWorld/Box2D/Dynamics/Contacts/b2ContactSolver.o \
./mimimi/SuperBiraWorld/Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.o \
./mimimi/SuperBiraWorld/Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.o \
./mimimi/SuperBiraWorld/Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.o \
./mimimi/SuperBiraWorld/Box2D/Dynamics/Contacts/b2PolygonContact.o 

CPP_DEPS += \
./mimimi/SuperBiraWorld/Box2D/Dynamics/Contacts/b2ChainAndCircleContact.d \
./mimimi/SuperBiraWorld/Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.d \
./mimimi/SuperBiraWorld/Box2D/Dynamics/Contacts/b2CircleContact.d \
./mimimi/SuperBiraWorld/Box2D/Dynamics/Contacts/b2Contact.d \
./mimimi/SuperBiraWorld/Box2D/Dynamics/Contacts/b2ContactSolver.d \
./mimimi/SuperBiraWorld/Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.d \
./mimimi/SuperBiraWorld/Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.d \
./mimimi/SuperBiraWorld/Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.d \
./mimimi/SuperBiraWorld/Box2D/Dynamics/Contacts/b2PolygonContact.d 


# Each subdirectory must supply rules for building sources it contributes
mimimi/SuperBiraWorld/Box2D/Dynamics/Contacts/%.o: ../mimimi/SuperBiraWorld/Box2D/Dynamics/Contacts/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


