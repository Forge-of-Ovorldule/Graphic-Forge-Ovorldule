cmake_minimum_required(VERSION 3.10)
project(GraphSouls-Forge)

# Настройки компилятора
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Поиск пакетов
find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)

# Исполняемый файл
add_executable(${PROJECT_NAME} main.cpp ../src/GraphicsEngine.cpp)

# Подключение библиотек
target_link_libraries(${PROJECT_NAME}
    PRIVATE
    Vulkan::Vulkan
    glfw
)