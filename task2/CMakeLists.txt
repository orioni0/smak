# Минимальная версия CMake
cmake_minimum_required(VERSION 3.20)

# Название проекта и указание языка C
project(ASCII_Tetris LANGUAGES C)

# Установить стандарт C (например, C11)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Указать исходные файлы и создать исполняемый файл
add_executable(ASCII_Tetris main.c tetris.c)

# Если заголовочные файлы находятся в отдельной папке (например, include), добавь директорию
# target_include_directories(ASCII_Tetris PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(ASCII_Tetris PUBLIC ${PROJECT_SOURCE_DIR})

# В данном случае, если заголовочные файлы в одной папке с исходными файлами, дополнительных действий не требуется
