/* 
 * File:   main.cpp
 * Author: Jeremy Aldama 20206228
 *
 * Created on 22 de marzo de 2023, 11:19
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    int dato, dd, mm, aa, cant, tipo, codigo;
    char nombre[100], c, unidad[10];
    while(1){
        cin >> dato;
        
        if(cin.eof()) break;
        
        if (dato>9999){
            cin >> nombre;
            cout << dato << " " << nombre << endl;
        }
        else{
            dd = dato;
            cin >> c >> mm >> c >> aa >> tipo >> codigo >> nombre >> cant;
            
            if(cin.fail()){
                cin.clear();
                cant = 1;
            }
            cin >> unidad;
        }
    }
    return 0;
}

