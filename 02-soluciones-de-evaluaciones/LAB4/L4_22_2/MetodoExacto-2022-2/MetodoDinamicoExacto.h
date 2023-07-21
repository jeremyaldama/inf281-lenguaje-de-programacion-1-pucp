/* 
 * File:   MetodoDinamicoExacto.h
 * Author: Jeremy Aldama 20206228
 *
 * Created on 2 de mayo de 2023, 12:52
 */

#ifndef METODODINAMICOEXACTO_H
#define METODODINAMICOEXACTO_H

void lecturaDeMedicos(const char* nomb_arch, int*&med_Codigo, 
        char** &med_Nombre, char** &med_Especialidad, double* &med_Tarifa);

void ObtenerEspecialidad(char*nombre, char*especialidad);

void pruebaDeLecturaDeMedicos(const char *nom_arch, int*med_Codigo, 
        char**med_Nombre, char**med_Especialidad, double*med_Tarifa);

void lecturaDeCitas(const char*nom_arch, int* &pac_Dni, char**&pac_Nombre,
        int**&pac_Citas);

int BuscarIndiceDNI(int*dnis, int dni);

void pruebaDeLecturaDeCitas(const char*nom_arch, int* pac_Dni, char**pac_Nombre,
        int**pac_Citas);

#endif /* METODODINAMICOEXACTO_H */

