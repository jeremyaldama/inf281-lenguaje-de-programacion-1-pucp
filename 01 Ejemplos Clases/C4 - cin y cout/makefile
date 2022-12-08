all: Clase04

Clase04: main.o FuncionesAuxiliares.o
	g++ -o Clase04 main.o FuncionesAuxiliares.o

main.o: main.cpp FuncionesAuxiliares.h
	g++ -c main.cpp

FuncionesAuxiliares.o: FuncionesAuxiliares.cpp
	g++ -c FuncionesAuxiliares.cpp

clean:
	-rm main.o FuncionesAuxiliares.o