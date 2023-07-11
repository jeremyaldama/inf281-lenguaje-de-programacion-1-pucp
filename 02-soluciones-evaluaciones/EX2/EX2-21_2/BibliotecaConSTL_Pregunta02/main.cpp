/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Danie
 *
 * Created on 9 de julio de 2023, 17:41
 */
// JEREMY DANIEL ALDAMA GIRALDO 20206228
// SE TRABAJARA TODO CON VECTORS
#include <cstdlib>
#include "Biblioteca.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    class Biblioteca biblioteca;
    biblioteca.leeLibros("Libros.csv");
    biblioteca.imprimeLibros("ReporteLibrosInicial.txt");
    biblioteca.leerUsuarios("Usuarios.csv");
    biblioteca.imprimeUsuarios("ReporteUsuariosInicial.txt");
    biblioteca.leerPrestamos("RegistroDePrestamos.csv");
    biblioteca.imprimeUsuarios("ReporteUsuariosFinal.txt");
    biblioteca.imprimeLibros("ReporteLibrosFinal.txt");
    biblioteca.imprimeSuspendidos("ReporteSuspendidos.txt", 19, 10, 2021);
    return 0;
}

