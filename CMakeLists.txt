cmake_minimum_required(VERSION 2.8)
project(simple-ogre-project)

find_package(OGRE 1.11 REQUIRED COMPONENTS Bites RTShaderSystem)
file(COPY ${OGRE_CONFIG_DIR}/resources.cfg DESTINATION ${CMAKE_BINARY_DIR})

add_executable(simple-ogre-project main.cpp)
target_link_libraries(simple-ogre-project ${OGRE_LIBRARIES})
