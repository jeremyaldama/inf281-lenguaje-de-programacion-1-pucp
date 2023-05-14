/* 
 * File:   PunterosGenericos.cpp
 * Author: Jeremy Aldama 20206228
 * 
 * Created on 13 de mayo de 2023, 18:23
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include "PunterosGenericos.h"

using namespace std;
#include <cstring>

void cargaproductos(void*&productos) {
    ifstream arch("productos2.csv", ios::in);
    if (!arch) {
        cout << "NO SE PUDO ABRIR PRODUCTOS2.CSV";
        exit(1);
    }

    void **productos2, *buff[100]{}, *reg;
    int nd = 0;
    while (1) {
        reg = LeerProducto(arch);
        if (!reg) break;
        buff[nd] = reg;
        nd++;
    }

    productos2 = new void*[nd + 1] {
    };
    for (int i = 0; i < nd; i++) {
        productos2[i] = buff[i];
    }
    productos = productos2;
}

void*LeerProducto(ifstream&arch) {
    int *cod, *can, codaux;
    char *desc, descrip[100];
    double *precio;

    arch >> codaux;
    if (arch.eof()) return nullptr;
    cod = new int;
    *cod = codaux;
    arch.get();
    arch.getline(descrip, 100, ',');
    desc = new char[strlen(descrip) + 1];
    strcpy(desc, descrip);
    precio = new double;
    can = new int;
    arch >> *precio;
    arch.get();
    arch >> *can;
    void **prod = new void*[4];
    prod[0] = cod;
    prod[1] = desc;
    prod[2] = precio;
    prod[3] = can;

    return prod;
}

void cargapedidos(void*&pedidos) {
    ifstream arch("pedidos2.csv", ios::in);
    if (!arch) {
        cout << "NO SE PUDO ABRIR pedidos2.CSV";
        exit(1);
    }

    void **registros, *buff2[500]{}, *reg2;
    int nd = 0;
    while (1) {
        reg2 = LeerPedido(arch);
        if (!reg2) break;

        buff2[nd] = reg2;

        nd++;
    }
    registros = new void*[nd + 1] {
    };
    for (int i = 0; i < nd; i++) {
        registros[i] = buff2[i];
    }
    pedidos = registros;
}

void *LeerPedido(ifstream&arch) {
    int cod, can, dni, fecha, dd, mm, aa;
    char *cad, cad2[500], c;

    arch >> cod;
    if (arch.eof()) return nullptr;
    arch.get();
    arch.getline(cad2, 500, ',');
    cad = new char[strlen(cad2) + 1];
    strcpy(cad, cad2);
    arch >> can >> c >> dni >> c >> dd >> c >> mm >> c >> aa;
    fecha = dd + mm * 100 + aa * 10000;
    void **reg = new void*[6];
    reg[0] = new int{cod};
    reg[1] = cad;
    reg[2] = new int{can};
    reg[3] = new int{dni};
    reg[4] = new int{fecha};
    reg[5] = new char{'N'};

    return reg;
}

void procesaclientes(void*productos, void*pedidos, void*&clientes) {
    ifstream arch("clientes2.csv", ios::in);
    if (!arch) {
        cout << "NO SE PUDO ABRIR clientes2.CSV";
        exit(1);
    }

    void **registros, *buff2[500]{}, *reg2;
    int nd = 0;
    while (1) {
        reg2 = LeerCliente(arch, productos, pedidos);
        if (!reg2) break;

        buff2[nd] = reg2;

        nd++;
    }
    cout << nd << endl;
    registros = new void*[nd + 1] {
    };
    for (int i = 0; i < nd; i++) {
        registros[i] = buff2[i];
    }
    clientes = registros;
}

void *LeerCliente(ifstream&arch, void*productos, void*pedidos) {
    int dni;
    char cad[100], *nombre, c;
    arch >> dni;
    if (arch.eof()) return nullptr;
    arch >> c;
    arch.getline(cad, 100);
    nombre = new char[strlen(cad) + 1];
    strcpy(nombre, cad);
    void **cliente = new void*[3] {
    };
    cliente[0] = new int{dni};
    cliente[1] = nombre;
    AsignarPedido(cliente[2], productos, pedidos, dni);

    return cliente;
}

void AsignarPedido(void*&cliente, void*productos, void*pedidos, int dni) {
    void **registros, *buff[100]{}, *reg;
    void **pedds_aux = (void**) pedidos;
    int hay_stock, dni_ped, cod_prod, can_ped, num_ped = 0, fecha_ped;
    for (int i = 0; pedds_aux[i]; i++) {
        void **pedido = (void**) pedds_aux[i];
        dni_ped = *(int*) pedido[3];
        cod_prod = *(int*) pedido[0];
        can_ped = *(int*) pedido[2];
        hay_stock = 0;
        if (dni_ped == dni) {
            fecha_ped = *(int*) pedido[4];
            hay_stock = BuscarActualizarStock(productos, cod_prod, can_ped,
                    buff[num_ped], fecha_ped, pedido[5]);
            if (hay_stock) num_ped++;
        }
    }
    registros = new void*[num_ped + 1] {
    };
    for (int i = 0; buff[i]; i++) {
        registros[i] = buff[i];
    }
    cliente = registros;
}

int BuscarActualizarStock(void*productos, int cod_prod, int can_ped,
        void*&buff, int fecha_ped, void*estado) {
    void**prods_aux = (void**) productos;
    int cod, *can;
    for (int i = 0; prods_aux[i]; i++) {
        void **prod = (void**) prods_aux[i];
        cod = *(int*) prod[0];
        can = (int*) prod[3];
        if (cod == cod_prod) {
            if (*can >= can_ped) {
                *can -= can_ped;

                void **registros = new void*[4];
                registros[0] = new int{fecha_ped};
                registros[1] = new int{cod};
                registros[2] = prod[1];
                registros[3] = new int{can_ped};
                buff = registros;
                return 1;
            } else return 0;
        }
    }
    return 0;
}