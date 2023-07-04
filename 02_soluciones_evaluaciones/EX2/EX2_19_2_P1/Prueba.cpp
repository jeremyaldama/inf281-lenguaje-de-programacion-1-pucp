/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Prueba.cpp
 * Author: Danie
 * 
 * Created on 17 de junio de 2023, 12:38
 */

#include "Prueba.h"

void Prueba::cargarCola(int &horaSal) {
    int hhSal, mmSal, ssSal;
    char car;
    class Cliente cli;
    ifstream arch("Banco-ClientesSeg.csv", ios::in);
    if (!arch) {
        cout << "NO SE PUDO ABRIR CANBO-CLIENTESSEG.CSV";
        exit(1);
    }

    arch >> hhSal >> car >> mmSal >> car >> ssSal;
    horaSal = hmsASegundos(hhSal, mmSal, ssSal);
    while (1) {
        arch >> cli;
        if (arch.eof()) break;
        cola.llegada(cli);
    }

}

void Prueba::emiteReporte(int horaSal) {
    ofstream arch("Rep-Clientes.txt", ios::out);
    if (!arch) {
        cout << "NO SE PUDO ABRIR REP-CLIENTES.TXT";
        exit(1);
    }
    
    class Cliente cli;
    char nomb[100];
    int horaLleg, tEspera, hhS, mmS, ssS;
    double sumaTE = 0, numCli = 0;
    
    imprimeEncabezados(arch, horaSal);
    arch << setprecision(2) << fixed;
    while (!cola.estaVacia()) {
        cola.atencion(cli);
        cli.GetNombre(nomb);
        arch << left << setw(10) << cli.GetDni() << setw(40) << nomb;
        arch << setfill('0') << setw(2) << cli.GetHora() << ':' << setw(2) <<
                cli.GetMinuto() << ':' << setw(2) << cli.GetSegundo();
        arch << setfill(' ');
        horaLleg = hmsASegundos(cli.GetHora(), cli.GetMinuto(), cli.GetSegundo());
        
        if (horaLleg > horaSal) horaSal = horaLleg + cli.GetTTrans();
        else horaSal += cli.GetTTrans();
        
        tEspera = horaSal - horaLleg;
        segundosAHMS(horaSal, hhS, mmS, ssS);
        arch << right << setw(13) << tEspera << " seg.      ";
        arch << setfill(' ') << endl;;
        sumaTE += tEspera;
        numCli++;
    }
    imprimeLinea(arch, '=', 95);
    arch << "Promedio de espera: " << setw(10) << sumaTE/numCli << "  seg." << endl; 
}

int Prueba::hmsASegundos(int hh, int mm, int ss) {
    return hh*3600 + mm*60 + ss;
}

void Prueba::imprimeEncabezados(ofstream&arch, int horaSal) {
    int hhS, mmS, ssS;
    segundosAHMS(horaSal, hhS, mmS, ssS);
    arch << setfill('0') << "Hora de apertura: " << setw(2) << hhS << ':' <<
            setw(2) << mmS << ':' << setw(2) << ssS << endl << endl;
    arch << setfill(' ') << left << setw(50) << ' ' << setw(15) << "HORA" <<
            setw(17) << "TIEMPO" << setw(14) << "HORA" << endl;
    arch << left << setw(10) << "DNI" << setw(40) << "NOMBRE" << setw(15) <<
            "DE LLEGADA" << setw(17) << "DE ESPERA" << setw(14) << "DE SALIDA"
            << endl;
    imprimeLinea(arch, '=', 95);
}

void Prueba::segundosAHMS(int seg, int&hh, int&mm, int&ss) {
    hh = seg/3600;
    seg %= 3600;
    mm = seg/60;
    ss = seg%60;
}

void Prueba::imprimeLinea(ofstream&arch, char c, int n) {
    for (int i=0; i<n; i++) arch.put(c);
    arch << endl;
}
