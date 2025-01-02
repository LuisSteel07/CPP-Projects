cmake_minimum_required(VERSION 3.31)
project(Departamentos)

set(CMAKE_C_STANDARD 11)

add_executable(Departamentos main.c
        Interfaz.h
        Interfaz.c
        Logica.h
        Logica.c)
