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
int Iguais(ARVORE *ea0,ARVORE *ea1){
	if((!ea0 && ea1) || (!ea1 && ea0))
		return 1;
	if((ea0 != NULL) && (ea1 != NULL)){
		if(ea0->c != ea1->c)
			return 1;
		return Iguais(ea0->esq, ea1->esq)+Iguais(ea0->dir, ea1->dir);
	}
	if((ea0 == NULL) && (ea1 == NULL))
		return 0;
}

//--------------------------------------------------------------
int main(){
	int iguais;
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
	iguais = Iguais(eainicio, eainicio1);
	if(iguais==0)
		printf("São iguais\n");
	else
		printf("São diferentes\n");
	return 0;
}