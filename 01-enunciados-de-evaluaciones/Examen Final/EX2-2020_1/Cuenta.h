/* 
 * Archivo:   Cuenta.h
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 14 de diciembre de 2020, 01:07 AM
 */

#ifndef CUENTA_H
#define CUENTA_H
#include <fstream>
using namespace std;

class Cuenta {
private:

    int codigo;
    char *cliente;
    double saldo;
    char *estado;

public:

    Cuenta();
    Cuenta(const Cuenta& orig);
    virtual ~Cuenta();
    
    void SetEstado(const char* p_estado);
    void GetEstado(char *p_estado) const;
    void SetSaldo(double saldo);
    double GetSaldo() const;
    void SetCliente(const char* nombre);
    void GetCliente(char *nombre) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    
    void operator = (const Cuenta& orig);
    void operator += (double valor);
    bool operator > (const Cuenta& orig);
    bool operator > (int valor);
    bool operator == (int valor);

};

ifstream& operator >> (ifstream& arch, Cuenta &cuenta);
ofstream& operator << (ofstream& arch, Cuenta &cuenta);

#endif /* CUENTA_H */
