/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Docente.h
 * Author: Danie
 *
 * Created on 8 de julio de 2023, 22:29
 */

#ifndef DOCENTE_H
#define DOCENTE_H
#include "Usuario.h"

class Docente : public Usuario {
public:
    Docente();
    Docente(const Docente& orig);
    virtual ~Docente();
    void SetAnexo(int anexo);
    int GetAnexo() const;
    void leer(ifstream&arch);
private:
    int anexo;
};

#endif /* DOCENTE_H */

