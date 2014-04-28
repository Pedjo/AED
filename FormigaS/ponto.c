/*
 * ponto.c
 *
 *  Created on: 12 de Fev de 2014
 *  Author: AED
 */

#include "ponto.h"
#include <stdlib.h>
#include <math.h>

/* Estrutura de dados associada a um ponto */
struct _ponto{
	double abcissa;
	double ordenada;
};

/* Implementacao das funcoes associadas a um ponto */

/***********************************************
criaPonto - Criacao da instancia da estrutura associada a um ponto.
Parametros:
	x - abcissa do ponto
	y - ordenada do ponto
Retorno: apontador para a  instancia criada
Pre-condicoes:
***********************************************/
ponto criaPonto(double x, double y){
	ponto p = (ponto) malloc(sizeof(struct _ponto));
	if (p == NULL)
		return NULL;
	p->abcissa = x;
	p->ordenada = y;
	return p;
}

/***********************************************
destroiPonto - Liberta a memoria ocupada pela instancia da estrutura associada ao ponto.
Parametros:
	p - ponto a destruir
Retorno:
Pre-condicoes: p != NULL
***********************************************/
void destroiPonto(ponto p){
	free(p);
}

/***********************************************
abcissaPonto - consulta da abcissa de um ponto dado.
Parametros:
	p - ponto
Retorno: abcissa do ponto
Pre-condicoes: p != NULL
***********************************************/
double abscissaPonto (ponto p){
	return p->abcissa;
}

/***********************************************
ordenadaPonto - consulta da ordenada de um ponto dado.
Parametros:
	p - ponto
Retorno: ordenada do ponto
Pre-condicoes: p != NULL
***********************************************/
double ordenadaPonto (ponto p){
	return p->ordenada;
}

/***********************************************
distanciaPontos - calcula a distancia entre dois pontos dados.
Parametros:
	p1 - ponto
	p2 - ponto
Retorno: distancia entre os pontos p1 e p2
Pre-condicoes: p1 != NULL && p2 != NULL
***********************************************/
double distanciaPontos (ponto p1, ponto p2){
	return sqrt(pow(p1->abcissa - p2->abcissa,2)+pow(p1->ordenada - p2->ordenada,2));
}

