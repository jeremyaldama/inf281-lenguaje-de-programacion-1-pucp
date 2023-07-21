/* 
 * Archivo:   ConferencePaper.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 13 de diciembre de 2020, 11:47 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "ConferencePaper.h"

ConferencePaper::ConferencePaper() {
    conference_name = nullptr;
    host_country = nullptr;
}

ConferencePaper::ConferencePaper(const ConferencePaper& orig) {
    conference_name = nullptr;
    host_country = nullptr;
    *this = orig;
}

ConferencePaper::~ConferencePaper() {
    if (conference_name != nullptr) delete []conference_name;
    if (host_country != nullptr) delete []host_country;
}

void ConferencePaper::SetHost_country(const char* country) {
    if (host_country) delete []host_country;
    host_country = new char [strlen(country)+1];
    strcpy(host_country,country);
}

void ConferencePaper::GetHost_country(char* country) const {
    if (!host_country) host_country[0] = '\0';
    strcpy(country,host_country);
}

void ConferencePaper::SetConference_name(const char* name) {
    if (conference_name) delete []conference_name;
    conference_name = new char [strlen(name)+1];
    strcpy(conference_name,name);
}

void ConferencePaper::GetConference_name(char* name) const {
    if (!conference_name) conference_name[0] = '\0';
    strcpy(name,conference_name);
}

void ConferencePaper::operator=(const ConferencePaper& orig) {
    char nombre[200], titulo[200], conf_name[200], country[200];
    this->SetId(orig.GetId());
    this->SetPublication_year(orig.GetPublication_year());
    orig.GetAuthor_name(nombre);
    orig.GetTitle(titulo);
    orig.GetConference_name(conf_name);
    orig.GetHost_country(country);
    this->SetAuthor_name(nombre);
    this->SetTitle(titulo);
    this->SetConference_name(conf_name);
    this->SetHost_country(country);
}

void ConferencePaper::leer_datos(ifstream& arch) {
    char nombre[200], titulo[200], conf_name[200], country[200];
    int id, year;
    arch >> id; arch.get();
    arch.getline(nombre,200,';');
    arch >> year; arch.get();
    arch.getline(titulo,200,';');
    arch.getline(conf_name,200,';');
    arch.getline(country,200,'\n');
    this->SetId(id);
    this->SetTitle(titulo);
    this->SetPublication_year(year);
    this->SetAuthor_name(nombre);
    this->SetConference_name(conf_name);
    this->SetHost_country(country);
}

void ConferencePaper::citar(ofstream& arch) {
    char nombre[200], titulo[200], conf_name[200], country[200];
    this->GetAuthor_name(nombre);
    this->GetTitle(titulo);
    this->GetConference_name(conf_name);
    this->GetHost_country(country);
    arch << nombre << " (" << this->GetPublication_year() << ")." << endl
            << titulo << '.' << endl
            << conf_name << ". " << country << '.' << endl;
}
