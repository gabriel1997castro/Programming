#include <stdio.h>
#include <stdlib.h>

struct lista{
	char dado;
	struct lista *prox;
};


void construir(struct lista **aux){
	FILE *file;
	struct lista *p1;
	char c;

	file = fopen("a.txt", "r");
	if(file == NULL){
		printf("O arquivo não pode ser aberto\n");
		return;
	}

	*aux = NULL;
	while((c = fgetc(file)) != EOF){
		
		if(c != EOF && c != ' ' && c != '\n'){
			p1 = malloc(sizeof(struct lista));
			p1->dado = c;
			p1->prox = *aux;
			*aux = p1;
		}
	}
	for(;p1->prox != NULL;){
		printf("%c\n", p1->dado);
		p1 = p1->prox;
	}
	printf("%c\n", p1->dado);
	fclose(file);
	return;
}

int main(){
	struct lista *aux;
	construir(&aux);
	return 0;
}