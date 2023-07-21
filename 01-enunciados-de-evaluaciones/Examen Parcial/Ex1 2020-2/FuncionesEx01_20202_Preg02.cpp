/* 
 * Archivo:   FuncionesEx01_20202_Preg02.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 27 de octubre de 2020, 08:04 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "FuncionesEx01_20202_Preg02.h"
#define INCREMENTO 5
using namespace std;

void imprimeLinea (char car, int num, ofstream &arch) {
    for (int i = 0; i < num; i++) arch.put(car);
    arch << endl;
}

ifstream abrirArchL (const char *nombre) {
    ifstream arch;
    arch.open(nombre, ios::in);
    if (!arch) {
        cout << "ERROR: no se pudo abrir el archivo " << nombre << endl;
        exit(1);
    }
    return arch;
} 

ofstream abrirArchE (const char *nombre) {
    ofstream arch;
    arch.open(nombre, ios::out);
    if (!arch) {
        cout << "ERROR: no se pudo abrir el archivo " << nombre << endl;
        exit(1);
    }
    return arch;
} 

char * leeCadena (ifstream &arch, char car) {
    char buff[200], *cad;
    arch.getline(buff,200,car);
    if (arch.eof()) return nullptr;
    cad = new char [strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

char * asignaCadenaExacta (char *cadena){
    int len;
    char *cad;
    len = strlen(cadena);
    cad = new char[len+1];
    strcpy(cad,cadena);
    return cad;
}

void leerDatos (char **&clientes, int ***&intProductos, char ***&strProductos) {
    ifstream arch = abrirArchL("pedidos.csv");
    int cap = 0, numClientes = 0, codC, codP, cant, pos, ind, numP[20] = {0}, 
            capP[20] = {0};
    char *nombreC, car, fecha[15], *nombreP;
    clientes = nullptr;
    while (1) {
        arch >> codC;
        if (arch.eof()) break;
        arch >> car;
        nombreC = leeCadena(arch,',');
        if (cap == numClientes) 
            incrementarEspaciosClientes(clientes,intProductos,strProductos,numClientes,cap);
        clientes[numClientes-1] = nombreC; clientes[numClientes] = nullptr;
        numClientes++; pos = numClientes-2;
        while (arch.get() != '\n') {
            arch.getline(fecha,15,',');
            arch >> codP >> car;
            nombreP = leeCadena(arch,',');
            arch >> cant;
            if (capP[pos] == numP[pos])
                incrementarEspaciosCliente(intProductos[pos],strProductos[pos],
                        numP[pos],capP[pos]);
            ind = buscarProducto(intProductos[pos],codP,numP[pos]);
            if (ind == -1) {
                agregarProducto(intProductos[pos],strProductos[pos],codP,nombreP,cant,numP[pos]);
            } else {
                intProductos[pos][ind][1] += cant;
            }
        }
    }
}
void incrementarEspaciosClientes (char **&clientes, int ***&intProductos, 
        char ***&strProductos, int &numClientes, int &cap) {
    char **auxC, ***auxP;
    int ***auxPi;
    cap += INCREMENTO;
    if (clientes == nullptr) {
        clientes = new char *[cap];
        intProductos = new int **[cap];
        strProductos = new char **[cap];
        clientes[0] = nullptr; intProductos[0] = nullptr; strProductos[0] = nullptr;
        numClientes = 1;
    } else {
        auxC = new char *[cap];
        auxPi = new int **[cap];
        auxP = new char **[cap];
        for (int i = 0; i < numClientes; i++) {
            auxC[i] = clientes[i];
            auxPi[i] = intProductos[i];
            auxP[i] = strProductos[i];
        }
        delete clientes; delete intProductos; delete strProductos;
        clientes = auxC;
        intProductos = auxPi;
        strProductos = auxP;
    }
}

void incrementarEspaciosCliente(int **&intProductos, char **&strProductos, 
        int &numP, int &cap) {
    int **auxi;
    char **auxs;
    cap += INCREMENTO;
    if (numP == 0) {
        intProductos = new int *[cap];
        strProductos = new char *[cap];
        intProductos[0] = nullptr; strProductos[0] = nullptr;
        numP = 1;
    } else {
        auxi = new int *[cap];
        auxs = new char *[cap];
        for (int i = 0; i < numP; i++) {
            auxi[i] = intProductos[i];
            auxs[i] = strProductos[i];
        }
        delete intProductos; delete strProductos;
        intProductos = auxi;
        strProductos = auxs;
    }
}

int buscarProducto (int **intProductos, int codP, int numP) {
    for (int i = 0; i < numP-1; i++) {
        if (intProductos[i][0] == codP) return i;
    }
    return -1;
}

void agregarProducto (int **&intProductos, char **&strProductos, int codP, 
        char *nombP, int cant, int &numP) {
    int *infoP;
    infoP = new int [2];
    infoP[0] = codP;
    infoP[1] = cant;
    intProductos[numP-1] = infoP;
    intProductos[numP] = nullptr;
    strProductos[numP-1] = nombP;
    strProductos[numP] = nullptr;
    numP++;
}

void imprimirDatos (char **clientes, int ***intProductos, char ***strProductos) {
    ofstream arch = abrirArchE("ReporteDeAtencion.txt");
    ordenarPedidos(clientes,intProductos,strProductos);
    arch << setw(60) << "REPORTE DE ATENCION" << endl;
    for (int i = 0; clientes[i] ; i++) {
        arch << "Cliente: " << clientes[i] << endl;
        imprimeLinea('=',100,arch);
        arch << setw(15) << "Cod. Producto"
                << setw(20) << "Producto"
                << setw(55) << "Cant. Solicitada" << endl;
        imprimeLinea('=',100,arch);
        for (int j = 0; intProductos[i][j]; j++) {
            arch << setw(12) << intProductos[i][j][0]
                    << setw(10) << " "
                    << left << setw(50) << strProductos[i][j]
                    << right << setw(15) << intProductos[i][j][1] << endl;
        }
        arch << endl;
    }
}

void ordenarPedidos (char **clientes, int ***intProductos, char ***strProductos) {
    int numPedidos;
    for (int i = 0; clientes[i] ; i++) {
        for (numPedidos = 0; intProductos[i][numPedidos] ; numPedidos++);
        ordenar(intProductos[i],strProductos[i],0,numPedidos-1);
    }
}

void ordenar (int **intProductos, char **strProductos, int izq, int der) {
    int limite;
    if (izq >= der) return;
    cambiarINT(intProductos,izq,(izq+der)/2);
    cambiarSTR(strProductos,izq,(izq+der)/2);
    limite = izq;
    for (int i = izq; i <= der; i++) {
        if (intProductos[i][1] > intProductos[izq][1]) {
            cambiarINT(intProductos,++limite,i);
            cambiarSTR(strProductos,limite,i);
        }
    }
    cambiarINT(intProductos,izq,limite);
    cambiarSTR(strProductos,izq,limite);
    ordenar(intProductos,strProductos,izq,limite-1);
    ordenar(intProductos,strProductos,limite+1,der);
}

void cambiarINT (int **num, int i, int k) {
    int *auxINT;
    auxINT = num[i];
    num[i] = num[k];
    num[k] = auxINT;
}

void cambiarSTR (char **str, int i, int k) {
    char *auxSTR;
    auxSTR = str[i];
    str[i] = str[k];
    str[k] = auxSTR;
}