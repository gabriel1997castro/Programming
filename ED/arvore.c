#include <stdio.h>
#include <stdlib.h>

typedef struct ARVORE
{
	char c;
	struct ARVORE *esq,*dir;
}ARVORE;

void Constroi(ARVORE **eainicio,FILE *arq){
	char c;

	if(arq == NULL)
	{
		printf("O arquivo não pode ser aberto!\n");
		return;
	}
	else
	{
		if(c=='.')
		{
			*eainicio = NULL;
		}
		else
		{
			c = fgetc(arq);

			if(c!=EOF)
			{
				*eainicio = malloc(sizeof(ARVORE));
				(*eainicio)->c = c;
				Constroi(&((*eainicio)->esq), arq);
				Constroi(&((*eainicio)->dir), arq);
			}
		}
		
	}

		return;
}

int main()
{
	FILE *arq;
	ARVORE *eainicio;

	arq = fopen("arvore.txt","r");

	Constroi(&eainicio, arq);
	fclose (arq);

	return 0;
}