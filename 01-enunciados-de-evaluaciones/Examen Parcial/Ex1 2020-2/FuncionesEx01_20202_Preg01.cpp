/* 
 * Archivo:   FuncionesEx01_20202_Preg01.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 27 de octubre de 2020, 09:02 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "FuncionesEx01_20202_Preg01.h"
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

enum pedido {FECHA,RUC,CODP,NOMBP,CANTS,CANTA};

void leerDatos (void *&pedidos, void *&stock) {
    ifstream archP = abrirArchL("pedidos.csv");
    ifstream archS = abrirArchL("stock.csv");
    ofstream archR1 = abrirArchE("ReportePedidos1.txt");
    ofstream archR2 = abrirArchE("ReporteStock1.txt");
    leerPedidos(pedidos,archP);
    leerStock(stock,archS);
    imprimirPedidos(pedidos,archR1);
    imprimirStock(stock,archR2);
}

void leerPedidos (void *&pedidos, ifstream &arch) {
    void *buffP[200], **pedido, *ped;
    int codC, dd, mm, aa, codP, cant, numPed = 0;
    char car, nombreC[60], *nombreP;
    while (1) {
        arch >> codC;
        if (arch.eof()) break;
        arch >> car;
        arch.getline(nombreC,60,',');
        while (1) {
            arch >> aa >> car >> mm >> car >> dd >> car >> codP >> car;
            nombreP = leeCadena(arch,',');
            arch >> cant;
            ped = asignarInfoPedido(codC,aa*10000+mm*100+dd,codP,nombreP,cant,arch);
            buffP[numPed] = ped;
            numPed++;
            if (arch.get() == '\n') break;
        }       
    }
    buffP[numPed] = nullptr; numPed++;
    pedido = new void *[numPed];
    for (int i = 0; i < numPed; i++) pedido[i] = buffP[i];
    pedidos = pedido;
} 

void * asignarInfoPedido (int codC, int fecha, int codP, char *nombreP, int cant, 
        ifstream &arch) {
    void **pedido;
    int *ruc, *fechaAMD, *codProd, *cantS, *cantA;
    ruc =  new int; *ruc = codC;
    fechaAMD =  new int; *fechaAMD = fecha;
    codProd =  new int; *codProd = codP;
    cantS =  new int; *cantS = cant;
    cantA =  new int; *cantA = 0;
    pedido = new void *[6];
    pedido[FECHA] = fechaAMD;
    pedido[RUC] = ruc;
    pedido[CODP] = codProd;
    pedido[NOMBP] = nombreP;
    pedido[CANTS] = cantS;
    pedido[CANTA] = cantA;
    return pedido;
}

void leerStock (void *&stock, ifstream &arch) {
    void *buffS[100], *s, **st;
    int cant = 0;
    while (1) {
        s = leerSt(arch);
        if (s == nullptr) break;
        buffS[cant] = s;
        cant++;
    }
    buffS[cant] = nullptr; cant++;
    st = new void *[cant];
    for (int i = 0; i < cant; i++) {
        st[i] = buffS[i];
    }
    stock = st;
}

void * leerSt (ifstream &arch) {
    int codP, s;
    char car;
    int *codProd, *st;
    void **stock;
    arch >> codP;
    if (arch.eof()) return nullptr;
    arch >> car >> s;
    codProd = new int; *codProd = codP;
    st = new int; *st = s;
    stock = new void *[2];
    stock[0] = codProd;
    stock[1] = st;
    return stock;
}

void imprimirPedidos (void *pedidos, ofstream &arch) {
    arch << "RUC" << setw(25) << "Fecha" << setw(15) << "Cod. Producto"
            << setw(25) << "Producto" << setw(45) << "Cant. solicitada"
            << setw(18) << "Cant. Atendida" << endl;
    imprimeLinea('=',130,arch);
    void **pedido = (void **)pedidos;
    for (int i = 0; pedido[i] ; i++) {
        imprimePedido(pedido[i],arch);
    }
}

void imprimePedido (void *ped, ofstream &arch) {
    void **pedido = (void **)ped;
    int *ruc = (int *)pedido[RUC];
    int *fecha = (int *)pedido[FECHA];
    int *codP = (int *)pedido[CODP];
    char *nombP = (char *)pedido[NOMBP];
    int *cantS = (int *)pedido[CANTS];
    int *cantA = (int *)pedido[CANTA];
    
    int f = (*fecha);
    int aa = f/10000;
    f = f%10000;
    int mm = f/100;
    int dd = f%100;
    arch << setw(10) << *ruc << setw(10) << " ";
    arch.fill('0');
    arch << aa << '/' << setw(2) << mm << '/' << setw(2) << dd;
    arch.fill(' ');
    arch << setw(10) << *codP
            << setw(10) << " "
            << left << setw(55) << nombP
            << right << setw(10) << *cantS
            << setw(10) << *cantA << endl;
}

void imprimirStock (void *stock, ofstream &arch) {
    arch << setw(20) << "CODIGO PRODUCTO" << setw(20) << "CANTIDAD DISP." << endl;
    imprimeLinea('=',45,arch);
    void **st = (void **)stock;
    for (int i = 0; st[i] ; i++) {
        imprimeStock(st[i],arch);
    }
}

void imprimeStock (void *st, ofstream &arch) {
    void **stock = (void **)st;
    int *cod = (int *)stock[0];
    int *cant = (int *)stock[1];
    
    arch << setw(12) << *cod << setw(20) << *cant << endl;
}

void atiende (void *pedidos, void *stock) {
    ofstream archR1 = abrirArchE("ReportePedidos2.txt");
    ofstream archR2 = abrirArchE("ReporteStock2.txt");
    ordenarPedidos(pedidos,1);
    void **pedido = (void **)pedidos;
    for (int i = 0; pedido[i] ; i++) {
        atenderPedido(pedido[i],stock);
    }
    imprimirPedidos(pedidos,archR1);
    imprimirStock(stock,archR2);
}

void ordenarPedidos (void *pedidos, int opc) {
    int cant = 0;
    void **pedido = (void **)pedidos;
    for (cant = 0; pedido[cant] ; cant++);
    qsortPedidos(pedido,0,cant-1,opc);
}

void qsortPedidos (void **pedidos, int izq, int der, int opc) {
    int limite;
    if (izq >= der) return;
    cambiar (pedidos[izq],pedidos[(izq+der)/2]);
    limite = izq;
    for (int i = izq+1; i <= der ; i++) {
        if (comparar(pedidos[i],pedidos[izq],opc) < 0) {
            cambiar(pedidos[++limite],pedidos[i]);
        }
    }
    cambiar(pedidos[izq],pedidos[limite]);
    qsortPedidos(pedidos,izq,limite-1,opc);
    qsortPedidos(pedidos,limite+1,der,opc);
}

void cambiar (void *&p1, void *&p2) {
    void *aux;
    aux = p1;
    p1 = p2;
    p2 = aux;
}

int comparar (void *p1, void *p2, int opc) {
    void **user1 = (void **)p1;
    void **user2 = (void **)p2;
    if (opc == 1) {      
        int *fecha1 = (int *)user1[FECHA];
        int *fecha2 = (int *)user2[FECHA];
        return (*fecha1) - (*fecha2);
    } else {       
        int *ruc1 = (int *)user1[RUC];
        int *ruc2 = (int *)user2[RUC];
        return (*ruc1) - (*ruc2);
    }  
}

void atenderPedido (void *ped, void *stock) {
    void **pedido = (void **)ped;
    int *codP = (int *)pedido[CODP];
    int *cantS = (int *)pedido[CANTS];
    int *cantA = (int *)pedido[CANTA];
    int despacho = actualizarStock(*codP,*cantS,stock);
    (*cantA) = despacho;
}

int actualizarStock (int codP, int cant, void *stock) {
    void **st = (void **)stock;
    int devuelve;
    for (int i = 0; st[i]; i++) {
        void **S = (void **)st[i];
        int *cod = (int *)S[0];
        int *ss = (int *)S[1];
        if (codP == *cod) {
            if ((*ss)-cant >= 0) {              
                devuelve = cant;
                (*ss) = (*ss)-cant;
            } else {
                devuelve = (*ss);
                (*ss) = 0;
            }
            return devuelve;
        }
    }
}

void imprimirDatos (void *pedidos) {
    ofstream arch = abrirArchE("ReporteFinal.txt");
    ordenarPedidos(pedidos,2);
    void **pedido = (void **)pedidos;
    int rucAnt = -1;
    for (int i = 0; pedido[i] ; i++) {
        void **ped = (void **)pedido[i];
        int *ruc = (int *)ped[RUC];
        int *fecha = (int *)ped[FECHA];
        int *codP = (int *)ped[CODP];
        char *nombP = (char *)ped[NOMBP];
        int *cantS = (int *)ped[CANTS];
        int *cantA = (int *)ped[CANTA];
        if (rucAnt == -1 || (*ruc) != rucAnt) {
            arch << endl << "RUC: " << *ruc << endl;
            imprimeLinea('=',130,arch);
            arch << "  Fecha" << setw(25) << "Cod. Producto"
                << setw(25) << "Producto" << setw(50) << "Cant. solicitada"
                << setw(20) << "Cant. Atendida" << endl;
            imprimeLinea('=',130,arch);
            rucAnt = *ruc;
        } 
        imprimePedidoF(*ruc,*fecha,*codP,nombP,*cantS,*cantA,arch);
    }
}

void imprimePedidoF (int ruc, int fecha, int codP, char *nombP, int cantS, int cantA,
        ofstream &arch) {
    int f = fecha;
    int aa = f/10000;
    f = f%10000;
    int mm = f/100;
    int dd = f%100;
    arch << setw(5) << " ";
    arch.fill('0');
    arch << aa << '/' << setw(2) << mm << '/' << setw(2) << dd;
    arch.fill(' ');
    arch << setw(10) << codP
            << setw(10) << " "
            << left << setw(55) << nombP
            << right << setw(10) << cantS
            << setw(15) << cantA << endl;
}