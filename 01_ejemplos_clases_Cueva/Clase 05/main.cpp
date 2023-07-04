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
    ifstream arch("input.txt",ios::in);
    if (!arch){
        cout << "No se pudo abrir el archivo de datos.txt" << endl;
        exit(1);
    }
    
    ofstream repo("output.txt",ios::out);
    if (!arch){
        cout << "No se pudo abrir el archivo de datos.txt" << endl;
        exit(1);
    }
    
    imprime(arch, repo);
    return 0;
}