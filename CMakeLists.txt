cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -fsanitize=address,undefined -fno-omit-frame-pointer")
file(GLOB TARGET_SRC "./src/*.cpp")

include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

add_executable(main ${TARGET_SRC})