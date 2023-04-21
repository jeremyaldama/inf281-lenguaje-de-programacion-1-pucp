/* 
 * File:   Funciones.cpp
 * Author: Jeremy Aldama 20206228
 * 
 * Created on 19 de abril de 2023, 23:11
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Funciones.h"

using namespace std;

void LeerArchivos() {
    ifstream arch("Medico-Paciente-Medicinas.txt", ios::in);
    if (!arch) {
        cout << "No se puede abrir el archivo de lectura";
        exit(1);
    }

    ofstream arch_medicos("Medicos.txt", ios::out);
    if (!arch_medicos) {
        cout << "Error al abrir el archivo Medicos.txt" << endl;
        exit(1);
    }

    ofstream arch_pacientes_bin("Pacientes.bin", ios::out | ios::binary);
    if (!arch_pacientes_bin) {
        cout << "Error al abrir el archivo Pacientes.bin" << endl;
        exit(1);
    }

    ofstream arch_medicinas_bin("Medicinas.bin", ios::out | ios::binary);
    if (!arch_medicinas_bin) {
        cout << "Error al abrir el archivo Medicinas.bin" << endl;
        exit(1);
    }

    ofstream arch_consultas("Consultas.txt", ios::out);
    if (!arch_consultas) {
        cout << "Error al abrir el archivo Consultas.txt" << endl;
        exit(1);
    }

    char codigo_medico[10], nombre_medico[100], codigo_medico_atiende[10],
            descripcion_medicamento[100], c, 
            nombre_paciente[100];
    int dni_paciente, dd_consulta, mm_consulta,
            aa_consulta, cantidad_medicamentos, codigo_medicamento;
    double precio_medicamento;


    while (1) {
        arch >> dni_paciente;
        if (arch.eof()) break;
        if (arch.fail()) {
            arch.clear();
            arch >> codigo_medico >> nombre_medico;
//            cout << nombre_medico << " " << especialidad_medico << endl;
            AgregarMedico(arch_medicos, codigo_medico, nombre_medico);
        } 
        else {
            arch >> nombre_paciente >> codigo_medico_atiende >> dd_consulta >>
                    c >> mm_consulta >> c >> aa_consulta >>
                    cantidad_medicamentos;
            AgregarPaciente(arch_pacientes_bin, dni_paciente, nombre_paciente, 
                    0.0);
            AgregarConsulta(arch_consultas, dni_paciente, codigo_medico_atiende,
                    dd_consulta, mm_consulta, aa_consulta, cantidad_medicamentos);
            for (int i = 0; i < cantidad_medicamentos; i++) {
                arch >> codigo_medicamento >> descripcion_medicamento >>
                        precio_medicamento;
                AgregarMedicina(arch_medicinas_bin, codigo_medicamento, 
                        descripcion_medicamento, precio_medicamento);
                AgregarMedicamentosConsulta(arch_consultas, codigo_medicamento);
            }
            arch_consultas << endl;
        }
    }
}

void AgregarMedicamentosConsulta(ofstream&arch_consultas, int codigo_medicamento){
    arch_consultas << ' ' << codigo_medicamento;
}

void AgregarConsulta(ofstream &arch_consultas, int dni_paciente, 
        char*codigo_medico_atiende, int dd, int mm, int aa, 
        int cantidad_medicamentos){
    arch_consultas << dni_paciente << ' ' << codigo_medico_atiende << ' ' <<
            setw(2) << setfill('0') << dd << '/' << setw(2) << mm << '/' << 
            aa << setfill(' ') << ' ' << cantidad_medicamentos; 
}

void AgregarMedicina(ofstream &arch_medicinas_bin, int codigo_medicamento, 
                        char*descripcion_medicamento, double precio_medicamento){
    int se_encuentra = VerificarSeEncuentraInt(codigo_medicamento, 
            "Medicinas.bin");
    if (!se_encuentra){
        arch_medicinas_bin.write(reinterpret_cast<const char*>
                (&codigo_medicamento), sizeof(int));
        arch_medicinas_bin.write(reinterpret_cast<const char*>
                (descripcion_medicamento), sizeof(char)*100);
        arch_medicinas_bin.write(reinterpret_cast<const char*>
                (&precio_medicamento), sizeof(double));
        arch_medicinas_bin.flush();
    }
}

void AgregarPaciente(ofstream &arch_pacientes, int dni_paciente, 
        char*nombre_paciente, double gasto){
    int se_encuentra = VerificarSeEncuentraInt(dni_paciente, "Pacientes.bin");
    // Inserta los primeros 4 caracteres
    if (!se_encuentra){
//        arch_pacientes.write(reinterpret_cast<const char*>(&dni_paciente), sizeof(int));
//        arch_pacientes.write(reinterpret_cast<const char*>(nombre_paciente), sizeof(char)*100);
//        arch_pacientes.write(reinterpret_cast<const char*>(&gasto), sizeof(double));
//        arch_pacientes.flush();
        arch_pacientes.write((const char*)(&dni_paciente), sizeof(int));
        arch_pacientes.write((const char*)(nombre_paciente), sizeof(char)*100);
        arch_pacientes.write((const char*)(&gasto), sizeof(double));
        /*
        By default, std::cout is buffered, and the actual output is only printed 
        once the buffer is full or some other flushing situation occurs (e.g. a 
        newline in the stream). Sometimes you want to make sure that the printing 
        happens immediately, and you need to flush manually.
        */
        arch_pacientes.flush();
    }
}

int VerificarSeEncuentraInt(int llave, const char*nombre_arch){
    ifstream arch(nombre_arch, ios::in | ios::binary);
    if (!arch){
        cout << "No se pudo abrir *.bin para verificar" << endl;
        exit(1);
    }
    int entero;
    char nombre[100];
    double flotante;
    while(1){
        arch.read(reinterpret_cast<char*>(&entero), sizeof(int));
        if (arch.eof()) break;
        arch.read(reinterpret_cast<char*>(nombre), sizeof(char)*100);
        arch.read(reinterpret_cast<char*>(&flotante), sizeof(double));
        if (entero == llave) return 1;
    }
    return 0;
}

void AgregarMedico(ofstream &arch, char*codigo_medico, char*nombre_medico){
    char especialidad_medico[20];
    ObtenerEspecialidad(nombre_medico, especialidad_medico);
    arch << codigo_medico << " " << nombre_medico << " " <<
            especialidad_medico << endl;
}

void ObtenerEspecialidad(char *nombre_medico, char*especialidad_medico) {
    int flag = 0, j = 0;
    for (int i = 0; nombre_medico[i] != '\0'; i++) {
        if (flag){
            especialidad_medico[j++] = nombre_medico[i];
        }
        
        if (nombre_medico[i+2]>='a' && nombre_medico[i+2]<='z'){
            nombre_medico[i] = 0;
            flag = 1;
        }
    }
    especialidad_medico[j] = 0;
}

void VerificarCreacion(const char*nombre_arch, 
        const char*nombre_arch_out){
    ifstream arch(nombre_arch, ios::in | ios::binary);
    if (!arch){
        cout << "No se pudo abrir *.bin para verificar" << endl;
        exit(1);
    }
    ofstream arch_prueba(nombre_arch_out, ios::out);
    int entero;
    char nombre[100];
    double flotante;
    while(1){
        arch.read(reinterpret_cast<char*>(&entero), sizeof(int));
        if (arch.eof()) break;
        arch.read(reinterpret_cast<char*>(nombre), sizeof(char)*100);
        arch.read(reinterpret_cast<char*>(&flotante), sizeof(double));
        arch_prueba << left << setw(14) << entero << setw(50) << nombre <<
                flotante << endl;
    }
}