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
int Isomorfas(ARVORE *ea0,ARVORE *ea1){
	if((!ea0 && ea1) || (!ea1 && ea0))
		return 1;
	if((ea0 != NULL) && (ea1 != NULL)){
		return Isomorfas(ea0->esq, ea1->esq)+Isomorfas(ea0->dir, ea1->dir);
	}
	if((ea0 == NULL) && (ea1 == NULL))
		return 0;
}


//--------------------------------------------------------------
int main(){
	int isomorfas;
	FILE *arq,*arq1;
	ARVORE *eainicio, *eainicio1, *procura;
	arq = fopen("arvore.txt","r");

	if(arq == NULL){
		printf("O arquivo não pode ser aberto!\n");
		return 0;;
	}
	arq1 = fopen("arvore1.txt","r");

	if(arq1 == NULL){
		printf("O arquivo não pode ser aberto!\n");
		return 0;;
	}

	Constroi(&eainicio, arq);
	Constroi(&eainicio1, arq1);
	fclose (arq);
	fclose (arq1);	
	isomorfas = Isomorfas(eainicio, eainicio1);
	if(isomorfas==0)
		printf("São isomorfas\n");
	else
		printf("Não são isomorfas\n");
	return 0;
}
