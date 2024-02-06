#CMakeLists file for SuperTrack

cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project (Histogram_Utilities VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD "17")

include(FetchContent)
FetchContent_Declare(
  rapidcsv
  GIT_REPOSITORY "https://github.com/d99kris/rapidcsv.git"
  GIT_TAG        "v8.50"
)
FetchContent_MakeAvailable(rapidcsv)

###
### Find and include ROOT libraries
###

find_package(ROOT 6.25 CONFIG REQUIRED)
include("${ROOT_USE_FILE}") #include the ROOT CMakelists which defines $ROOT_LIBRARIES

###
### Configure executable and in-project libraries
###

add_executable(Histogram_Utilities Histogram_Utilities.cc)

#locate our project source files and make a library
file(GLOB_RECURSE sources ${CMAKE_SOURCE_DIR}/src/*.cc)
add_library(src STATIC ${sources})

#public below means the main Histgram_utilities inherits the include directories of src
#hard coding the include directories is sloppy, but simple
target_include_directories(src PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(src PUBLIC rapidcsv)

#Now link my libraries
target_link_libraries(Histogram_Utilities PRIVATE src ${ROOT_LIBRARIES})


