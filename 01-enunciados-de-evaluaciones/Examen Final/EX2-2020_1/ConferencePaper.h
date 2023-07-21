/* 
 * Archivo:   ConferencePaper.h
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 13 de diciembre de 2020, 11:47 PM
 */

#ifndef CONFERENCEPAPER_H
#define CONFERENCEPAPER_H
#include <fstream>
using namespace std;
#include "Paper.h"

class ConferencePaper : public Paper {
private:

    char *conference_name;
    char *host_country;

public:

    ConferencePaper();
    ConferencePaper(const ConferencePaper& orig);
    virtual ~ConferencePaper();
    
    void SetHost_country(const char* country);
    void GetHost_country(char *country) const;
    void SetConference_name(const char* name);
    void GetConference_name(char *name) const;
    
    void operator = (const ConferencePaper& orig);
    
    void leer_datos (ifstream &arch);
    void citar (ofstream &arch);

};
#endif /* CONFERENCEPAPER_H */
