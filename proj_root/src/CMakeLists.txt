
cmake_minimum_required( VERSION 3.0 )

# Mark the language as C so that CMake doesn't try to test the C++
# cross-compiler's ability to compile a simple program because that will fail
project(currantOS C ASM )

set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0" )
set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g" )
set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -nostartfiles" )
add_definitions( -Wl,-T,./linker_script/rpi.x )

add_executable(currantOS
	main/gpio.c
	main/main.c
	main/timer.c	
	main/interrupts.c
	main/arm_timer.c
	main/aux.c
	main/serial.c
	main/led.h
	main/console.c
	init/start.S
	init/cstartup.c
	lib/cstubs.c
)

add_custom_command(
	TARGET currantOS POST_BUILD
	COMMAND ${CMAKE_OBJCOPY} ./currantOS${CMAKE_EXECUTABLE_SUFFIX} -O binary ../bin/kernel.img
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Convert the ELF output file to a binary image" )
