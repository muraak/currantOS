# A CMake toolchain file so we can cross-compile for the Rapsberry-Pi bare-metal

include(CMakeForceCompiler)

# The Generic system name is used for embedded targets (targets without OS) in
# CMake
set( CMAKE_SYSTEM_NAME          Generic )
set( CMAKE_SYSTEM_PROCESSOR     BCM2836 )

# Toolchain's path(we don't need to set this if it already added to the system path)
set( TC_PATH "" )

# Compiler's Prefix
set( CROSS_COMPILE arm-none-eabi- )

CMAKE_FORCE_C_COMPILER( ${TC_PATH}${CROSS_COMPILE}gcc GNU )

# We must set the OBJCOPY setting into cache so that it's available to the
# whole project. Otherwise, this does not get set into the CACHE and therefore
# the build doesn't know what the OBJCOPY filepath is
set( CMAKE_OBJCOPY      ${TC_PATH}${CROSS_COMPILE}objcopy
    CACHE FILEPATH "The toolchain objcopy command " FORCE )

# Compile Options
set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mfpu=neon-vfpv4" )
set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mfloat-abi=hard" )
set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -march=armv7-a" )
set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mtune=cortex-a7" )

# I don't know what does this mean...
set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS}" CACHE STRING "" )
set( CMAKE_ASM_FLAGS "${CMAKE_C_FLAGS}" CACHE STRING "" )

# Add the raspberry-pi 2 definition so conditional compilation works
add_definitions( -DRPI2=1 )
