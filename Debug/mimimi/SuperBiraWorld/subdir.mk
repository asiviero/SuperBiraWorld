################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../mimimi/SuperBiraWorld/Render.cpp \
../mimimi/SuperBiraWorld/main.cpp 

OBJS += \
./mimimi/SuperBiraWorld/Render.o \
./mimimi/SuperBiraWorld/main.o 

CPP_DEPS += \
./mimimi/SuperBiraWorld/Render.d \
./mimimi/SuperBiraWorld/main.d 


# Each subdirectory must supply rules for building sources it contributes
mimimi/SuperBiraWorld/%.o: ../mimimi/SuperBiraWorld/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


