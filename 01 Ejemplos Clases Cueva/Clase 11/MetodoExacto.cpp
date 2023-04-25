/* 
 * File:   MetodoExacto.cpp
 * Author: Jeremy Aldama 20206228
 * 
 * Created on 25 de abril de 2023, 9:06
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "MetodoExacto.h"

using namespace std;

void leercadena(ifstream &arch, char*&cad){
    char buff[200];
    arch.getline(buff, 200, ',');
    int len = strlen(buff);
    cad = new char[len+1];
    strcpy(cad, buff);
}

void cargaclientes(int *&cli_dni, char **&cli_nombre, char *&cli_categoria){
    ifstream arch("Clientes.csv", ios::in);
    if(!arch){
        cout << "NO SE PUDO ABRIR CLIENTES";
        exit(1);
    }
    
    int auxdni[100], cont=0;
    char *auxnombre[100], auxcate[100], *cad, temp[100];
    while(1){
        arch >> auxdni[cont];
        if (arch.eof()) break;
        arch.get();
        leercadena(arch, cad);
        int tam = strlen(cad);
        if (cad[tam-2]==' '){
            auxcate[cont] = cad[tam-1];
            cad[tam-2] = 0;
        }
        else{
            auxcate[cont] = '-';
        }
        auxnombre[cont] = cad;
        arch.getline(temp, 100);
        cont++;
    }
    auxdni[cont] = -1;
    cont++;
    
    cli_dni = new int[cont];
    cli_nombre = new char*[cont];
    cli_categoria = new char[cont];
    
    for (int i=0; i<cont-1; i++){
        cli_dni[i] = auxdni[i];
        cli_nombre[i] = auxnombre[i];
        cli_categoria[i] = auxcate[i];
    }
}