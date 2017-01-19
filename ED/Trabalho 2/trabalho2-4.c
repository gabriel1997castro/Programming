#include <stdio.h>
#include <stdlib.h>

//--------------------------------------------------------------------------//
typedef struct elemento_fone
{
	int fone;
	struct elemento_fone *proxF;
}elemento_fone;

//--------------------------------------------------------------------------//
typedef struct elemento_central
{
	char central;
	struct elemento_central *proxC;
	struct elemento_fone *pfone;
}elemento_central;

//--------------------------------------------------------------------------//
void construirMalha(elemento_central **pacesso)
{
	FILE *arq;
	elemento_central *pc1,*pc2;
	elemento_fone *pf1,*pf2;
	char c;
	int i,n,m;

	arq = fopen("t2-4.txt", "r");

	*pacesso = NULL;
	while((c = getc(arq)) != EOF)
	{
		if(c!='\n')
		{
			pc1 = malloc(sizeof(elemento_central));
			pc1->central = c;
			pc1->pfone = NULL;
			pc1->proxC = NULL;
			if(*pacesso == NULL)
				*pacesso = pc1;
			else
				pc2->proxC = pc1;
			pc2 = pc1;
			fscanf (arq, "%d ", &n);
			for(i=1;i!=n+1;i++){
				fscanf(arq, "%d", &m);
				pf1 = malloc(sizeof(elemento_fone));
				pf1->fone = m;
				pf1->proxF = NULL;
				if(pc1->pfone == NULL)
					pc1->pfone = pf1;
				else 
					pf2->proxF = pf1;
				pf2 = pf1;
			}
		}
	}
	fclose(arq);
	return;
}

//--------------------------------------------------------------------------//
void PercorreMalha(elemento_central *pacesso) 
{
	elemento_central *pc1;
	elemento_fone *pf1;

	if (pacesso == NULL)
		printf ("lista vazia \n");
	else {          
		pc1 = pacesso;     
		while (pc1 != NULL) 
		{
			printf("\n %c", pc1->central);
			pf1 = pc1->pfone;
			while (pf1 != NULL) 
			{
				printf("%5d", pf1->fone);
				pf1 = pf1->proxF;
			}
			pc1 = pc1->proxC;   
		}
	}     

	printf("\n");
}     

//--------------------------------------------------------------------------//
int main()
{
	elemento_central *pacesso;
	FILE *arq;

	arq = fopen("t2-4.txt", "r");
	if(!arq)
	{
		printf("O arquivo (t2-4.txt) não pode ser aberto\n");
		getchar();
		return 0;
	}
	fclose(arq);

	construirMalha(&pacesso);
	PercorreMalha(pacesso);
	return 0;
}

