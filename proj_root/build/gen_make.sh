rm -r !\(gen_make.sh\)
cmake -G "CodeBlocks - Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE=../rpi2.cmake ../src
