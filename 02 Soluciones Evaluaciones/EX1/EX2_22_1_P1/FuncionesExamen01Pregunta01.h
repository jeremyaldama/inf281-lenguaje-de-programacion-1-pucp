/* 
 * File:   FuncionesExamen01Pregunta01.h
 * Author: Jeremy Aldama 20206228
 *
 * Created on 14 de mayo de 2023, 17:42
 */

#ifndef FUNCIONESEXAMEN01PREGUNTA01_H
#define FUNCIONESEXAMEN01PREGUNTA01_H

void CargarProductosPedidos(int**&pro_Informacion, char**&pro_Descripcion,
        int**&ped_Todo, const char*nom);
void PruebaProductosPedidos(int**pro_Informacion, char**pro_Descripcion,
        int**ped_Todo, const char*nom);
void AgregarPedido(int*&ped, int dni, int fecha, int cant, int cod);
int BuscarProducto(int**pro_inf, int cod);
void ordenarPedidos(int**ped_Todo);

void qSort(int**ped_Todo, int izq, int der);
void cambiar(int *&valorI, int*&valorK);
bool enDesorden(int*vI, int*vK);
void IncrementarEspaciosPedidos(int*&datos, int&num_ped, int&cap);
void asignarPedidos(int***cli_DniTelPed, int**pro_Informacion, int**ped_Todo);
#endif /* FUNCIONESEXAMEN01PREGUNTA01_H */
