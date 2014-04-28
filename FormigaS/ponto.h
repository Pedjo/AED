/*
 * ponto.h
 *
 *  Created on: 12 de Fev de 2014
 *  Author: AED
 */

#ifndef PONTO_H_
#define PONTO_H_

/* Tipo de dados: ponto */
typedef struct _ponto * ponto;

/* Prototipos das funcoes associadas a um ponto */

/***********************************************
criaPonto - Criacao da instancia da estrutura associada a um ponto.
Parametros:
	x - abcissa do ponto
	y - ordenada do ponto
Retorno: apontador para a  instancia criada
Pre-condicoes:
***********************************************/
ponto criaPonto(double x, double y);

/***********************************************
destroiPonto - Liberta a memoria ocupada pela instancia da estrutura associada ao ponto.
Parametros:
	p - ponto a destruir
Retorno:
Pre-condicoes: p != NULL
***********************************************/
void destroiPonto(ponto p);

/***********************************************
abcissaPonto - consulta da abcissa de um ponto dado.
Parametros:
	p - ponto
Retorno: abcissa do ponto
Pre-condicoes: p != NULL
***********************************************/
double abscissaPonto (ponto p);

/***********************************************
ordenadaPonto - consulta da ordenada de um ponto dado.
Parametros:
	p - ponto
Retorno: ordenada do ponto
Pre-condicoes: p != NULL
***********************************************/
double ordenadaPonto (ponto p);

/***********************************************
distanciaPontos - calcula a distancia entre dois pontos dados.
Parametros:
	p1 - ponto
	p2 - ponto
Retorno: distancia entre os pontos p1 e p2
Pre-condicoes: p1 != NULL && p2 != NULL
***********************************************/
double distanciaPontos (ponto p1, ponto p2);


#endif /* PONTO_H_ */
