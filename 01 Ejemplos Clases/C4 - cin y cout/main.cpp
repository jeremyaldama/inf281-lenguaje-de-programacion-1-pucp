#include <iostream>
#include <iomanip>
using namespace std;
#include "FuncionesAuxiliares.h"
#define MAX_CAR_LIN 100

int main(){
    int dd, mm, aa, serie, secuencia, referencia;
    char cliente[10], doc, car;
    double monto, total_facturas = 0, totas_nc = 0;

    cout<<"REGISTRO DE VENTAS"<<endl;
    ImprimirLinea('=', MAX_CAR_LIN);

    cout<<left<<setw(15)<<"FECHA"<<setw(14)<<"CLIENTE"<<setw(17)<<"TIPO"<<
                setw(12)<<"SECUENCIA"<<setw(9)<<"SERIE"<<setw(14)<<"FACTURAS"
                <<setw(8)<<"N/C"<<"REFERENCIA"<<endl;
    ImprimirLinea('-', MAX_CAR_LIN);

    while (1){
        cin >> dd;
        if (cin.eof()) break;

        cin>>car>>mm>>car>>aa;
        cin>>cliente>>doc;
        cin>>serie>>car>>secuencia;
        cin>>monto>>referencia;

        if (doc=='F') total_facturas += monto;

        cout<<right<<setfill('0')<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<aa
            <<setfill(' ');
        cout<<setw(13)<<cliente;
        cout<<left<<setw(5)<<" "<<setw(20);
        if (doc=='F') cout<<"FACTURA";
        else cout<<"NOTA DE CREDITO";

        cout<<right<<setfill('0')<<setw(5)<<secuencia
        // Se tiene que actualizar el setfill, porque lo estaba llenando con 0's
            <<setfill(' ')<<setw(5)<<" ";

        cout<<setfill('0')<<setw(4)<<serie<<setfill(' ');
        cout<<setw(12);

        if (doc=='F') cout<<monto; else cout<<" ";
        cout<<setw(12);

        if (doc=='F') cout<<" "; else cout<<monto;
        cout<<setfill(' ')<<setw(5)<<" "
            <<setfill('0')<<setw(5)<<referencia<<setfill(' ');

        cout<<endl;
    }
    return 0;
}