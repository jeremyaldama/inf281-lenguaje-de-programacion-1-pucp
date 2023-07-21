/* 
 * Archivo:   Urgencia.h
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 9 de diciembre de 2020, 11:03 PM
 */

#ifndef URGENCIA_H
#define URGENCIA_H
#include <fstream>
#include "Paciente.h"
using namespace std;

class Urgencia : public Paciente {
private:

    double porcSeguro;
    double porcUrgencia;

public:

    Urgencia();
    Urgencia(const Urgencia& orig);
    virtual ~Urgencia();

    void SetPorcUrgencia(double porcUrgencia);
    double GetPorcUrgencia() const;
    void SetPorcSeguro(double porcSeguro);
    double GetPorcSeguro() const;
    
    void operator = (const Urgencia& urg);
    
    int getPrioridad ();
    void lee (ifstream &arch);
    void imprime (ofstream &arch);
    
};
#endif /* URGENCIA_H */
