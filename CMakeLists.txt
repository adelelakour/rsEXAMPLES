cmake_minimum_required(VERSION 3.25.2)
project(rsEXAMPLES)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PCL 1.13 REQUIRED)
find_package(realsense2 REQUIRED)
find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(rsEXAMPLES main.cpp)

target_include_directories(rsEXAMPLES PRIVATE ${PCL_INCLUDE_DIRS})

target_link_libraries(rsEXAMPLES
        ${PCL_LIBRARIES}
        realsense2
        glfw
        ${OPENGL_LIBRARIES}
)


target_compile_features(rsEXAMPLES PRIVATE cxx_std_17)

install(TARGETS rsEXAMPLES RUNTIME DESTINATION bin)
