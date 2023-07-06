/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   PalletEU.h
 * Author: Danie
 *
 * Created on 17 de junio de 2023, 15:36
 */

#ifndef PALLETEU_H
#define PALLETEU_H
#include "Pallet.h"

class PalletEU : public Pallet{
public:
    void imprime(ofstream&);
    char tipo(void);
    int peso(void);
};

#endif /* PALLETEU_H */

