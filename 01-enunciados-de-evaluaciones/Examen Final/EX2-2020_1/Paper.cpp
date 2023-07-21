/* 
 * Archivo:   Paper.cpp
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 13 de diciembre de 2020, 11:36 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Paper.h"

Paper::Paper() {
    title = nullptr;
    author_name = nullptr;
}

Paper::Paper(const Paper& orig) {
    title = nullptr;
    author_name = nullptr;
    *this = orig;
}

Paper::~Paper() {
    if (title != nullptr) delete []title;
    if (author_name != nullptr) delete []author_name;
}

void Paper::SetPublication_year(int publication_year) {
    this->publication_year = publication_year;
}

int Paper::GetPublication_year() const {
    return publication_year;
}

void Paper::SetAuthor_name(const char* name) {
    if (author_name) delete []author_name;
    author_name = new char [strlen(name)+1];
    strcpy(author_name,name);
}

void Paper::GetAuthor_name(char* name) const {
    if (!author_name) author_name[0] = '\0';
    strcpy(name,author_name);
}

void Paper::SetTitle(const char* p_title) {
    if (title) delete []title;
    title = new char [strlen(p_title)+1];
    strcpy(title,p_title);
}

void Paper::GetTitle(char* p_title) const {
    if (!title) title[0] = '\0';
    strcpy(p_title,title);
}

void Paper::SetId(int id) {
    this->id = id;
}

int Paper::GetId() const {
    return id;
}

void Paper::operator=(const Paper& orig) {
    char nombre[200], titulo[200];
    this->SetId(orig.GetId());
    this->SetPublication_year(orig.GetPublication_year());
    orig.GetAuthor_name(nombre);
    orig.GetTitle(titulo);
    this->SetAuthor_name(nombre);
    this->SetTitle(titulo);
}