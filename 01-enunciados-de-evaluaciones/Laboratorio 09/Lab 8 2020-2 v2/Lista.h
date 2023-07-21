/* 
 * Archivo:   Lista.h
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 9 de diciembre de 2020, 11:42 PM
 */

#ifndef LISTA_H
#define LISTA_H
#include <fstream>
#include "Nodo.h"

using namespace std;

#include "Ambulatorio.h"
#include "Emergencia.h"
#include "Urgencia.h"

class Lista {
private:

    Nodo *lista;

public:

    Lista();
    virtual ~Lista();
    void crear (const char *nombArch);
    void insertar (Paciente *& dato);
    void imprimir (const char *nombArch);

};

void imprimeLinea (char car, int num, ofstream &arch);

#endif /* LISTA_H */
