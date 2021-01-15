cmake_minimum_required (VERSION 3.12)
# cross-compilation toolchain -----------------------------------------------
set(CMAKE_TOOLCHAIN_FILE toolchain-aarch64.cmake)

project(opencv_test)

# cmake flags ---------------------------------------------------------------
set(CMAKE_CXX_FLAGS "-O3 -Wall -Wextra")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS YES)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_FIND_DEBUG_MODE ON)

# threads are nice ----------------------------------------------------------
find_package(Threads REQUIRED)

# cross-compiled opencv -----------------------------------------------------
if (NOT DEFINED ENV{OPENCV_ARM64_ROOT})
	message(FATAL_ERROR "cannot find ENV variable OPENCV_ARM64_ROOT")
endif ()
set(OpenCV_DIR $ENV{OPENCV_ARM64_ROOT}/lib/cmake/opencv4)
find_package(OpenCV 4 REQUIRED)

# include dirs --------------------------------------------------------------
include_directories(
	# /usr/aarch64-linux-gnu/include
	${OpenCV_INCLUDE_DIRS}
	${PROJECT_SOURCE_DIR}/include
)

# executable ----------------------------------------------------------------
add_executable(${PROJECT_NAME}
	main.cpp
)
target_link_libraries(${PROJECT_NAME}
    ${OpenCV_LIBS}
    pthread
)