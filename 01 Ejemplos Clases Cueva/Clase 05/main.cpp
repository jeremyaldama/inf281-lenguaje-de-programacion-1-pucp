#include <iostream>
#include <fstream>
#include <iomanip>
#include "funciones_auxiliares.h"

using namespace std;

// TRAUMATOLOGIA   GINECOLOGIA   2/9/2022
// LF50611   EDGAR_MUNOZ_VERGEL_Urologia   43704548   Vizcardo/Maribel   1   59121   DESLORATADINA_5MG_10T   9/09/2022
//    36471787   Pena/Glenda   5   46919   VITAMINA_C_C20_TAB_100MG   16/01/2023   92517   ISOCONAZOL_CR_20GR_GI   2/08/2022   22232   LEVETIRACETAM   12/02/2023   26484   DILTIAZEM_30_TAB/30_MG   29/08/2022   76596   CEFADROXILO_250MG_SUSP   18/12/2022
//    71422479   Lozada/Felicita   3   18672   TINIDAZOL_500MG_8T   17/08/2022   75565   MICONAZOL_20_GR_CRA   23/09/2022   37007   DIFENHIDRAMINA_250MG_JBE_120ML   17/08/2022


int main(){
    ifstream arch("datos.txt",ios::in);
    if (!arch){
        cout << "No se pudo abrir el archivo de datos.txt" << endl;
        exit(1);
    }
    
    ifstream repo("output.txt",ios::out);
    if (!arch){
        cout << "No se pudo abrir el archivo de datos.txt" << endl;
        exit(1);
    }
    
    int ddv, mmv, aav, dni, cant, cod_med, ddm, mmm, aam;
    char esp1[50], esp2[50], c,cod_doc[10], nom_doc[100], nomb_pac[50], nom_med[50];
    char nom_esp[50], esp_min[50];
    arch >> esp1 >> esp2 >> ddv >> c >> mmv >> c >> aav;

    while (1){
        arch >> dni;
        if (arch.eof()) break;
        if (arch.fail()){
            arch.clear();
            arch >> cod_doc >> nom_doc;
            corta_especialidad(nom_doc, nom_esp, esp_min);
            repo << left << setw(50) << nom_doc << setw(20) << cod_doc 
            << setw(20) << esp_min << endl;

        }
        else{
            arch >> nomb_pac >> cant;
            repo << left << setw(20) << dni << setw(50) << nomb_pac << endl;

            for (int i=0; i<cant; i++){
                arch >> cod_med >> nom_med >> ddm >> c >> mmm >> c >> aam;

                repo << setw(20) << cod_med << setw(50) << nom_med << endl;
            }
            repo << endl;
        }
    }
    
    return 0;
}