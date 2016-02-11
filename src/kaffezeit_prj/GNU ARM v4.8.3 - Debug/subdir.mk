################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../LogType.cpp \
../MFRC522.cpp \
../User.cpp \
../main.cpp 

OBJS += \
./LogType.o \
./MFRC522.o \
./User.o \
./main.o 

CPP_DEPS += \
./LogType.d \
./MFRC522.d \
./User.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
LogType.o: ../LogType.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C++ Compiler'
	arm-none-eabi-g++ -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG990F1024=1' '-DTOOLCHAIN_GCC_ARM=' '-DTOOLCHAIN_GCC=' '-DTARGET_CORTEX_M=' '-DTARGET_Silicon_Labs=' '-DARM_MATH_CM3=' '-DTARGET_EFM32=' '-D__CORTEX_M3=' '-DTARGET_M3=' '-DTARGET_EFM32GG_STK3700=' '-DMBED_BUILD_TIMESTAMP=1454591546.8' '-D__MBED__=1' '-DDEBUG=1' -I"C:\Users\vitor\Downloads\mbed_blinky\mbed" -I"C:\Users\vitor\Downloads\mbed_blinky\mbed\TARGET_EFM32GG_STK3700" -I"C:\Users\vitor\Downloads\mbed_blinky\mbed\TARGET_EFM32GG_STK3700\TARGET_Silicon_Labs" -I"C:\Users\vitor\Downloads\mbed_blinky\mbed\TARGET_EFM32GG_STK3700\TARGET_Silicon_Labs\TARGET_EFM32" -I"C:\Users\vitor\Downloads\mbed_blinky\mbed\TARGET_EFM32GG_STK3700\TARGET_Silicon_Labs\TARGET_EFM32\TARGET_EFM32GG_STK3700" -I"C:\Users\vitor\Downloads\mbed_blinky\mbed\TARGET_EFM32GG_STK3700\TARGET_Silicon_Labs\TARGET_EFM32\emlib" -I"C:\Users\vitor\Downloads\mbed_blinky\mbed\TARGET_EFM32GG_STK3700\TARGET_Silicon_Labs\TARGET_EFM32\emlib\inc" -I"C:\Users\vitor\Downloads\mbed_blinky\mbed\TARGET_EFM32GG_STK3700\TOOLCHAIN_GCC_ARM" -I"C:\Users\vitor\SimplicityStudio\v3_workspace\mbed_blinky" -O0 -Wall -c -fmessage-length=0 -fno-rtti -fno-exceptions -fno-common -fomit-frame-pointer -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"LogType.d" -MT"LogType.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

MFRC522.o: ../MFRC522.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C++ Compiler'
	arm-none-eabi-g++ -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG990F1024=1' '-DTOOLCHAIN_GCC_ARM=' '-DTOOLCHAIN_GCC=' '-DTARGET_CORTEX_M=' '-DTARGET_Silicon_Labs=' '-DARM_MATH_CM3=' '-DTARGET_EFM32=' '-D__CORTEX_M3=' '-DTARGET_M3=' '-DTARGET_EFM32GG_STK3700=' '-DMBED_BUILD_TIMESTAMP=1454591546.8' '-D__MBED__=1' '-DDEBUG=1' -I"C:\Users\vitor\Downloads\mbed_blinky\mbed" -I"C:\Users\vitor\Downloads\mbed_blinky\mbed\TARGET_EFM32GG_STK3700" -I"C:\Users\vitor\Downloads\mbed_blinky\mbed\TARGET_EFM32GG_STK3700\TARGET_Silicon_Labs" -I"C:\Users\vitor\Downloads\mbed_blinky\mbed\TARGET_EFM32GG_STK3700\TARGET_Silicon_Labs\TARGET_EFM32" -I"C:\Users\vitor\Downloads\mbed_blinky\mbed\TARGET_EFM32GG_STK3700\TARGET_Silicon_Labs\TARGET_EFM32\TARGET_EFM32GG_STK3700" -I"C:\Users\vitor\Downloads\mbed_blinky\mbed\TARGET_EFM32GG_STK3700\TARGET_Silicon_Labs\TARGET_EFM32\emlib" -I"C:\Users\vitor\Downloads\mbed_blinky\mbed\TARGET_EFM32GG_STK3700\TARGET_Silicon_Labs\TARGET_EFM32\emlib\inc" -I"C:\Users\vitor\Downloads\mbed_blinky\mbed\TARGET_EFM32GG_STK3700\TOOLCHAIN_GCC_ARM" -I"C:\Users\vitor\SimplicityStudio\v3_workspace\mbed_blinky" -O0 -Wall -c -fmessage-length=0 -fno-rtti -fno-exceptions -fno-common -fomit-frame-pointer -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"MFRC522.d" -MT"MFRC522.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

User.o: ../User.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C++ Compiler'
	arm-none-eabi-g++ -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG990F1024=1' '-DTOOLCHAIN_GCC_ARM=' '-DTOOLCHAIN_GCC=' '-DTARGET_CORTEX_M=' '-DTARGET_Silicon_Labs=' '-DARM_MATH_CM3=' '-DTARGET_EFM32=' '-D__CORTEX_M3=' '-DTARGET_M3=' '-DTARGET_EFM32GG_STK3700=' '-DMBED_BUILD_TIMESTAMP=1454591546.8' '-D__MBED__=1' '-DDEBUG=1' -I"C:\Users\vitor\Downloads\mbed_blinky\mbed" -I"C:\Users\vitor\Downloads\mbed_blinky\mbed\TARGET_EFM32GG_STK3700" -I"C:\Users\vitor\Downloads\mbed_blinky\mbed\TARGET_EFM32GG_STK3700\TARGET_Silicon_Labs" -I"C:\Users\vitor\Downloads\mbed_blinky\mbed\TARGET_EFM32GG_STK3700\TARGET_Silicon_Labs\TARGET_EFM32" -I"C:\Users\vitor\Downloads\mbed_blinky\mbed\TARGET_EFM32GG_STK3700\TARGET_Silicon_Labs\TARGET_EFM32\TARGET_EFM32GG_STK3700" -I"C:\Users\vitor\Downloads\mbed_blinky\mbed\TARGET_EFM32GG_STK3700\TARGET_Silicon_Labs\TARGET_EFM32\emlib" -I"C:\Users\vitor\Downloads\mbed_blinky\mbed\TARGET_EFM32GG_STK3700\TARGET_Silicon_Labs\TARGET_EFM32\emlib\inc" -I"C:\Users\vitor\Downloads\mbed_blinky\mbed\TARGET_EFM32GG_STK3700\TOOLCHAIN_GCC_ARM" -I"C:\Users\vitor\SimplicityStudio\v3_workspace\mbed_blinky" -O0 -Wall -c -fmessage-length=0 -fno-rtti -fno-exceptions -fno-common -fomit-frame-pointer -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"User.d" -MT"User.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.o: ../main.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C++ Compiler'
	arm-none-eabi-g++ -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG990F1024=1' '-DTOOLCHAIN_GCC_ARM=' '-DTOOLCHAIN_GCC=' '-DTARGET_CORTEX_M=' '-DTARGET_Silicon_Labs=' '-DARM_MATH_CM3=' '-DTARGET_EFM32=' '-D__CORTEX_M3=' '-DTARGET_M3=' '-DTARGET_EFM32GG_STK3700=' '-DMBED_BUILD_TIMESTAMP=1454591546.8' '-D__MBED__=1' '-DDEBUG=1' -I"C:\Users\vitor\Downloads\mbed_blinky\mbed" -I"C:\Users\vitor\Downloads\mbed_blinky\mbed\TARGET_EFM32GG_STK3700" -I"C:\Users\vitor\Downloads\mbed_blinky\mbed\TARGET_EFM32GG_STK3700\TARGET_Silicon_Labs" -I"C:\Users\vitor\Downloads\mbed_blinky\mbed\TARGET_EFM32GG_STK3700\TARGET_Silicon_Labs\TARGET_EFM32" -I"C:\Users\vitor\Downloads\mbed_blinky\mbed\TARGET_EFM32GG_STK3700\TARGET_Silicon_Labs\TARGET_EFM32\TARGET_EFM32GG_STK3700" -I"C:\Users\vitor\Downloads\mbed_blinky\mbed\TARGET_EFM32GG_STK3700\TARGET_Silicon_Labs\TARGET_EFM32\emlib" -I"C:\Users\vitor\Downloads\mbed_blinky\mbed\TARGET_EFM32GG_STK3700\TARGET_Silicon_Labs\TARGET_EFM32\emlib\inc" -I"C:\Users\vitor\Downloads\mbed_blinky\mbed\TARGET_EFM32GG_STK3700\TOOLCHAIN_GCC_ARM" -I"C:\Users\vitor\SimplicityStudio\v3_workspace\mbed_blinky" -O0 -Wall -c -fmessage-length=0 -fno-rtti -fno-exceptions -fno-common -fomit-frame-pointer -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"main.d" -MT"main.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


