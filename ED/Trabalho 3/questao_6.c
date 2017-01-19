#include <stdio.h>
#include <stdlib.h>

typedef struct ARVORE{
	char c;
	struct ARVORE *esq,*dir;
}ARVORE;

/*-----------------------------------------------------------------*/

void Constroi(ARVORE **eainicio,FILE *arq){
	char c;
	c = fgetc(arq);
	if(c=='.'){
		*eainicio = NULL;
	}
	else{	
		*eainicio = malloc(sizeof(ARVORE));
		(*eainicio)->c = c;
		Constroi(&((*eainicio)->esq), arq);
		Constroi(&((*eainicio)->dir), arq);
	}
}

/*-----------------------------------------------------------------*/
ARVORE *ProcuraAnt(ARVORE **inicio, char chave, ARVORE **pai){
	ARVORE *a1;
	
	*pai = NULL;
	a1 = *inicio;
	while((a1 != NULL) && (a1->c != chave)){
		if(a1->c != chave){
			if(chave < a1->c){
				*pai = a1;
				a1 = a1->esq;
			}
			
			else{
				*pai = a1;
				a1 = a1->dir;
			}
		}
	}
	return a1;
}

/*-----------------------------------------------------------------*/
void Remove(ARVORE **eainicio) {
    if (*eainicio != NULL) {
        Remove (&((*eainicio)->esq));
        Remove (&((*eainicio)->dir));
        free (*eainicio);
        *eainicio = NULL;
    }
}

/*-----------------------------------------------------------------*/
void RemoveMenorIgual(ARVORE **inicio, char c){
	ARVORE *a1, *antes;

	antes = NULL;
	a1 = ProcuraAnt(inicio, c, &antes);
	if(a1 == *inicio)
		NULL;
	else{
		if(a1 != NULL){
			if(a1 == antes->esq){
				antes->esq = a1->dir;
				a1->dir = NULL;
				Remove(&a1);
			}
			if(a1 == antes->dir){
				antes->dir = a1->dir;
				a1->dir = NULL;
				Remove(&a1);
			}
		}
	}
}
/*-----------------------------------------------------------------*/
void LeArv(ARVORE *inicio){
	if(inicio == NULL)
		printf(".");
	else{
		printf("%c", inicio->c);
		LeArv(inicio->esq);
		LeArv(inicio->dir);
	}
}

/*-----------------------------------------------------------------*/
int main(){	
	char remove;
	FILE *arq;
	ARVORE *eainicio;
	arq = fopen("arvoredebusca.txt","r");

	if(arq == NULL){
		printf("O arquivo não pode ser aberto!\n");
		return 0;
	}

	Constroi(&eainicio, arq);
	fclose (arq);	
	LeArv(eainicio);
	printf("\nDigite o elemento que é chave para remoção dele e de todos os menores que ele:\n");
	scanf("%c", &remove);
	getchar();
	RemoveMenorIgual(&eainicio, remove);
	LeArv(eainicio);
	printf("\n");
	return 0;
}