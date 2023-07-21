/* 
 * Archivo:   Paciente.h
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 9 de diciembre de 2020, 10:54 PM
 */

#ifndef PACIENTE_H
#define PACIENTE_H
#include <fstream>
using namespace std;

class Paciente {
private:

    int dni;
    char *nombre;
    char *codMed;

public:

    Paciente();
    Paciente(const Paciente& orig);
    virtual ~Paciente();
    
    void SetCodMed(const char* codM);
    void GetCodMed(char *codM) const;
    void SetNombre(const char* nomb);
    void GetNombre(char *nomb) const;
    void SetDni(int dni);
    int GetDni() const;
    
    void operator = (const Paciente &paciente);
    
    virtual int getPrioridad () = 0;
    virtual void lee (ifstream &arch) = 0;
    virtual void imprime (ofstream &arch) = 0;

};
#endif /* PACIENTE_H */
