/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   NodoPallet.h
 * Author: Danie
 *
 * Created on 17 de junio de 2023, 15:48
 */

#ifndef NODOPALLET_H
#define NODOPALLET_H
#include "Pallet.h"
#include "PalletPE.h"
#include "PalletEU.h"
#include "PalletUS.h"

class NodoPallet {
private:
    class Pallet *pallet;
    class NodoPallet *sig;
public:
    NodoPallet() { pallet = nullptr; sig = nullptr; }
    virtual ~NodoPallet() { if (pallet) delete pallet;}
    friend class ListaPallet;
};

#endif /* NODOPALLET_H */

