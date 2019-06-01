cmake_minimum_required(VERSION 3.14)
project(dushi-cli)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-fPIC")

file(GLOB SOURCE_FILES
        "src/dushi.h"
        "src/dushi.cpp"
        "dushi-cli.cpp"
)

add_executable(dushi-cli ${SOURCE_FILES})

target_include_directories(dushi-cli PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        )
target_link_libraries(dushi-cli ${PYTHON_LIBRARIES})
