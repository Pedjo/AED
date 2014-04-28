#ifndef _FORMIGA_H
#define _FORMIGA_H

typedef struct _formiga * formiga;

// construtor
formiga criaFormiga();

//finalizador
void destroiFormiga(formiga f);

// Tad Functions
void adicionaPontoFormiga(formiga f, ponto p);

void removePontoFormiga(formiga f, int index);

double retDistFormiga(formiga f,int base, int final);

iterador iteradorFormiga(formiga f);

#endif
