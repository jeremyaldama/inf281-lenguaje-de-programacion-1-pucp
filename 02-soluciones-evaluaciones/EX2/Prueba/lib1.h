/* 
 * File:   lib1.h
 * Author: Jeremy Aldama 20206228
 *
 * Created on 14 de junio de 2023, 23:32
 */

#ifndef LIB1_H
#define LIB1_H
#include <iostream>
using namespace std;
#include "lib2.h"

class Persona {
private:
    int num;
public:
    void mostrar();
};

void Persona::mostrar() {
    cout << "lib1" << endl;
}
#endif /* LIB1_H */
