cmake_minimum_required(VERSION 3.10)
project(MOD12)

# Принудительно установить стандарт c++ 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Для MinGW в Windows
# Решает проблему с локализацией
if(MINGW)
    add_compile_options(-finput-charset=UTF-8 -fexec-charset=UTF-8)
endif()

# Если Линукс Решает проблему с локализацией
if(UNIX AND NOT APPLE)
    add_definitions(-DSET_GLOBAL_LOCALE_LINUX)
endif()


# Добавить исходники
add_executable(MOD12 
src/main.cpp
)
