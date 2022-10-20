cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)
set(CMAKE_CXX_STANDARD 20)
set(PROJECT_NAME NokiaLCD)

set(${PROJECT_NAME}_BOARD uno)
project(${PROJECT_NAME})

set(${PROJECT_NAME}_SRCS src/NokiaLCD.cpp src/cursor/Cursor.cpp src/print/Pr.cpp)
set(${PROJECT_NAME}_HDRS src/NokiaLCD.h)


generate_arduino_firmware(${PROJECT_NAME})

print_board_list()
print_programmer_list()
