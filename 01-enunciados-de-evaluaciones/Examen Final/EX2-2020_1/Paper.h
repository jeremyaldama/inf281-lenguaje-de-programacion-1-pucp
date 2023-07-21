/* 
 * Archivo:   Paper.h
 * Autor: Oscar Dueñas Damian - Oscar DD.
 * Codigo PUCP: 20180146
 * Created on 13 de diciembre de 2020, 11:36 PM
 */

#ifndef PAPER_H
#define PAPER_H
#include <fstream>
using namespace std;

class Paper {
private:

    int id;
    char *title;
    char *author_name;
    int publication_year;

public:

    Paper();
    Paper(const Paper& orig);
    virtual ~Paper();
    
    void SetPublication_year(int publication_year);
    int GetPublication_year() const;
    void SetAuthor_name(const char* name);
    void GetAuthor_name(char *name) const;
    void SetTitle(const char* p_title);
    void GetTitle(char *p_title) const;
    void SetId(int id);
    int GetId() const;
    
    void operator = (const Paper &orig);
    
    virtual void leer_datos (ifstream &arch) = 0;
    virtual void citar (ofstream &arch) = 0;

};
#endif /* PAPER_H */
