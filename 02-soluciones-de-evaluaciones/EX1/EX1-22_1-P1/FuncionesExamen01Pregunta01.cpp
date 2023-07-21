/* 
 * File:   FuncionesExamen01Pregunta01.cpp
 * Author: Jeremy Aldama 20206228
 * 
 * Created on 14 de mayo de 2023, 17:42
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include "FuncionesExamen01Pregunta01.h"

using namespace std;
#include <cstring>
#define INCREMENTO 5

void CargarProductosPedidos(int**&pro_Informacion, char**&pro_Descripcion,
        int**&ped_Todo, const char*nom) {
    ifstream arch(nom, ios::in);
    if (!arch) {
        cout << "NO SE PUDO ABRIR PedidosPreg01.csv";
        exit(1);
    }

    // 412041,TORTILLAS DE MAIZ 1KG,7.91%,1.78,14.93,15.95,71378466,26/10/2020
    // codigo, descripcion, descuento (si tiene), cantidad, preciou, stock, dni_cli, dd,mm,aa
    int*pro_inf[500]{}, *ped_to[500]{};
    char*pro_des[500]{};

    int cod, dni, dd, mm, aa, fecha, ind_pro, num_pro = 0, num_ped = 0;
    char des[100], c, por;
    double descuento, cant, preciou, stock;

    while (1) {
        arch >> cod;
        if (arch.eof()) break;
        arch >> c;
        arch.getline(des, 100, ',');
        arch >> descuento >> c;
        if (c == '%') {
            arch >> c >> cant >> c;
        } else if (c == ',') {
            cant = descuento;
            descuento = 0;
        }
        arch >> preciou >> c >> stock >> c >> dni >> c >> dd >> c >> mm >> c >> aa;
        fecha = dd + mm * 100 + aa * 10000;

        ind_pro = BuscarProducto(pro_inf, cod);
        if (ind_pro == -1) {
            pro_inf[num_pro] = new int[4];
            int*info = pro_inf[num_pro];
            info[0] = cod;
            info[1] = (int) (descuento * 100);
            info[2] = (int) (preciou * 100) + 1;
            info[3] = (int) (stock * 100) + 1;

            pro_des[num_pro] = new char[strlen(des) + 1];
            strcpy(pro_des[num_pro], des);
            num_pro++;
        }

        AgregarPedido(ped_to[num_ped++], dni, fecha, (int) (cant * 100), cod);
    }

    pro_Descripcion = new char*[num_pro + 1] {
    };
    pro_Informacion = new int*[num_pro + 1] {
    };
    ped_Todo = new int*[num_ped + 1] {
    };

    for (int i = 0; pro_des[i]; i++) {
        pro_Informacion[i] = pro_inf[i];
        pro_Descripcion[i] = pro_des[i];
    }

    for (int i = 0; ped_to[i]; i++) {
        ped_Todo[i] = ped_to[i];
    }
}

void AgregarPedido(int*&ped, int dni, int fecha, int cant, int cod) {
    ped = new int[4];
    ped[0] = dni;
    ped[1] = fecha;
    ped[2] = cant;
    ped[3] = cod;
}

int BuscarProducto(int**pro_inf, int cod) {
    for (int i = 0; pro_inf[i]; i++) {
        int *datos = pro_inf[i];
        if (datos[0] == cod) return i;
    }
    return -1;
}

void PruebaProductosPedidos(int**pro_Informacion, char**pro_Descripcion,
        int**ped_Todo, const char*nom) {
    ofstream arch(nom, ios::out);
    if (!arch) {
        cout << "NO SE PUDO ABRIR PruebaProductosPedidos";
        exit(1);
    }
    arch << "PRODUCTOS: " << endl;
    arch << left << setw(20) << "CODIGO PRODUCTO" << setw(10) << "DESCUENTO" <<
            setw(8) << "PRECIO" << setw(8) << "STOCK" << endl;
    for (int i = 0; pro_Informacion[i]; i++) {
        arch << setw(20) << pro_Informacion[i][0] << setw(10) <<
                pro_Informacion[i][1] << setw(8) << pro_Informacion[i][2] <<
                setw(8) << pro_Informacion[i][3] << endl;
        for (int j = 0; ped_Todo[j]; j++) {
            if (pro_Informacion[i][0] == ped_Todo[j][3]) {
                arch << setw(7) << " " << ped_Todo[j][1] << "    " <<
                        ped_Todo[j][0] << "    " << ped_Todo[j][2] << endl;
            }
        }
        arch << endl;
    }

}

void ordenarPedidos(int**ped_Todo) {
    int nd;
    for (nd = 0; ped_Todo[nd]; nd++);
    qSort(ped_Todo, 0, nd - 1);
}

void qSort(int**ped_Todo, int izq, int der) {
    int limite;
    if (izq >= der) return;
    // pivot
    cambiar(ped_Todo[izq], ped_Todo[(izq + der) / 2]);
    limite = izq;

    for (int i = izq + 1; i <= der; i++)
        if (enDesorden(ped_Todo[i], ped_Todo[izq]))
            cambiar(ped_Todo[++limite], ped_Todo[i]);
    cambiar(ped_Todo[izq], ped_Todo[limite]);
    qSort(ped_Todo, izq, limite - 1);
    qSort(ped_Todo, limite + 1, der);
}

void cambiar(int *&valorI, int*&valorK) {
    int *aux;
    aux = valorI;
    valorI = valorK;
    valorK = aux;
}

bool enDesorden(int*vI, int*vK) {
    return vI[1] < vK[1] or vI[1] == vK[1] and vI[0] < vK[0];
}

void asignarPedidos(int***cli_DniTelPed, int**pro_Informacion, int**ped_Todo) {
    for (int i = 0; cli_DniTelPed[i]; i++) {
        int **datos = cli_DniTelPed[i];
        int cap = 0, num_ped = 0;
        cout << "DNI CLIENTE: " << *datos[0] << endl;
        for (int j = 0; ped_Todo[j]; j++) {
            int*ped = ped_Todo[j];
            if (ped[0] == *datos[0]) {
                if (num_ped == cap) {
                    IncrementarEspaciosPedidos(datos[2], num_ped, cap);
                }

                if (*(pro_Informacion[i] + 3) >= ped[2]) {
                    int *pedido = datos[2];
                    pedido[num_ped - 3] = ped[1];
                    pedido[num_ped - 2] = ped[2];
                    (*(pro_Informacion[i] + 3)) -= ped[2];
                    pedido[num_ped - 1] = ped[3];

                    cout << pedido[num_ped - 3] << endl;
                    cout << pedido[num_ped - 2] << endl;
                    cout << pedido[num_ped - 1] << endl << endl;
                    num_ped += 3;
                }
            }
        }
    }
}

void IncrementarEspaciosPedidos(int*&datos, int&num_ped, int&cap) {
    cap += (INCREMENTO * 3);
    if (datos == nullptr) {
        datos = new int[cap] {
        };
        num_ped = 3;
    } else {
        int*aux = new int[cap] {};
        for (int i = 0; i < num_ped; i++) {
            aux[i] = datos[i];
        }
        delete datos;
        datos = aux;
    }
}