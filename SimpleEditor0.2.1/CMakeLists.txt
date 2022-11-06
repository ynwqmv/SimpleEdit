cmake_minimum_required(VERSION 3.7.1)
project(main)


find_package(wxWidgets 3.0.5 REQUIRED)
find_package(OpenGL)
include(${wxWidgets_USE_FILE})


link_libraries(${wxWidgets_LIBRARIES} ${OPENGL_LIBRARIES})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE main.cpp)

