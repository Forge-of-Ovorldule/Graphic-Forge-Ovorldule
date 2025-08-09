cmake_minimum_required(VERSION 3.15)
project(GraphicForgeOvorldule LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Настройка выходных директорий
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Поиск зависимостей
find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)

# Библиотека GraphicForgeOvorldule
add_library(GraphicForgeOvorldule STATIC
    src/common/Window.cpp
)

target_include_directories(OvorlduleGraphics PUBLICf
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(OvorlduleGraphics
    OpenGL::GL
    glfw
)

# Пример приложения
add_executable(example examples/main.cpp)
target_link_libraries(example OvorlduleGraphics)