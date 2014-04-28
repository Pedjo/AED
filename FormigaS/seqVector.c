#include <stdlib.h>
#include "iterador.h"
#include "sequencia.h"

/* Estrutura de dados: sequencia implementada em vector */
struct _sequencia{
	void * * elems; // apontador para vector de enderecos de elementos
	int numElems;
	int capacidade; // capacidade corrente do vector
};

/* Prototipos das funcoes associadas a uma sequencia */

/***********************************************
criaSequencia - Criacao da instancia da estrutura associada a uma sequencia.
Parametros:
	cap - capacidade prevista da sequencia
Retorno: apontador para a  instancia criada
Pre-condicoes:
***********************************************/
sequencia criaSequencia(int cap){
	sequencia s = (sequencia)malloc(sizeof(struct _sequencia));
	
	if(s == NULL)
		return NULL;
	s->elems = (void **)malloc(sizeof(void*)*cap);
	if(s->elems == NULL){
		free(s);
		return NULL;
	}
	s->numElems = 0;
	s->capacidade = cap;
	return s;
}

/***********************************************
destroiSequencia - Liberta a memoria ocupada pela instancia da estrutura associada à sequencia.
Parametros:
	s - sequencia a destruir
Retorno:
Pre-condicoes: s != NULL
***********************************************/
void destroiSequencia (sequencia s ){
	free(s->elems);
	free(s);
}

/***********************************************
destroiSeqEElems - Liberta a memoria ocupada pela instancia da estrutura associada à sequencia e os elementos.
Parametros:
	s - sequencia a destruir
	destroi - função para destruição os elementos contidos na sequencia
Retorno:
Pre-condicoes: s != NULL
***********************************************/
void destroiSeqElems(sequencia s, void (*destroi)(void *) ){
	int i;
	
	for(i = 0; i< s->numElems;i++)
		destroi(s->elems[i]);
	destroiSequencia(s);
}

/***********************************************
vaziaSequencia - Indica se a sequencia está vazia.
Parametros:
	s - sequencia
Retorno: 1- caso sequencia vazia; 0 - caso contrário
Pre-condicoes: s != NULL
***********************************************/
int vaziaSequencia(sequencia s){
	return (s->numElems == 0);
}

/***********************************************
tamanhoSequencia - Consulta o numero de elementos na sequencia.
Parametros:
	s - sequencia
Retorno: numero de elementos na sequencia
Pre-condicoes: s != NULL
***********************************************/
int tamanhoSequencia(sequencia s){
	return s->numElems;
}

/***********************************************
elementoPosSequencia - Consulta o elemento i-esimo na sequencia.
Parametros:
	s - sequencia
	i - posicao na sequencia
Retorno: endereco do elemento
Pre-condicoes: s != NULL && i>0 && i<= tamanhoSequencia(s)
***********************************************/
void * elementoPosSequencia(sequencia s, int i){
	if(i < 1 || i > s->numElems)
		return NULL;
	return s->elems[i-1];
}

/***********************************************
adicionaPosSequencia - Adiciona o elemento dado na posicao i da sequencia.
Parametros:
	s - sequencia
	elem - endereco do elemento
	i - posicao na sequencia
Retorno:
Pre-condicoes: s != NULL && i>0 && i<= tamanhoSequencia(s)+1
***********************************************/
void adicionaPosSequencia(sequencia s, void * elem, int i){
	int j;
	
	if(i < 1 || i > tamanhoSequencia(s)+1)
		return;
	if(s->numElems < s->capacidade){
		j = s->numElems;
		for(	; j >= i; j--)
			s->elems[j] = s->elems[j-1];
		s->elems[j] = elem;
	}
	else{
		void ** aux = (void **)malloc(sizeof(void *)*s->capacidade*2);
		
		if(aux == NULL)
			return;
		i--; // posicao do novo elem
		aux[i] = elem; // mete novo elem
		for(j = 0; j < s->capacidade; j++)
			if(j < i) // meter elems com index menor ao novo elem
				aux[j] = s->elems[j];
			else // meter elems com index superior ou igual ao novo elem
				aux[j+1] = s->elems[j];
		free(s->elems);
		s->elems = aux;
		s->capacidade *= 2;
	}
	s->numElems++;
}

/***********************************************
removePosSequencia - Remove o elemento na posicao i da sequencia.
Parametros:
	s - sequencia
	i - posicao na sequencia
Retorno: retorna o elemento
Pre-condicoes: s != NULL && i>0 && i<= tamanhoSequencia(s)
***********************************************/
void * removePosSequencia(sequencia s, int i){
	void * elem;
	
	if(i < 1 || i >tamanhoSequencia(s))
		return NULL;
	
	elem = s->elems[i-1];
	for(	; i < s->numElems;i++)
		s->elems[i-1] = s->elems[i];
	s->numElems--;
	return elem;
}

/***********************************************
iteradorSequencia - Cria e devolve um iterador para a sequencia.
Parametros:
	s - sequencia
Retorno: iterador da sequencia
Pre-condicoes: s != NULL && vaziaSequencia(s)!=1
***********************************************/
iterador iteradorSequencia(sequencia s){
	//CUIDADO: DEVE DAR AO ITERADOR UMA COPIA DO VECTOR A PERCORRER
	void ** aux = (void **)malloc(sizeof(void *)*s->numElems);
	int i;
	
	if(aux == NULL)
		return NULL;
	
	for(i = 0; i < s->numElems; i++)
		aux[i] = s->elems[i];
	
	return criaIterador(aux,s->numElems);
}
