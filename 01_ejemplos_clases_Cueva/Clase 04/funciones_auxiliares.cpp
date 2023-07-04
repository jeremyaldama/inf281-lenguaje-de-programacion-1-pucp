#include <iostream>
#include <iomanip>
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