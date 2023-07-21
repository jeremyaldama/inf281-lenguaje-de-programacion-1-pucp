/* 
 * Archivo:   JournalPaper.h
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 13 de diciembre de 2020, 11:58 PM
 */

#ifndef JOURNALPAPER_H
#define JOURNALPAPER_H
#include <fstream>
using namespace std;
#include "Paper.h"

class JournalPaper : public Paper {
private:

    char *journal_name;
    int volume;

public:

    JournalPaper();
    JournalPaper(const JournalPaper& orig);
    virtual ~JournalPaper();
    
    void SetVolume(int volume);
    int GetVolume() const;
    void SetJournal_name(const char* name);
    void GetJournal_name(char *name) const;
    
    void operator = (const JournalPaper& orig);
    
    void leer_datos (ifstream &arch);
    void citar (ofstream &arch);

};
#endif /* JOURNALPAPER_H */
