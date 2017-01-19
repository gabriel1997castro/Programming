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
void LeArv(ARVORE *inicio)
{
	if(inicio == NULL)
	{
		printf(".");
	}
	else
	{
		printf("%c", inicio->c);
		LeArv(inicio->esq);
		LeArv(inicio->dir);
	}
	
}

//--------------------------------------------------------------
void CaminhaPre1(ARVORE *inicio)
{
	if(inicio != NULL)
	{
		printf("%c", inicio->c);
		CaminhaPre1(inicio->esq);
		CaminhaPre1(inicio->dir);
	}
}

//--------------------------------------------------------------
void CaminhaPre2(ARVORE *inicio)
{
	printf("%c", inicio->c);
	if(inicio->esq != NULL)
		CaminhaPre2(inicio->esq);
	if(inicio->dir != NULL)
		CaminhaPre2(inicio->dir);
}

//--------------------------------------------------------------
void CaminhaIn(ARVORE *inicio)
{
	if(inicio != NULL)
	{
		CaminhaIn(inicio->esq);
		printf("%c", inicio->c);
		CaminhaIn(inicio->dir);
	}
}

//--------------------------------------------------------------
void CaminhaPos(ARVORE *inicio){
	if(inicio != NULL){
		CaminhaPos(inicio->esq);
		CaminhaPos(inicio->dir);
		printf("%c", inicio->c);
	}
}

//--------------------------------------------------------------
void Remove(ARVORE **inicio)
{
	if(*inicio != NULL)
	{
		Remove(&((*inicio)->esq));
		Remove(&((*inicio)->dir));
		free(*inicio);
		*inicio = NULL;
	}
}

//--------------------------------------------------------------
void *Procura(ARVORE *inicio, char chave){
	ARVORE *a1;
	if(inicio != NULL){
		if(inicio->c == chave)
			a1 = inicio;
		if(a1 == NULL)
			a1 = Procura(inicio->esq, chave);
		if(a1 == NULL)
			a1 = Procura(inicio->dir, chave);
	}
	return a1;
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
int Isomorfas(ARVORE *ea0,ARVORE *ea1)
{
	if((!ea0 && ea1) || (!ea1 && ea0))
		return 1;
	if((ea0 != NULL) && (ea1 != NULL))
	{
		return Isomorfas(ea0->esq, ea1->esq)+Isomorfas(ea0->dir, ea1->dir);
	}
	if((ea0 == NULL) && (ea1 == NULL))
		return 0;
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
void Mostra_elementos(ARVORE *inicio)
{
	if(inicio != NULL)
	{
		printf("%c ", inicio->c);
		Mostra_elementos(inicio->esq);
		Mostra_elementos(inicio->dir);
	}

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
	FILE *arq;
	ARVORE *eainicio, *procura;
	arq = fopen("arvore.txt","r");

	if(arq == NULL)
	{
		printf("O arquivo não pode ser aberto!\n");
		return 0;;
	}

	Constroi(&eainicio, arq);
	fclose (arq);
	printf("Lê arvore\n");
	LeArv(eainicio);
	getchar();
	printf("\n");
	system("clear");
	CaminhaPre1(eainicio);
	//getchar();
	//if(eainicio != NULL) CaminhaPre2(eainicio);
	//getchar();
	//CaminhaIn(eainicio);
	//printf("\n");
	//getchar();
	//Remove(&eainicio);
	//CaminhaPos(eainicio);
	//printf("\n");
	//Remove(&eainicio);
	procura = Procura(eainicio, 'A');
	getchar();
	printf("aaaaaaaaaaaaa%c\n", procura->c);
	

	return 0;
}