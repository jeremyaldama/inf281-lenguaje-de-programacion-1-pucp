/* 
 * File:   main.cpp
 * Author: Jeremy Aldama 20206228
 *
 * Created on 13 de mayo de 2023, 18:09
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    void *medicinas, *citas;
    
    cargamedicinas(medicinas);
    cargaconsultas(citas);
    actualizarreservas(medicinas,citas);
    imprimerepfinal(citas);
    return 0;
}

