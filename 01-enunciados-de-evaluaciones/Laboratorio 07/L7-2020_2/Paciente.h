/* 
 * Archivo:   Paciente.h
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 27 de noviembre de 2020, 08:03 AM
 */

#ifndef PACIENTE_H
#define PACIENTE_H
#include <fstream>
using namespace std;

class Paciente {
private:

    int fecha; 
    int codigo;
    char *nombre;
    double prima; 
    char estado;

public:

    Paciente();
    Paciente(const Paciente& orig);
    ~Paciente();
    void SetEstado(char estado);
    char GetEstado() const;
    void SetPrima(double prima);
    double GetPrima() const;
    void SetNombre(const char* pnombre);
    void GetNombre(char *pnombre) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    
};

ifstream& operator >> (ifstream& in, Paciente &paciente);

#endif /* PACIENTE_H */
