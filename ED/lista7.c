// Lista fechada com encadeamento duplo

#include <stdio.h>
#include <stdlib.h>

struct elemento{
	char dado;
	struct elemento *prox, *ant;
};

void construir_inicio(struct elemento **pinicio){
	FILE *arq;
	struct elemento *p1;
	char c;

	arq = fopen("a.txt","r");
	*pinicio = NULL;
	while((c=fgetc(arq)) != EOF){
		if(c != '\n' && c !=' '){
			p1 = malloc(sizeof(struct elemento));
			p1->dado = c;
			if(*pinicio == NULL){
				p1->prox = p1;
				p1->ant = p1;
				*pinicio = p1;
			}
			else{
				p1->prox = (*pinicio);
				p1->ant = (*pinicio)->ant;
				(*pinicio)->ant->prox = p1;
				(*pinicio)->ant = p1;
				*pinicio = p1;
			}
		}
	}
	

	fclose(arq);
	free(p1);
	return;
}

void construir_final(struct elemento **pinicio){
	FILE *arq;
	struct elemento *p1, *p2;
	char c;

	arq = fopen("a.txt","r");
	*pinicio = NULL;
	while((c = getc(arq)) != EOF){
		if(c != '\n' && c !=' '){
			p1=malloc(sizeof(struct elemento));
			p1->dado=c;
		}
		if(*pinicio == NULL){
			p1->prox = p1;
			p1->ant = p1;
			*pinicio = p1;
		}
		else{
			p1->prox = *pinicio;
			p1->ant = p2;
			p2->prox = p1;
			(*pinicio)->ant = p1;
		}
		p2 = p1;
	}
	fclose(arq);
	return;
}

void imprimir(struct elemento **pinicio){
	struct elemento *p1;

	if(pinicio == NULL)
		printf("Elemento: %c\n", p1->dado);
	else{
		p1 = *pinicio;
		do{
			printf("Elemento: %c\n", p1->dado);
			p1 = p1->prox;
		}while(p1 != *pinicio);
		do{
			p1 = p1->ant;
			printf("Elemento(para tras): %c\n", p1->dado);
		}while(p1!= *pinicio);
	}
	return;
}

void *procurar(struct elemento *pinicio,char chave){
	struct elemento *p1;

	if(pinicio == NULL)
		p1 = NULL;
	else{
		p1 = pinicio;
		do
			p1 = p1->prox;
		while((p1!=pinicio)&&(p1->dado!=chave));
			p1 = NULL;
	}
	return p1;
}

int main(){
	struct elemento *pinicio;
	construir_inicio(&pinicio);
	imprimir(&pinicio);
	return 0;
}