// Jeremy Aldama 20206228

#include <iostream>
#include <iomanip>

using namespace std;
#include "FuncionesAuxiliares.h"
#define MAX_CAR_LIN 113

int main(int argc, char** argv) {
    int codigo_alum, aa_alum, dd, mm, aa, i = 0, total_alumnos = 0,
            num_cursos_error = 0;
    double nota, total_creditos = 0.0, creditos_desaprobados = 0.0,
            creditos_aprobados = 0.0, creditos;
    char nombre[100], codigo_curso[20], c;
    cout << setprecision(2);
    cout << fixed;

    cout << right << setw(60) << "INFORMACION ACADEMICA DE LOS ESTUDIANTES" << endl;
    while (1) {
        cin >> codigo_alum;
        if (cin.eof()) break;
        if (cin.fail()) {
            cin.clear();
            cin >> codigo_curso >> creditos >> nota >> dd >> c >> mm >> c >> aa;
            i++;

            if (nota >= 11) {
                cout << right << setw(3) << setfill('0') << i << setw(9) <<
                        setfill(' ') << codigo_curso << setw(9) << creditos <<
                        setw(9) << nota << setw(8) << aa << '/' << setw(2) <<
                        mm << '/' << setw(2) << dd << setfill(' ');
                if (aa_alum > aa) {
                    cout << setw(67) << "ERROR FECHA" << endl;
                    num_cursos_error++;
                } else {
                    creditos_aprobados += creditos;
                    total_creditos += creditos;
                    cout << endl;
                }
            } else {
                cout << right << setw(3) << setfill('0') << i << setw(58) <<
                        setfill(' ') << codigo_curso << setw(8) << creditos <<
                        setw(10) << nota << setw(9) << aa << '/' << setw(2) <<
                        setfill('0') << mm << '/' << setw(2) << dd <<
                        setfill(' ');
                if (aa_alum > aa) {
                    cout << setw(17) << "ERROR FECHA" << endl;
                    num_cursos_error++;
                } else {
                    creditos_desaprobados += creditos;
                    total_creditos += creditos;
                    cout << endl;
                }
            }
        } else {
            cin >> c >> aa_alum >> nombre;

            if (total_alumnos > 0) {
                ImprimirLinea('=', MAX_CAR_LIN);
                cout << setw(8) << " " << "RESUMEN:" << endl;
                cout << setw(8) << " " << "Cursos matriculados:  " << left <<
                        setw(20) << i << "Total de creditos: " << right <<
                        setw(8) << total_creditos << endl;
                cout << setw(8) << "" << "Creditos aprobados:   " << left <<
                        setw(20) << creditos_aprobados <<
                        "Creditos desaprobados: " << right << setw(6) <<
                        creditos_desaprobados << endl;
                cout << setw(8) << "" << "Creditos aprobados/matriculados:  " <<
                        creditos_aprobados / total_creditos * 100 << '%' << endl;
                ImprimirLinea('-', MAX_CAR_LIN);
                cout << setw(8) << "" << "Cursos con error no considerados: " <<
                        setw(2) << setfill('0') << num_cursos_error <<
                        setfill(' ') << endl;
                ImprimirLinea('=', MAX_CAR_LIN);
            }
            total_creditos = creditos_aprobados = creditos_desaprobados = 0.0;
            num_cursos_error = 0;

            FormatearNombre(nombre);
            ImprimirLinea('=', MAX_CAR_LIN);
            cout << right << setw(12) << "Alumno: " << nombre <<
                    setfill(' ') << setw(70-Strlen(nombre)) << "";
            cout << "Codigo: " << aa_alum << " - " << setw(6) <<
                    setfill('0') << codigo_alum << endl;
            ImprimirLinea('-', MAX_CAR_LIN);

            cout << setfill(' ') << right << setw(30) << "CURSOS APROBADOS" <<
                    setw(54) << "CURSOS DESAPROBADOS" << setw(27) <<
                    "OBSERVACION" << endl;
            cout << right << "No." << setw(9) << "CODIGO" << setw(10) <<
                    "CREDITOS" << setw(7) << "NOTA" << setw(12) << "FECHA" <<
                    setw(20) << "CODIGO" << setw(10) << "CREDITOS" << setw(8) <<
                    "NOTA" << setw(12) << "FECHA" << endl;
            ImprimirLinea('-', MAX_CAR_LIN);
            total_alumnos++;
        }
    }
    ImprimirLinea('=', MAX_CAR_LIN);
    cout << setw(8) << " " << "RESUMEN:" << endl;
    cout << setw(8) << " " << "Cursos matriculados:  " << left <<
            setw(20) << i << "Total de creditos: " << right <<
            setw(8) << total_creditos << endl;
    cout << setw(8) << "" << "Creditos aprobados:   " << left <<
            setw(20) << creditos_aprobados <<
            "Creditos desaprobados: " << right << setw(6) <<
            creditos_desaprobados << endl;
    cout << setw(8) << "" << "Creditos aprobados/matriculados:  " <<
            creditos_aprobados / total_creditos * 100 << '%' << endl;
    ImprimirLinea('-', MAX_CAR_LIN);
    cout << setw(8) << "" << "Cursos con error no considerados: " <<
            setw(2) << setfill('0') << num_cursos_error <<
            setfill(' ') << endl;
    ImprimirLinea('=', MAX_CAR_LIN);
    ImprimirLinea('=', MAX_CAR_LIN);
    cout << "TOTAL DE ALUMNOS REGISTRADOS: " << total_alumnos << endl;
    return 0;
}