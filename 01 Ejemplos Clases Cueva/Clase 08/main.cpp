#include <iostream>
#include <iomanip>

using namespace std;
#include "funcion.h"
#include "funciones.h"
#include "sobrecarga.h"
#include "regalo.h"

int main(){
    tregistro rnotas = {{20,11,5,4,8}, 5},
              rcurva = {{0,2,5,5,3}, 5};
    tregalu lalumnos[100];

    cout << rnotas++ << endl;
    cout << rnotas;

    cout << rnotas + rcurva;

    CargaAlumnos(lalumnos, "input.txt");

    return 0;
}