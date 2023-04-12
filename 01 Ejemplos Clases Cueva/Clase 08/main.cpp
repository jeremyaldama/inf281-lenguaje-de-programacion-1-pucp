#include <iostream>
#include <iomanip>

using namespace std;
#include "funcion.h"
#include "sobrecarga.h"

int main(){
    tregistro rnotas = {{20,11,5,4,8}, 5};
    cout << rnotas++ << endl;


    return 0;
}