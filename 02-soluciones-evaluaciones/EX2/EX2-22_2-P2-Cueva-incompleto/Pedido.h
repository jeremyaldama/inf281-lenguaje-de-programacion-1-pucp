
/* 
 * File:   Pedido.h
 * Author: cueva
 *
 * Created on 6 de junio de 2022, 05:41 PM
 */
#include <fstream>


using namespace std;

#ifndef PEDIDO_H
#define PEDIDO_H

class Pedido {
public:
    Pedido();
    Pedido(const Pedido& orig);
    virtual ~Pedido();
    void iniPedido();
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetDni(int dni);
    int GetDni() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void setTotal(double total);
    double getTotal() const;
    void setDespacho(int despacho);
    int getDespacho() const;
    void setOrden(int orden);
    int getOrden() const;

private:
    int codigo;
    int cantidad;
    double total;
    int dni;
    int fecha;
   // int despacho;
    int orden;
};


ifstream &operator >> (ifstream &, Pedido &);
ofstream &operator << (ofstream &, Pedido &);

#endif /* PEDIDO_H */

