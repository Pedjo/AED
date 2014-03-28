/*
	Autor: 	Carlos Pinto Machado
	Data:	13/06/2013
	Nome:	pergunta3.c
	Descrição:	resolução da Pergunta 3 do 1º teste de AED, 2012/13
	Observações:
*/

void listaDiversoes(percursoParque p){
	iterador it;
	int i = tamanhoPercurso(p);
	visita v; // variavel auxiliar
	
	if(i){
		it = iteradorPercurso(p);
		if(it!=NULL){//verificar se iterador foi criado
			while(temSeguinteIterador(it)){
				v = (visita)seguinteIterador(it);
				i = pontosVisita(v);
				printf("%s\t%d\n",diversaoVisita(v),i);
			}
			destroiIterador(it);//destruir o iterador
		}
		else
			puts("Sem espaço para iterador");//facultativo
	}
	else
		puts("Sem visitas");
}