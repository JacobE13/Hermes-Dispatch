cmake_minimum_required(VERSION 3.10)

project(HermesDispatch VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(dispatch2
    dispatch2.cpp
    firefighter.cpp
    police.cpp
    medical.cpp
)

target_sources(dispatch2 PRIVATE
    dispatch2.cpp
    firefighter.cpp
    police.cpp
    medical.cpp
)

# Link Dependencies (currently none)
# target_link_libraries(dispatch2 PRIVATE pthread)

target_include_directories(dispatch2 PRIVATE ${CMAKE_SOURCE_DIR}/include)
