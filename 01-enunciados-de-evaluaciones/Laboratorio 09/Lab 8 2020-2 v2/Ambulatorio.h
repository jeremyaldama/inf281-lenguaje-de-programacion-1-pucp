/* 
 * Archivo:   Ambulatorio.h
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 9 de diciembre de 2020, 10:59 PM
 */

#ifndef AMBULATORIO_H
#define AMBULATORIO_H
#include <fstream>
#include "Paciente.h"
using namespace std;

class Ambulatorio : public Paciente {
private:

    double PorcSeguro;

public:

    Ambulatorio();
    Ambulatorio(const Ambulatorio& orig);
    virtual ~Ambulatorio();

    void SetPorcSeguro(double PorcSeguro);
    double GetPorcSeguro() const;
    
    void operator = (const Ambulatorio& amb);
    
    int getPrioridad ();
    void lee (ifstream &arch);
    void imprime (ofstream &arch);
    
};
#endif /* AMBULATORIO_H */
