/* 
 * Archivo:   Medico.h
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 27 de noviembre de 2020, 08:03 AM
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
    int fechas[100];
    int pacientes[100];
    double prima[100];
    char estado[100];
    int numPac;
    double ingresosPac;
    double ingresosS;

public:

    Medico();
    Medico(const Medico& orig);
    ~Medico();
    void SetIngresosS(double ingresosS);
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
    void operator * (int pfecha);
    void operator - (int pfecha);
    void operator ++();
    
    void SetEstado(char estado, int pos);  
    char GetEstado(int pos) const;
    void SetPrima(double prima, int pos);
    double GetPrima(int pos) const;
    void SetPacientes(int paciente, int pos);
    int GetPacientes(int pos) const;
    void SetFechas(int fecha, int pos);
    int GetFechas(int pos) const;
    
};

ifstream& operator >> (ifstream& in, Medico &medico);
ofstream& operator << (ofstream& out, Medico &medico);
void imprimeLinea (char , int , ofstream &);
void imprimirPacientesAtendidos(Medico &medico, ofstream& out);
void imprimirPacientesPorAtender(Medico &medico, ofstream& out);

#endif /* MEDICO_H */
