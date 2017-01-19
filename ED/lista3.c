#include <stdio.h>
#include <stdlib.h>

struct lista{
	char dado;
	struct lista *prox;
};

struct lista *aux, *p1;

int main(){
	aux = NULL;
	p1 = malloc(sizeof(struct lista));
	p1->dado = 'a';
	p1->prox = aux;
	aux = p1;

	p1 = malloc(sizeof(struct lista));
	p1->dado = 'b';
	p1->prox = aux;
	aux = p1;

	p1 = malloc(sizeof(struct lista));
	p1->dado = 'c';
	p1->prox = aux;
	aux = p1;

	for(;p1->prox != NULL;){
		printf("%c\n", p1->dado);
		p1 = p1->prox;
	}
	printf("%c\n", p1->dado);
	return 0;
}
/*Nessa lista seus elementos são alocados na contrária a que eles
são pegos*/