cmake_minimum_required(VERSION 3.14)

# set the project name
set(CMAKE_PROJECT_NAME "TEMPLATE")
project(${CMAKE_PROJECT_NAME} CXX CUDA)

# print project name
message("Project name: ${CMAKE_PROJECT_NAME}")

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

#
# for production
#
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -pedantic -lm -O3 -funroll-loops")
#
# for debugging
#
#set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -pedantic -lm -g -funroll-loops") # debug

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

# find installed MPI
message(STATUS "Running CMAKE FindMPI.cmake...")
find_package(MPI)

message(STATUS "MPI_FOUND: ${MPI_FOUND}")
message(STATUS "MPI_VERSION: ${MPI_VERSION}")

# find openmp
#find_package(OpenMP)

# find HDF5 parallel TODO: check parallel io is enable or not
#message(STATUS "Running CMAKE FindHDF5.cmake...")
# set parallel HDF5 default
#set(HDF5_PREFER_PARALLEL TRUE)
#find_package(HDF5)

# cuda
find_package(CUDA)
# add .cu if cuda found
if(CUDA_FOUND) # TODO : add HIP here in the future
  message(STATUS "CUDA_FOUND: ${CUDA_FOUND}")
  add_definitions(-DUSE_CUDA)
  # list of source files
  file(GLOB SOURCES "src/*.cpp" "src/*.cu")
else()
  message(STATUS "CUDA not found. This library is compiled without CUDA.")
  # list of source files
  file(GLOB SOURCES "src/*.cpp")
  #file(GLOB SOURCES_EXT_XML "external_libs/tinyxml2/*.cpp")
endif()

# submodules
# yaml parser
add_subdirectory(external_libs)
#include_directories(${PROJECT_SOURCE_DIR}/external_libs/yaml-cpp/include)

# add include directory
include_directories(include)

# add the executable
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})# ${SOURCES_EXT_XML})

# set include path
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
          ${PROJECT_SOURCE_DIR}/include)
          #${PROJECT_SOURCE_DIR}/external_libs/tinyxml2)

# link mpi
target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC MPI::MPI_CXX)

# link yaml-app:
#target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC yaml-cpp)
#target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/external_libs/yaml-cpp/include)

# link openmp
#target_link_libraries(Grid PUBLIC MPI::MPI_CXX OpenMP::OpenMP_CXX)
#target_link_libraries(ESFAST PUBLIC MPI::MPI_CXX OpenMP::OpenMP_CXX)

# link HDF5
#target_link_libraries(ESFAST PUBLIC ${HDF5_LIBRARIES})
#target_include_directories(ESFAST PUBLIC ${HDF5_INCLUDE_DIRS})
