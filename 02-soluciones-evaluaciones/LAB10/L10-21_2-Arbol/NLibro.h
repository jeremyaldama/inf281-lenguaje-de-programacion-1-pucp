/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   NLibro.h
 * Author: Danie
 *
 * Created on 23 de junio de 2023, 23:31
 */

#ifndef NLIBRO_H
#define NLIBRO_H
#include "Libro.h"
#include "ALibro.h"

class NLibro {
public:
    NLibro();
    friend class ALibro;
private:
    class Libro dlibro;
    class NLibro *izq;
    class NLibro *der;
};

#endif /* NLIBRO_H */

