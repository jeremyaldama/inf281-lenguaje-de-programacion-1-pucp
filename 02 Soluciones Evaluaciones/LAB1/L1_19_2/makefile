# objetivo: dependencias
#	instrucciones

program: main.o FuncionesAuxiliares.o
	g++ main.o FuncionesAuxiliares.o -o program

main.o: main.cpp FuncionesAuxiliares.h
	g++ -c main.cpp

FuncionesAuxiliares.o: FuncionesAuxiliares.cpp
	g++ -c FuncionesAuxiliares.cpp

clean:
	rm -f program.exe *.o