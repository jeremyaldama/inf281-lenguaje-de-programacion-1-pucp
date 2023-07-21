/* 
 * Archivo:   Ambulatorio.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 9 de diciembre de 2020, 10:59 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Ambulatorio.h"

Ambulatorio::Ambulatorio() {

}

Ambulatorio::Ambulatorio(const Ambulatorio& orig) {
    *this = orig;
}

Ambulatorio::~Ambulatorio() {

}

void Ambulatorio::SetPorcSeguro(double PorcSeguro) {
    this->PorcSeguro = PorcSeguro;
}

double Ambulatorio::GetPorcSeguro() const {
    return PorcSeguro;
}

void Ambulatorio::operator=(const Ambulatorio& amb) {
    char nomb[60], codM[10];
    this->SetDni(amb.GetDni());
    this->SetPorcSeguro(amb.GetPorcSeguro());
    amb.GetNombre(nomb);
    amb.GetCodMed(codM);
    this->SetNombre(nomb);
    this->SetCodMed(codM);
}

int Ambulatorio::getPrioridad() {
    return 3;
}

void Ambulatorio::imprime(ofstream& arch) {
    char nomb[60], codM[10];
    this->GetNombre(nomb);
    this->GetCodMed(codM);
    arch << setw(10) << this->GetDni()
            << setw(5) << " "
            << left << setw(45) << nomb
            << right << setw(10) << codM
            << setw(15) << PorcSeguro << endl;
}

void Ambulatorio::lee(ifstream& arch) {
    double porcSeg;
    char codM[10];
    arch.getline(codM,10,',');
    if (arch.eof()) return;
    arch >> porcSeg; arch.get(); 
    this->SetCodMed(codM);
    this->SetPorcSeguro(porcSeg);
}