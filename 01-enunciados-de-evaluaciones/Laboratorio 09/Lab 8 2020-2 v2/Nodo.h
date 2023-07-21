/* 
 * Archivo:   Nodo.h
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 9 de diciembre de 2020, 03:44 AM
 */

#ifndef NODO_H
#define NODO_H
#include <fstream>
#include "Paciente.h"
using namespace std;

class Nodo {
private:

    Paciente *paciente;
    Nodo *next;

public:

    Nodo();
    virtual ~Nodo();
    friend class Lista;

};
#endif /* NODO_H */
