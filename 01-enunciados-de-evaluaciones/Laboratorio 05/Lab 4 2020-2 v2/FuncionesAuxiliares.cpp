/* 
 * Archivo:   FuncionesAuxiliares.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 14 de octubre de 2020, 11:49 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "FuncionesAuxiliares.h"
#define INCREMENTO 5
using namespace std;

void imprimeLinea (char car, int num, ofstream &arch) {
    for (int i = 0; i < num; i++) arch.put(car);
    arch << endl;
}

ifstream abrirArchL (const char *nombre) {
    ifstream arch;
    arch.open(nombre, ios::in);
    if (!arch) {
        cout << "ERROR: no se pudo abrir el archivo " << nombre << endl;
        exit(1);
    }
    return arch;
} 

ofstream abrirArchE (const char *nombre) {
    ofstream arch;
    arch.open(nombre, ios::out);
    if (!arch) {
        cout << "ERROR: no se pudo abrir el archivo " << nombre << endl;
        exit(1);
    }
    return arch;
} 

char * leeCadena (ifstream &arch, char car) {
    char buff[200], *cad;
    arch.getline(buff,200,car);
    if (arch.eof()) return nullptr;
    cad = new char [strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

char * asignaCadenaExacta (char *cadena){
    int len;
    char *cad;
    len = strlen(cadena);
    cad = new char[len+1];
    strcpy(cad,cadena);
    return cad;
}

void cargarMedicosEspecialidad (char **&especialidad, char ***&listaMedicos, 
        char ***&medicos) {
    ifstream arch = abrirArchL("RelacionMedicos.csv");
    char *cod, *nomb, *esp, *tar, **infoMed;
    int capEsp = 0, capMed = 0, numEsp = 0, numMed = 0, pos, capxMed[100] = {0}, 
            numM[100] = {0}, numDat = 0;
    especialidad = nullptr; listaMedicos = nullptr; medicos = nullptr;
    while (1) {
        cod = leeCadena(arch,',');
        if (cod == nullptr) break;
        nomb = leeCadena(arch,',');
        esp = leeCadena(arch,',');
        tar = leeCadena(arch,'\n');
        pos = buscarEspecialidad(especialidad,esp,numEsp);
        if (pos == -1) {
            if (numEsp == capEsp) incrementarEspaciosEsp(especialidad,listaMedicos,
                    numEsp,capEsp);
            especialidad[numEsp] = nullptr;
            especialidad[numEsp-1] = esp;
            numEsp++;
            pos = numEsp-2;
        }
        if (numM[pos] == capxMed[pos]) incrementarEspaciosLista(listaMedicos[pos],numM,
                capxMed,pos);
        listaMedicos[pos][numM[pos]] = nullptr;
        listaMedicos[pos][numM[pos]-1] = cod;
        numM[pos]++;
        if (numMed == capMed) incrementarEspaciosMed(medicos,numMed,capMed);
        infoMed = new char *[3];
        infoMed[0] = cod;  infoMed[1] = nomb; infoMed[2] = tar;
        medicos[numMed] = nullptr;
        medicos[numMed-1] = infoMed;
        numMed++;
    }
}

int buscarEspecialidad (char **buffEsp, char *esp, int numDat) {
    for (int i = 0; i < numDat-1 ; i++) {
        if (strcmp(esp,buffEsp[i]) == 0) return i;
    }
    return -1;
}

void incrementarEspaciosEsp (char **&especialidad, char ***&listaMedicos, int &numEsp, 
        int &capEsp) {
    char **auxEsp, ***auxMed;
    capEsp += INCREMENTO;
    if (especialidad == nullptr) {
        especialidad = new char *[capEsp];
        listaMedicos = new char **[capEsp];
        especialidad[0] = nullptr; listaMedicos[0] = nullptr;
        numEsp = 1;
    } else {
        auxEsp = new char *[capEsp];
        auxMed = new char **[capEsp];
        for (int i = 0; i < numEsp ; i++) {
            auxEsp[i] = especialidad[i];
            auxMed[i] = listaMedicos[i];
        }
        delete especialidad;
        delete listaMedicos;
        especialidad = auxEsp;
        listaMedicos = auxMed;
    }
}

void incrementarEspaciosLista (char **&lista, int *numM, int *capxMed, int pos) {
    char **aux;
    capxMed[pos] += INCREMENTO;
    if (lista == nullptr || capxMed[pos] == INCREMENTO) {
        lista = new char *[capxMed[pos]];
        lista[0] = nullptr;
        numM[pos] = 1;
    } else {
        aux = new char *[capxMed[pos]];
        for (int i = 0; i < numM[pos]; i++) aux[i] = lista[i];
        delete lista;
        lista = aux;
    }
}

void incrementarEspaciosMed (char ***&medicos,int &numMed, int &capMed) {
    char ***aux;
    capMed += INCREMENTO;
    if (medicos == nullptr) {
        medicos = new char **[capMed];
        medicos[0] = nullptr;
        numMed = 1;
    } else {
        aux = new char **[capMed];
        for (int i = 0; i < numMed; i++) aux[i] = medicos[i];
        delete medicos;
        medicos = aux;
    }
}

void reporteMedicos (char **especialidad, char ***listaMedicos, char ***medicos) {
    ofstream arch = abrirArchE("ReporteMedicos.txt");
    arch.precision(2); arch << fixed;
    char nomb[50]; 
    double tarifa;
    for (int i = 0; especialidad[i] ; i++) {
        imprimeLinea('=',80,arch);
        arch << "Especialidad: " << especialidad[i] << endl;
        imprimeLinea('=',80,arch);
        arch << setw(12) << "Codigo" 
                << setw(25) << "Nombre" 
                << setw(40) << "Tarifa" << endl;
        imprimeLinea('-',80,arch);
        for (int j = 0; listaMedicos[i][j] ; j++) {
            buscarInfoMed(listaMedicos[i][j],nomb,tarifa,medicos);
            arch << setw(10) << listaMedicos[i][j]
                    << setw(7) << " "
                    << left << setw(50) << nomb
                    << right << setw(10) << tarifa << endl;
        }
    }
}

void buscarInfoMed (char *cod, char *nomb, double &tarifa, char ***medicos) {
    for (int i = 0; medicos[i] ; i++) {
        if (strcmp(medicos[i][0],cod) == 0) {          
            strcpy(nomb,medicos[i][1]);
            tarifa = atof(medicos[i][2]);
        }
    }
}

void cargarPacientes (char ***medicos, char ***&pacientes, double ***&montos) {
    ifstream arch = abrirArchL("Pacientes-Atencion.csv");
    char *fecha, tipo, *nomb, car, codMed[7], **infoPac, *cod;
    int numPac = 0, capPac = 0, pos, cant, ind, idx;
    double porc, tarifa, *infoTar;
    pacientes = nullptr;
    for (cant = 0; medicos[cant] ; cant++);
    montos = new double **[cant];
    while (1) {
        fecha = leeCadena(arch,',');
        if (fecha == nullptr) break;
        while (1) {
            arch >> tipo >> car;
            cod = leeCadena(arch,',');
            nomb = leeCadena(arch,',');
            arch >> porc >> car;
            arch.get(codMed,7,',');           
            if (tipo == 'A') {
                ind = buscarInfoMedico(medicos,codMed,tarifa);
                pos = buscarPaciente(pacientes,cod,numPac);
                if (pos == -1) {
                    if (numPac == capPac) {
                        incrementarEspaciosPac(pacientes,numPac,capPac);
                        for (int i = 0; i < cant; i++) 
                            incrementarEspaciosTar(montos[i],numPac,capPac);                        
                    }
                    for (int i = 0; i < cant ; i++) {
                        infoTar = new double [2];
                        infoTar[0] = 0; infoTar[1] = 0;
                        montos[i][numPac] = nullptr;
                        montos[i][numPac-1] = infoTar;
                    }
                    infoPac = new char *[2];
                    infoPac[0] = cod; infoPac[1] = nomb;
                    pacientes[numPac] = nullptr;
                    pacientes[numPac-1] = infoPac;
                    numPac++;
                    pos = numPac-2;
                }
                montos[ind][pos][0] += (porc*tarifa/100);
                montos[ind][pos][1] += ((100-porc)*tarifa/100);
            }
            if (arch.get() == '\n') break;
        }
    }
}

int buscarPaciente (char ***pacientes, char *cod, int numPac) {
    for (int i = 0; i < numPac-1; i++) {
        if (strcmp(pacientes[i][0],cod) == 0) return i;
    }
    return -1;
}

void incrementarEspaciosPac (char ***&pacientes, int &numPac, int &capPac) {
    char ***aux;
    capPac += INCREMENTO;
    if (pacientes == nullptr) {
        pacientes = new char **[capPac];
        pacientes[0] = nullptr;
        numPac = 1;
    } else {
        aux = new char **[capPac];
        for (int i = 0; i < numPac; i++) aux[i] = pacientes[i];
        delete pacientes;
        pacientes = aux;
    }
}

int buscarInfoMedico (char ***medicos, char *codMed, double &tarifa) {
    for (int i = 0; medicos[i] ; i++) {
        if (strcmp(medicos[i][0],codMed) == 0) {
            tarifa = atof(medicos[i][2]);
            return i;
        }
    }
    return -1;
}

void incrementarEspaciosTar (double **&monto, int numPac, int capPac) {
    double **aux;   
    if (numPac == 1) {
        monto = new double *[capPac];
        monto[0] = nullptr;
    } else {
        aux = new double *[capPac];
        for (int i = 0; i < numPac ; i++) {
            aux[i] = monto[i];
        }
        delete monto;
        monto = aux;
    }  
}

void reportePacientesPorMedico (char **especialidad, char ***listaMedicos, 
        char ***medicos, char ***pacientes, double ***montos) {
    ofstream arch = abrirArchE("ReporteFinal.txt");
    arch.precision(2); arch << fixed;
    char nomb[50]; 
    int cant;
    double tarifa, totalPago, totalSeguro;
    for (int i = 0; especialidad[i] ; i++) {
        imprimeLinea('=',90,arch);
        arch << "Especialidad: " << especialidad[i] << endl;              
        for (int j = 0; listaMedicos[i][j] ; j++) {
            imprimeLinea('-',90,arch); 
            buscarInfoMed(listaMedicos[i][j],nomb,tarifa,medicos);
            arch << "Codigo: " 
                    << listaMedicos[i][j]
                    << setw(15) << "Nombre: " 
                    << left << setw(45) << nomb
                    << right << setw(10) << "Tarifa: "
                    << tarifa << endl;
            imprimeLinea('-',90,arch);        
            arch << "Lista de Ingresos por paciente:" << endl;
            arch << setw(10) << "Codigo"
                    << setw(20) << "Nombre"
                    << setw(33) << "Pago"
                    << setw(12) << "Seguro" << endl;
            totalPago = 0; totalSeguro = 0; cant = 0;
            for (int k = 0; pacientes[k] ; k++) {
                int pos = buscarMed(medicos,listaMedicos[i][j]);
                if (montos[pos][k][0] > 0 || montos[pos][k][1] > 0 ) {
                    arch << setw(10) << pacientes[k][0]
                            << setw(10) << " "
                            << left << setw(35) << pacientes[k][1]
                            << right << setw(8) << montos[pos][k][0]
                            << right << setw(12) << montos[pos][k][1] << endl;
                    totalPago += montos[pos][k][0];
                    totalSeguro += montos[pos][k][1];
                    cant++;
                }
            }
            imprimeLinea('-',90,arch);
            arch << left << setw(45) << "Monto total recibido por pacientes: " 
                    << totalPago << endl
                    << setw(45) << "Monto a solicitar al seguro: "
                    << totalSeguro << endl
                    << setw(45) << "Total de citas atendidas: " << cant << right << endl;
        }
    }
}

int buscarMed (char ***medicos, char *cod) {
    for (int i = 0; medicos[i] ; i++) {
        if (strcmp(medicos[i][0],cod) == 0) return i;
    }
}