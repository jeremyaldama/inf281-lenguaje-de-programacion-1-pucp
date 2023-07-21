/* 
 * Archivo:   FuncionesLaboratorio07.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 11 de noviembre de 2020, 11:49 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "FuncionesLaboratorio07.h"
using namespace std;

/************************ Funciones Auxiliares ************************/

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

/******************** Funciones de lectura e impresion **********************/

enum Reg {PRODUCTO,PALET,STOCK};

void * leeRegistro (ifstream &arch) {
    /* declaracion de variables */
    int *stock;
    char *palet, *producto;
    void **registro;
    /* lectura de datos*/
    producto = leeCadena(arch,';');
    if (producto == nullptr) return nullptr;
    palet = leeCadena(arch,';'); 
    stock = new int; arch >> *stock; arch.get();
    /* creacion del registro */
    registro = new void *[3];
    registro[PRODUCTO] = producto;
    registro[PALET] = palet;
    registro[STOCK] = stock;
    return registro;
}

int comparar (const void *parametro1, const void *parametro2) {
    void **p1 = (void **)parametro1;
    void **p2 = (void **)parametro2;
    /* sacar datos tipo char a comparar */
    char *dato1 = (char *)p1[PRODUCTO];
    char *dato2 = (char *)p2[PRODUCTO];
    return strcmp(dato1,dato2);
}

void imprimeRegistro (ofstream &arch, void *reg) {
    /* declaracion de variables */
    void **registro = (void **)reg;
    char *producto = (char *)registro[PRODUCTO];
    char *palet = (char *)registro[PALET];
    int *stock = (int *)registro[STOCK];
    /* impresion de datos */
    arch << setw(10) << producto
            << setw(25) << palet
            << setw(20) << *stock << endl;
}

int compararStr (const void *parametro1, const void *parametro2) {
    void **p = (void **)parametro2;
    /* sacar datos tipo char a comparar */
    char *dato1 = (char *)parametro1;
    char *dato2 = (char *)p[PRODUCTO];
    return strcmp(dato1,dato2);
}

void eliminaReg (void *reg) {
    /* declaracion de variables */
    void **registro = (void **)reg;
    char *codP = (char *)registro[PRODUCTO];
    char *palet = (char *)registro[PALET];
    int *stock = (int *)registro[STOCK];
    /* eliminar datos */
    delete codP;
    delete palet;
    delete stock;
    delete registro;
}

/******************** Funciones Genericas **********************/

enum Nodo {DATO,NEXT};

void crealista (void *&Lista, void * (*lee)(ifstream &), 
        int (*cmp)(const void *, const void *)) {
    ifstream arch = abrirArchL("stock.csv"); 
    void *dato;
    Lista = nullptr;
    while (1) {
        dato = lee(arch);
        if (dato == nullptr) break;
        insertarLista(Lista,dato,cmp);
    }
}

void insertarLista (void *&Lista, void *dato, int (*cmp)(const void *, const void *)) {
    void **p = (void **)Lista;
    void **prev = nullptr, **nuevo;
    nuevo = new void *[2];
    nuevo[DATO] = dato;
    while (p) {
        if (cmp(p[DATO],dato) > 0) break;
        prev = p;
        p = (void **)(p[NEXT]);
    }
    nuevo[NEXT] = p;
    if (prev == nullptr) Lista = nuevo;
    else prev[NEXT] = nuevo;
}

void imprimelista (void *Lista, void (*imprime)(ofstream &, void *)) {
    ofstream arch = abrirArchE("Reporte.txt");
    arch.precision(2); arch << fixed;
    arch << "Codigo de Producto"
            << setw(20) << "Codigo de Palet"
            << setw(25) << "Cant. de Productos" << endl;
    imprimeLinea('=',65,arch);
    void **aux = (void **)Lista;
    while (aux) {
        imprime(arch,aux[DATO]);
        aux = (void **)aux[NEXT];
    }
}

void eliminarDatoLista (void *&Lista, void *dato, int (*cmp)(const void *, const void *)) {
    void **aux = (void **)Lista, **sale, **prev = nullptr;
    while (aux) {
        if (cmp(dato,aux[DATO]) == 0) {
            if (!prev) Lista = aux[NEXT];
            else prev[NEXT] = aux[NEXT];
            sale = aux;
            delete sale;
            break;
        }  
        prev = aux;
        aux = (void **)aux[NEXT];             
    }
}

void * buscarDatoLista (void *Lista, void *dato, int (*cmp)(const void *, const void *)) {
    void **aux = (void **)Lista, **sale, **prev = nullptr, **devuelve;
    while (aux) {
        if (cmp(dato,aux[DATO]) == 0)  return aux[DATO];
        prev = aux;
        aux = (void **)aux[NEXT];             
    }
    return nullptr;
}

enum ptrCola {FIRST,LAST};

void encola (void *&Cola, void *dato) {
    void **p_ptr = (void **)Cola;
    void **p = (void **)p_ptr[LAST];
    void **nuevo;
    nuevo = new void *[2];
    nuevo[DATO] = dato;
    nuevo[NEXT] = nullptr;
    if (esColaVacia(Cola)) {
        p_ptr[FIRST] = nuevo;
        p_ptr[LAST] = nuevo;
    } else {
        p[NEXT] = nuevo;
        p_ptr[LAST] = nuevo;
    }
}

void * desencola (void *&Cola) {
    void **p_ptr = (void **)Cola;
    void **sale;
    void **devuelve;
    void **p = (void **)p_ptr[FIRST];   
    if (esColaVacia(Cola)) return nullptr;
    sale = (void **)p_ptr[FIRST];
    p_ptr[FIRST] = p[NEXT];
    if (p_ptr[FIRST] == nullptr) p_ptr[LAST] = p[NEXT];
    devuelve = (void **)sale[DATO]; 
    delete sale;
    return devuelve;
}

int esColaVacia (void *Cola) {
    void **p_ptr = (void **)Cola;
    return !p_ptr[FIRST] && !p_ptr[LAST];
}

/******************** Funciones del Laboratorio **********************/

void despacha (void *&lpalets, void *&despachados, int argc, char **argv) {
    void **nodoCola;
    char *codProd;
    int cant;
    nodoCola = new void *[2];
    nodoCola[FIRST] = nodoCola[LAST] = nullptr;
    despachados = nodoCola;
    ofstream arch = abrirArchE("faltantes.txt");
    arch.precision(2); arch << fixed;
    arch << setw(10) << "Cod. Prod" << setw(12) << "Faltan" << endl;
    imprimeLinea('=',30,arch);
    for (int i = 1; i < argc; i+=2) {
        codProd = argv[i];
        cant = atoi(argv[i+1]);
        atender(lpalets,despachados,codProd,cant,arch);
    }
}

void atender (void *&lpalets, void *&despachados, char *codProd, int cant, ofstream &arch) {
    int restante = cant, despachado;
    void *reg, **data, **encolado;
    while (restante > 0) {
        reg = buscarDatoLista(lpalets,codProd,compararStr);
        if (reg == nullptr) {
            arch << setw(10) << codProd << setw(10) << restante << endl;
            break;
        } else {
            data = (void **)reg;
            char *codP = (char *)data[PRODUCTO];
            char *palet = (char *)data[PALET];
            int *stock = (int *)data[STOCK];
            if (*stock > restante) {              
                // primer caso: tengo mas stock que lo que necesito en un palet
                (*stock) = (*stock) - restante; // actualizamos el stock
                despachado = restante; // cantidad despachada
                restante = 0; // ya no quedan mas por atender               
            } else {
                // segundo caso: tengo menos stock que lo que necesito en un palet
                eliminarDatoLista(lpalets,codProd,compararStr); // elimino el palet de la lista
                despachado = (*stock); // despacho el stock que tenia
                restante -= despachado; // lo restante es lo que tenia menos lo que despacho
            }
            encolado = new void *[3];
            encolado[0] = codP;
            encolado[1] = palet;
            int *cantidad = new int; *cantidad = despachado;
            encolado[2] = cantidad;
            encola(despachados,encolado);
        }
    }
}

void imprimedespachados (void *&despachados, void (*imprime)(ofstream &, void *)) {
    ofstream arch = abrirArchE("despachado.txt");
    arch.precision(2); arch << fixed;
    arch << "Codigo de Producto"
            << setw(20) << "Codigo de Palet"
            << setw(25) << "Cant. de Productos" << endl;
    imprimeLinea('=',65,arch);
    void *reg;
    while (!esColaVacia(despachados)) {
        reg = desencola(despachados);
        imprime(arch,reg);
        eliminaReg(reg);
    }
}