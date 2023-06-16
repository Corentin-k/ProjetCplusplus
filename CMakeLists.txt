cmake_minimum_required(VERSION 3.25)
project(Documents)

set(CMAKE_CXX_STANDARD 23)


add_executable(Documents main.cpp  personnage.cpp personnage.h ennemis.cpp ennemis.h)
