/*
	Autor: 	Carlos Pinto Machado
	Data:	13/06/2013
	Nome:	pergunta1.c
	Descrição:	resolução da Pergunta 1 do 1º teste de AED, 2012/13
	Observações:	
*/
#include <stdlib.h>
#include <string.h>

#include "visita.h"//TAD visita

#define TAM 50 // neste teste a professora não estava preocupada com eficiência, 
			  //por isso utilizei um tamanho standard para as strings

struct _visita{
	char nome[TAM];//nome da diversão
	int pontos;//pontuação da diversão
};


visita criaVisita(char * nomeDiv, int pontosDiv){
	visita v = (visita)malloc(sizeof(struct _visita));//alocação de memória
	
	if(v == NULL)//verificar se foi possível alocar memória
		return NULL;
	v->pontos = pontosDiv;//atribuir os pontos
	strcpy(v->nome,nomeDiv);//atribuir o nome
	return v;
}

void destroiVisita(visita v){
	free(v);//simplesmente libertar a memória alocada
}

char * diversaoVisita(visita v){
	return v->nome; // retorna o nome da visita
}

int pontosVisita(visita v){
	return v->pontos;//retorna os pontos da visita
}
