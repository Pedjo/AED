/*
	Autor: 	Carlos Pinto Machado
	Data:	13/06/2013
	Nome:	pergunta2B.c
	Descrição:	resolução da Pergunta 2B do 1º teste de AED, 2012/13
	Observações:	Optou-se pela opção C da pergunta 2A
*/
#include <stdlib.h>
#include <string.h>

#include "iterador.h"	//iterador
#include "sequencia.h"	//sequencia
#include "visita.h"		//TAD visita
#include "visitaGen.h"	//funções que tratam a visita como void *
#include "percursoParque.h"	//TAD percursoParque

struct _percurso{
	int numeroCrianca;
	sequencia percurso; // sequência de visitas
	visita maxUltVisita; // última visita com máxima pontuação
};

percursoParque criaPercurso(int nCrianca, int nVis){
	percursoParque p = (percursoParque)malloc(sizeof(struct _percurso));
	
	if(p==NULL)
		return NULL;
	p->percurso = criaSequencia(nVis);//criar sequencia da visita
	if(p->percurso == NULL){
		free(p);
		return NULL;
	}
	p->maxUltVisita = NULL; // começa inicializado como NULL
	p->numeroCrianca = nCrianca;
	return p;
}

void destroiPercurso(percursoParque p){
	destroiSeqElems(p->percurso,destroiVisitaGen);
	free(p);
}

void adicionaVisPercurso(percursoParque p, char * nomeDiv, int pontosVis){
	int i;//variavel auxiliar
	visita v = criaVisita(nomeDiv,pontoVis);
	
	if(v==NULL)//verificar se conseguimos alocar espaço para a visita
		return;
	i = tamanhoSequencia(p->percurso)+1;//a posição a seguir à ultima na sequencia, vejam os parâmetros da função abaixo
	adicionaPosSequencia(p->percurso,(void*)v,i);//adiciona à sequencia
	if(p->maxUltVisita == NULL)//Se for NULL ou tiver mais ou o mesmo numero de pontos que a ultima visita com mais pontos, substitui-se
		p->maxUltVisita = v;
	else
		if(pontosVis >= pontosVisita(p->maxUltVisita))//separado assim, porque
			p->maxUltVisita = v;					// temos de utilizar a função pontosVisita, que pressupoe que não tem um parametro NULL
}

int tamanhoPercurso(percursoParque p){
	return tamanhoSequencia(p->percurso);
}

visita visitaPercurso(percursoParque p, int i){
	if(i>tamanhoSequencia(p->percurso))//verificar o prerequisito que é i <= tamanhoSequencia
		return NULL;//Isto é facultativo, mas eu recomendo
	return (visita)elementoPosSequencia(p->percurso,i);
}

visita maxVisitaPercurso(percursoParque p){
	return p->maxUltVisita;
}

int numVisitaPercurso(percursoParque p, char * nomeDis){
	iterador it;//iterador
	visita v=NULL;	//variavel auxiliar
	int i = 0;	//contador
	
	if(tamanhoSequencia(p->percurso)){//pre-requisito de qualquer iterador é a existência de pelo menos um elemento
		it = iteradorSequencia(p->percurso);
		if(it!=NULL){//verificar se iterador foi criado
			while(temSeguinteIterador(it)){
				v = (visita)seguinteIterador(it);
				if(!strcmp(nomeDis,diversaoVisita(v)))
					i++;
			}
			destroiIterador(it);//destruir o iterador
		}
		else
			return -1; // isto é facultativo, mas, nos meus programas, eu costumo meter certos valores que apontam certos erros do sistema.
	}
	return i;
}

iterador iteradorPercurso(percursoParque p){
	return iteradorSequencia(p->percurso);
}
