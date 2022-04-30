cmake_minimum_required(VERSION 2.8.7)

project(primenum)
add_executable(primenum main.c)

include(CheckLibraryExists)
CHECK_LIBRARY_EXISTS(m sin "" HAVE_LIB_M)                                                                                                
                                                                                                                                         
if (HAVE_LIB_M)
    target_link_libraries(primenum m)
endif (HAVE_LIB_M)

set(CMAKE_C_FLAGS "-std=c99")
#target_compile_features(primenum PUBLIC c_std_99)
