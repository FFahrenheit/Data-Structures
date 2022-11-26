cmake_minimum_required(VERSION 3.17)
project(Tienda)

set(CMAKE_CXX_STANDARD 14)

add_executable(Tienda main.cpp Producto.cpp Producto.h ListaEstatica.h Algoritmos.h Tienda.cpp Tienda.h)