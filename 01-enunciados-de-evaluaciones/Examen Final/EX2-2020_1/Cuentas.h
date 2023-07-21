/* 
 * Archivo:   Cuentas.h
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 14 de diciembre de 2020, 12:17 PM
 */

#ifndef CUENTAS_H
#define CUENTAS_H
#include <fstream>
using namespace std;
#include "ArbolBBG.h"
#include "Cuenta.h"
#include "Moneda.h"
#include <map>
#include <iterator>

class Cuentas {
private:

    ArbolBBG<class Cuenta> arbClientes;
    map<char,class Moneda> monedas;

public:

    Cuentas();
    virtual ~Cuentas();
    
    void leerCuentas (const char *nombArch);
    void leerTiposDeCambio (const char *nombArch);
    void ejecutarMovimientos (const char *nombArch);
    void reporteDeCuentas (const char *nombArch, char car);

};
#endif /* CUENTAS_H */
