/* 
 * File:   main.cpp
 * Author: Jeremy Aldama 20206228
 *
 * Created on 22 de marzo de 2023, 10:14
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    char nombre[20];
    double nota, suma_notas = 0;
    int cantidad_notas = 0;
    
    cin >> nombre;
    cout << left << setfill('.') <<setw(20) << nombre;
    
    
    while(1){
        cin >> nota;
        // como le estoy diciendo que lea un double, cuando encuentre otra tipo
        // de dato como char levantara la bandera
        if (cin.eof()){
            cout << fixed << setprecision(2) << suma_notas/cantidad_notas << endl;
            break;
        }
        
        if (cin.fail()){
            cin.clear();
            cin >> nombre;
            cout  << fixed << setprecision(2) << suma_notas/cantidad_notas << endl << setw(20) << nombre;
            suma_notas = 0;
            cantidad_notas = 0;
        }
        else{
            suma_notas += nota;
            cantidad_notas++;
        }
    }
    return 0;
}

