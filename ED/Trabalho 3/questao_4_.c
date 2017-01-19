#include <stdio.h>
#include <stdlib.h>

typedef struct ARVORE
{
	char c;
	struct ARVORE *esq,*dir;
}ARVORE;

//--------------------------------------------------------------
void Constroi(ARVORE **eainicio,FILE *arq)
{
	char c;
	c = fgetc(arq);
	if(c=='.')
	{
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
int ContarNos(ARVORE *eainicio)
{
	if(eainicio == NULL)
		return 0;
	else 
		return 1 + ContarNos(eainicio->esq)+ContarNos(eainicio->dir);
}

//--------------------------------------------------------------
int Iguais(ARVORE *ea0,ARVORE *ea1)
{
	if((!ea0 && ea1) || (!ea1 && ea0))
		return 1;
	if((ea0 != NULL) && (ea1 != NULL))
	{
		if(ea0->c != ea1->c)
			return 1;
		return Iguais(ea0->esq, ea1->esq)+Iguais(ea0->dir, ea1->dir);
	}
	if((ea0 == NULL) && (ea1 == NULL))
		return 0;
}

//--------------------------------------------------------------
int MostraContaFilhos(ARVORE *ea)
{
	int a;
	if(ea == NULL)
		return 0;
	else
	{
		a = MostraContaFilhos(ea->esq)+MostraContaFilhos(ea->dir);
		printf("%c         |%d\n", ea->c, a);

		return 1 + a;
	}
}

//--------------------------------------------------------------
int main()
{
	FILE *arq,*arq1;
	ARVORE *eainicio, *eainicio1, *procura;
	arq = fopen("arvore.txt","r");

	if(arq == NULL)
	{
		printf("O arquivo não pode ser aberto!\n");
		return 0;;
	}
	arq1 = fopen("arvore1.txt","r");

	if(arq1 == NULL)
	{
		printf("O arquivo não pode ser aberto!\n");
		return 0;;
	}

	Constroi(&eainicio, arq);
	Constroi(&eainicio1, arq1);
	fclose (arq);
	fclose (arq1);

	printf("Elementos |filhos\n");	
	MostraContaFilhos(eainicio);

	return 0;
}