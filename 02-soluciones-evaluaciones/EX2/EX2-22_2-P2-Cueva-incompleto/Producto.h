/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Producto.h
 * Author: cueva
 *
 * Created on 12 de junio de 2022, 05:20 PM
 */
#include <fstream>

using namespace std;

#ifndef PRODUCTO_H
#define PRODUCTO_H

class Producto {
public:
    Producto();
    Producto(const Producto& orig);
    virtual ~Producto();
    void SetStock(int stock);
    int GetStock() const;
    void SetCodprod(int codprod);
    int GetCodprod() const;
    virtual void leeprod(ifstream &);
    virtual void imprimeprod(ofstream &arch);
    void SetNombre(char* );
    void GetNombre(char *) const;
    int validastock(int);
    
    virtual void setPrioridad(int prioridad)=0;
    virtual int getPrioridad() const =0 ;
//    virtual int getMinimo() const=0;
    
private:
    int codprod;
    char *nombre;
    int stock;

};

#endif /* PRODUCTO_H */

