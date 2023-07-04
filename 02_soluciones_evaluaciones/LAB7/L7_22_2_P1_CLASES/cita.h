/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   cita.h
 * Author: Danie
 *
 * Created on 9 de junio de 2023, 0:28
 */

#ifndef CITA_H
#define CITA_H

class cita {
public:
    cita();
    cita(const cita& orig);
    virtual ~cita();
private:
    int dni;
    int codigo;
    // aaaammdd
    int fecha;
    double tarifa;
};

#endif /* CITA_H */

