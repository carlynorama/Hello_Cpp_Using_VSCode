# Set the minimum required version
cmake_minimum_required(VERSION 3.24)
# Project Information
project(Hello
        VERSION 0.0.1
        DESCRIPTION "Complete Miscellany"
        LANGUAGES CXX)  

# Name the Executable Target and say which files it uses
add_executable(ClickHello HelloWorld.cpp)
target_compile_features(ClickHello PRIVATE cxx_std_20)