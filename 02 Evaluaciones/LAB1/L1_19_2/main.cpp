#include <iostream>
#include <iomanip>
#include "FuncionesAuxiliares.h"
using namespace std;

int main(int argc, char** argv) {
    double dolar, euro;
    cin>>dolar>>euro;
    cout.precision(2);
    cout<<fixed;
    char moneda;
    
    while (1){
        if (cin.eof()) break;
        LeerCliente(moneda);
        ProcesarCliente(dolar, euro, moneda);
        
    }
    return 0;
}

