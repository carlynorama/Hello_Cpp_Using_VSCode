# Set the minimum required version
cmake_minimum_required(VERSION 3.24)
# Project Information
project(Primes
        VERSION 0.0.1
        DESCRIPTION "Complete Miscellany"
        LANGUAGES CXX)  

#Name the library and the files it uses         
add_library(PrimeNumberStore PrimeLib.cpp PrimeLib.hpp)

# Name the Executable Target and say which files it uses
add_executable(PrimeEmitter Prime.cpp)
target_compile_features(PrimeEmitter PRIVATE cxx_std_20)

# Link the library
target_link_libraries(PrimeEmitter PRIVATE PrimeNumberStore)
 
# If instead of including resources inthe binary, want them as dir
# Example of add_custom_command(), Move a Resources Folder
add_custom_command(
	TARGET PrimeEmitter POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
		${CMAKE_SOURCE_DIR}/resources $<TARGET_FILE_DIR:PrimeEmitter>/resources
)

