/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   PalletPE.h
 * Author: Danie
 *
 * Created on 17 de junio de 2023, 15:30
 */

#ifndef PALLETPE_H
#define PALLETPE_H
#include "Pallet.h"

class PalletPE : public Pallet{
public:
    void imprime(ofstream&);
    char tipo(void);
    int peso(void);
};

#endif /* PALLETPE_H */

