all: program

program: main.o funciones_auxiliares.o
	g++  main.o funciones_auxiliares.o -o program

main.o: main.cpp funciones_auxiliares.h
	g++ -c main.cpp

funciones_auxiliares.o: funciones_auxiliares.cpp
	g++ -c funciones_auxiliares.cpp