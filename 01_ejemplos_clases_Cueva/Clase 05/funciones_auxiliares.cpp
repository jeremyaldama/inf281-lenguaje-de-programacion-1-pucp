#include <iostream>
#include <iomanip>
#include <fstream>
#include "funciones_auxiliares.h"
using namespace std;

void corta_especialidad(char *nom_doc, char *nom_esp, char *esp_min){
    int i = 0, j = 0, aux;
    while(nom_doc[i]) i++;

    while(nom_doc[i] != '_') i--;
    
    aux = i;
    i++;

    while(nom_doc[i]){
        if (nom_doc[i] <= 'z' && nom_doc[i] >= 'a')
            nom_esp[j] = nom_doc[i] - 'a' + 'A';
        else nom_esp[j] = nom_doc[i];

        esp_min[j++] = nom_doc[i++];
    }
    nom_doc[aux] = 0;
    esp_min[j] = 0;
    nom_esp[j] = 0;
 }

void imprime(ifstream &arch, ofstream &repo){
    int ddv, mmv, aav, dni, cant, cod_med, ddm, mmm, aam;
    char esp1[50], esp2[50], c,cod_doc[10], nom_doc[100], nomb_pac[50], nom_med[50];
    char nom_esp[50], esp_min[50];
    arch >> esp1 >> esp2 >> ddv >> c >> mmv >> c >> aav;

    while (1){
        arch >> dni;
        if (arch.eof()) break;
        if (arch.fail()){
            arch.clear();
            arch >> cod_doc >> nom_doc;
            corta_especialidad(nom_doc, nom_esp, esp_min);
            repo << left << setw(50) << nom_doc << setw(20) << cod_doc 
            << setw(20) << esp_min << endl;

        }
        else{
            arch >> nomb_pac >> cant;
            repo << left << setw(20) << dni << setw(50) << nomb_pac << endl;

            for (int i=0; i<cant; i++){
                arch >> cod_med >> nom_med >> ddm >> c >> mmm >> c >> aam;

                repo << setw(20) << cod_med << setw(50) << nom_med << endl;
            }
            repo << endl;
        }
    }
    
}