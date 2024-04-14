cmake_minimum_required(VERSION 3.27)
project(lab4oop)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab4oop FruitApp.cpp
        FruitApp.h
        FruitUI.cpp
        FruitUI.h
        FruitController.cpp
        FruitController.h
        FruitRepo.cpp
        FruitRepo.h
        Fruit.cpp
        Fruit.h)
