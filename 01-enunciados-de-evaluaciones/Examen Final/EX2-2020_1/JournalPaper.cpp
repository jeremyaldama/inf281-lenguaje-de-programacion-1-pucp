/* 
 * Archivo:   JournalPaper.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 13 de diciembre de 2020, 11:58 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "JournalPaper.h"

JournalPaper::JournalPaper() {
    journal_name = nullptr;
}

JournalPaper::JournalPaper(const JournalPaper& orig) {
    journal_name = nullptr;
    *this = orig;
}

JournalPaper::~JournalPaper() {
    if (journal_name != nullptr) delete []journal_name;
}

void JournalPaper::SetVolume(int volume) {
    this->volume = volume;
}

int JournalPaper::GetVolume() const {
    return volume;
}

void JournalPaper::SetJournal_name(const char* name) {
    if (journal_name) delete []journal_name;
    journal_name = new char [strlen(name)+1];
    strcpy(journal_name,name);
}

void JournalPaper::GetJournal_name(char* name) const {
    if (!journal_name) journal_name[0] = '\0';
    strcpy(name,journal_name);
}

void JournalPaper::operator=(const JournalPaper& orig) {
    char nombre[200], titulo[200], j_name[200];
    this->SetId(orig.GetId());
    this->SetPublication_year(orig.GetPublication_year());
    this->SetVolume(orig.GetVolume());
    orig.GetAuthor_name(nombre);
    orig.GetTitle(titulo);
    orig.GetJournal_name(j_name);
    this->SetAuthor_name(nombre);
    this->SetTitle(titulo);
    this->SetJournal_name(j_name);
}

void JournalPaper::leer_datos(ifstream& arch) {
    char nombre[200], titulo[200], j_name[200];
    int id, year, volumen;
    arch >> id; arch.get();
    arch.getline(nombre,200,';');
    arch >> year; arch.get();
    arch.getline(titulo,200,';');
    arch.getline(j_name,200,';');
    arch >> volumen;
    this->SetId(id);
    this->SetTitle(titulo);
    this->SetPublication_year(year);
    this->SetAuthor_name(nombre);
    this->SetJournal_name(j_name);
    this->SetVolume(volumen);
    
}

void JournalPaper::citar(ofstream& arch) {
    char nombre[200], titulo[200], j_name[200];
    this->GetAuthor_name(nombre);
    this->GetTitle(titulo);
    this->GetJournal_name(j_name);
    arch << nombre << " (" << this->GetPublication_year() << ")." << endl
            << titulo << '.' << endl
            << j_name << ", " << this->GetVolume() << '.' << endl;
}