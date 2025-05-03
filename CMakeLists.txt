cmake_minimum_required(VERSION 3.10)
project(ShamirsSecretSharing)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include header files
include_directories(include)

# Define source files
set(SOURCES
    app/main.cpp
    code/ModInt.cpp
    code/Polynomial.cpp
    code/Scenarios.cpp
    code/Shamir.cpp
    code/Share.cpp
    code/SSS.cpp
    code/Utils.cpp
)

# Create executable
add_executable(run_app ${SOURCES})