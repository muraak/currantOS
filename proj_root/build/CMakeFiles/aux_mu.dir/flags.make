# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

# compile ASM with /Users/muraak/MyGarage/gcc/gcc-arm-none-eabi-4_7-2013q3/bin/arm-none-eabi-gcc
# compile C with /Users/muraak/MyGarage/gcc/gcc-arm-none-eabi-4_7-2013q3/bin/arm-none-eabi-gcc
ASM_FLAGS =  -mfpu=neon-vfpv4 -mfloat-abi=hard -march=armv7-a -mtune=cortex-a7   -Wl,-T,./linker_script/rpi.x

ASM_DEFINES = -DRPI2=1

ASM_INCLUDES = 

C_FLAGS =  -mfpu=neon-vfpv4 -mfloat-abi=hard -march=armv7-a -mtune=cortex-a7 -mfpu=neon-vfpv4 -mfloat-abi=hard -march=armv7-a -mtune=cortex-a7 -O0 -g -nostartfiles   -Wl,-T,./linker_script/rpi.x

C_DEFINES = -DRPI2=1

C_INCLUDES = 

