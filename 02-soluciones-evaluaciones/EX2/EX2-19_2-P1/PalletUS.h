/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   PalletUS.h
 * Author: Danie
 *
 * Created on 17 de junio de 2023, 14:05
 */

#ifndef PALLETUS_H
#define PALLETUS_H
#include "Pallet.h"

class PalletUS : public Pallet{
public:
    void imprime(ofstream&);
    char tipo(void);
    int peso(void);
};

#endif /* PALLETUS_H */

