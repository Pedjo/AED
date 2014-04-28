#include <stdlib.h>

#include "ponto.h"
#include "pontoGen.h"
#include "iterador.h"
#include "sequencia.h"
#include "formiga.h"

#define CAP 50

struct _formiga{
	sequencia pontos;
};

// construtor
formiga criaFormiga(){
	formiga f = (formiga)malloc(sizeof(struct _formiga));
	
	if(f == NULL)
		return NULL;
	f->pontos = criaSequencia(CAP);
	if(f->pontos == NULL){
		free(f);
		return NULL;
	}
	return f;
}

//finalizador
void destroiFormiga(formiga f){
	destroiSeqElems(f->pontos,destroiPontoGen);
	free(f);
}

// Tad Functions
void adicionaPontoFormiga(formiga f, ponto p){
	adicionaPosSequencia(f->pontos,(void*)p,tamanhoSequencia(f->pontos)+1);
}

void removePontoFormiga(formiga f, int index){
	void * aux = removePosSequencia(f->pontos,index);
	
	if(aux != NULL)
		destroiPontoGen(aux);
}

double retDistFormiga(formiga f,int base, int final){
	int i;
	double per = 0;
	ponto e1;
	ponto e2;
	
	if(base > final || final > tamanhoSequencia(f->pontos))
		return -1;
	
	e1 = (ponto)elementoPosSequencia(f->pontos,base);
	for(i = base+1; i <= final; i++){ // somar a distancia de i com i-1
		e2 = (ponto)elementoPosSequencia(f->pontos,i);
		per+= distanciaPontos(e1,e2);
		e1 = e2;
	}
	return per;
}

iterador iteradorFormiga(formiga f){
	return iteradorSequencia(f->pontos);
}
