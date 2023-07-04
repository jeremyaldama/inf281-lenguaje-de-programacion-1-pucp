/* 
 * File:   main.cpp
 * Author: Jeremy Aldama 20206228
 *
 * Created on 25 de junio de 2023, 11:59
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "Persona.h"

void foo(class Persona *per) {
    char nomb[100];
    per->GetNombre(nomb);
    cout << nomb << endl;
    delete per;
}

int main(int argc, char** argv) {
    class Persona *per = new class Persona;
    per->SetNombre("Jeremy");
    char n[100];
    per->GetNombre(n);
    cout << n << endl;
    foo(per);
    delete per;
    cout << per->GetEdad() << endl;
    per->GetNombre(n);
    cout << n << endl;
    return 0;
}

