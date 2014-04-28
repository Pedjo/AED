#include <stdio.h>
#include <ctype.h>

#include "iterador.h"
#include "ponto.h"
#include "sequencia.h"
#include "formiga.h"

void inter(formiga f);

void interReg(formiga f, char * reader);

void interDist(formiga f, char * reader);

void interRem(formiga f,char * reader);

void interList(formiga f);

int main(int argc, char ** argv){
	formiga f = criaFormiga();
	inter(f);
	destroiFormiga(f);
	return 0;
}


void inter(formiga f){
	char reader[90];
	char ch;
	
	do{
		printf(">");
		fgets(reader,90,stdin);
		ch = toupper(reader[0]);
		switch(ch){
			case 'A': interReg(f,reader); break;
			case 'R': interRem(f,reader);break;
			case 'L': interList(f);break;
			case 'D': interDist(f,reader);
			case 'S': break;
			default: puts(">Command not implemented");		
		}
	}while(ch != 'S');
	puts(">End of program");
}

void interReg(formiga f, char * reader){
	double x,y;
	ponto p;
	if(sscanf(reader," %*c %lf %lf",&x,&y)!= 2){
		puts(">Invalid Input");
		return;
	}
	p = criaPonto(x,y);
	if(p == NULL)
		puts(">No memory available");
	else
		adicionaPontoFormiga(f,p);
}

void interDist(formiga f, char * reader){
	int x,y;
	double dist;
	
	if(sscanf(reader," %*c %d %d",&x,&y)!= 2){
		puts(">Invalid Input");
		return;
	}
	dist = retDistFormiga(f,x,y);
	
	if(dist == -1)
		puts(">Invalid indexs");
	else
		printf(">The distance is %.2lf\n",dist);
}

void interRem(formiga f,char * reader){
	int x;
	
	if(sscanf(reader," %*c %d",&x)!= 1){
		puts(">Invalid Input");
		return;
	}
	removePontoFormiga(f,x);
}

void interList(formiga f){
	iterador it = iteradorFormiga(f);
	
	if(it == NULL){
		puts(">Memory or empty points problem");
		return;
	}
	
	while(temSeguinteIterador(it)){
		ponto p = (ponto)seguinteIterador(it);
		printf(">(%lf,%lf)\n",abscissaPonto(p),ordenadaPonto(p));
	}
	destroiIterador(it);
}
