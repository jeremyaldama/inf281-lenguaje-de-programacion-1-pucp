/* 
 * Archivo:   Medico.h
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 26 de noviembre de 2020, 12:15 AM
 */

#ifndef MEDICO_H
#define MEDICO_H
#include <fstream>
#include "Paciente.h"
using namespace std;

class Medico {
private:

    char *codigo;
    char *nombre;
    char *especialidad;
    double tarifa;
    Paciente pacientes[100];
    int numPac;
    double ingresosPac;
    double ingresosS;

public:

    Medico();
    Medico(const Medico& orig);
    ~Medico();
    
    void SetIngresosS(double inresosS);
    double GetIngresosS() const;
    void SetIngresosPac(double ingresosPac);
    double GetIngresosPac() const;
    void SetNumPac(int numPac);
    int GetNumPac() const;
    void SetTarifa(double tarifa);
    double GetTarifa() const;
    
    void SetEspecialidad(const char* pespecialidad);
    void GetEspecialidad(char *pespecialidad) const;
    void SetNombre(const char* pnombre);
    void GetNombre(char *pnombre) const;
    void SetCodigo(const char* pcodigo);
    void GetCodigo(char *pcodigo) const;
    
    void operator + (const Paciente& pac);
    void operator + (int pfecha);
    void operator - (int pfecha);
    void operator / (int pfecha);
    void operator ++();
    void printPacientesAtendidos (ofstream &);
    void printPacientesPorAtender (ofstream &);
    
};

ifstream& operator >> (ifstream& in, Medico &medico);
ofstream& operator << (ofstream& out, Medico &medico);

#endif /* MEDICO_H */
