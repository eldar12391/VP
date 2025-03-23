cmake_minimum_required(VERSION 3.10)
project(MusicCollectionSystem)

# Установка стандарта C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Исходные файлы
set(SOURCES
    main.cpp
    Models/User/User.cpp
    Models/Admin/Admin.cpp
    Models/User/RegularUser.cpp
    menu/CMenu.cpp
    menu/CMenuItem.cpp
    Auth/AuthSystem.cpp
)

# Заголовочные файлы
include_directories(
    Models/User
    Models/Admin
    menu
    Auth/
)

# Создание исполняемого файла
add_executable(${PROJECT_NAME} ${SOURCES})