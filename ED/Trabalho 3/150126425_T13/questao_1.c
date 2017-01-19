#include <stdio.h>
#include <stdlib.h>

typedef struct ARVORE{
	char c;
	struct ARVORE *esq,*dir;
}ARVORE;

//--------------------------------------------------------------
void Constroi(ARVORE **eainicio,FILE *arq){
	char c;
	c = fgetc(arq);
	if(c=='.'){
		*eainicio = NULL;
		return;
	}
	else{	
		if(c!=EOF && c!='\n' && c !=' '){
			*eainicio = malloc(sizeof(ARVORE));
			(*eainicio)->c = c;
			Constroi(&((*eainicio)->esq), arq);
			Constroi(&((*eainicio)->dir), arq);
		}
	}
}

//--------------------------------------------------------------
void Mostra_elementos(ARVORE *inicio){
	if(inicio != NULL){
		printf("%c ", inicio->c);
		Mostra_elementos(inicio->esq);
		Mostra_elementos(inicio->dir);
	}
}

//--------------------------------------------------------------
int main(){
	FILE *arq;
	ARVORE *eainicio, *procura;
	arq = fopen("arvore.txt","r");

	if(arq == NULL){
		printf("O arquivo não pode ser aberto!\n");
		return 0;;
	}

	Constroi(&eainicio, arq);
	fclose (arq);
	printf("Elementos contidos na árvore:\n");
	Mostra_elementos(eainicio);
	printf("\n");	
	return 0;
}