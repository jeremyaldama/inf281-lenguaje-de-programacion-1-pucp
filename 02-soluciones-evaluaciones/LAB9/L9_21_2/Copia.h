/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Copia.h
 * Author: Danie
 *
 * Created on 22 de junio de 2023, 0:50
 */

#ifndef COPIA_H
#define COPIA_H
#include "Libro.h"
#include "Disponible.h"
#include "Perdida.h"
#include "Prestamo.h"

class Copia {
public:
    Copia();
    Copia(const Copia& orig);
    virtual ~Copia();
    void SetEstado(const char* estado);
    void GetEstado(char*) const;
    void SetNumero(int numero);
    int GetNumero() const;
    void AsignaCopia(const char*codigo, const char*descrip, const char*autor, 
                    int aa, int cantidad, double precio, int zona, int);
    void ObtenerCodigo(char*);
    void Actualiza(const char*, int, int, int);
    void ImprimirCopia(ofstream&arch);
    int ObtenerCantidad();
    int fin();
    void imprimirCabecera(ofstream&arch);
private:
    int numero;
    // "Disponible", "Prestamo", "Perdida"
    char *estado;
    class Libro *Olibro;
};

#endif /* COPIA_H */

