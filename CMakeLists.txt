cmake_minimum_required(VERSION 3.16)
project(CppCalculator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_executable(calculator
  src/main.cpp
  src/GuiApp.cpp
  src/Calculator.cpp
)

target_link_libraries(calculator PRIVATE Qt6::Widgets)
