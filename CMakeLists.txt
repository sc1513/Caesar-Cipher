project(TEST)
cmake_minimum_required(VERSION 2.6)

if (CMAKE_VERSION VERSION_LESS "3.1")
  add_definitions(-std=c++11)
else()
  set(CMAKE_CXX_STANDARD 11)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  set(CMAKE_CXX_EXTENSIONS OFF)
endif()

if(UNIX AND NOT APPLE)
  message(">> Linux")
  add_compile_options(-DWITH_LINUX)
else()
  message(">> non-Linux")
  add_compile_options(-DWITH_APPLE) 
endif()




set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# New code to adjust

add_executable(ceaser.o decrypt.c dictionary_hashtable.c shift_matrix.c file_handler.c)
target_link_libraries(ceaser.o ${GTEST_LIBRARIES} -lpthread -lm)

add_executable(GoogleTest GoogleTest.cc dictionary_hashtable.c shift_matrix.c file_handler.c)
target_link_libraries(GoogleTest ${GTEST_LIBRARIES} -lpthread -lm)
 