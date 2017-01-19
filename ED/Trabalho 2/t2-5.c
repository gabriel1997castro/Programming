#include <stdio.h>
#include <stdlib.h>

typedef struct LISTA{
	int dado;
	struct LISTA *ant,*prox;
}LISTA;

//---------------------------------------------------------------------------------------------------------------------------------------------------------//
void construir_final(LISTA **pinicio, FILE *arq) 
{
	LISTA *p1, *p2;
	int c;

	(*pinicio) = NULL;
	while ((fscanf(arq,"%d",&c)) != EOF) 
	{
		p1 = malloc (sizeof (struct LISTA));
		p1->dado = c;
		p1->prox = NULL;
		if (*pinicio == NULL) 
		{
			*pinicio = p1;
			p1->ant = NULL;
		}
		else 
		{
			p2->prox = p1;
			p1->ant = p2;
		}
		p2 = p1;
	}
	p1 = NULL;
	free(p1);
	return;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------//
void imprimir_lista(LISTA **pinicio)
{
	int i;
	LISTA *p1;
	
	if(*pinicio == NULL)
	{
		printf("Lista vazia!\n");
		return;
	}
	else
	{
		p1 = *pinicio;
		i=1;
		printf("\n");
		while(p1 != NULL)
		{
			printf("Elemento %3d: %3d\n",i, p1->dado);
			p1 = p1->prox;
			i++;
		}
	}
	printf("\nTecle enter...\n");
	getchar();
	return;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------//
void lista_intercalada(LISTA **pinicio1, LISTA **pinicio2 ,LISTA **pinicio3)
{
	LISTA *p1, *p2, *p3, *p4;
	int i=0;
	if(*pinicio1 == NULL)
	{
		printf("Lista 1 vazia!\n");
	}
	if(*pinicio2 == NULL)
	{
		printf("Lista 2 vazia!\n");
	}
	else
	{
		p1 = *pinicio1;
		p2 = *pinicio2;
		p3 = *pinicio3;

		*pinicio3 = NULL;
		while(p2 != NULL)
		{
			if(i%2==0)
			{
				p3 = malloc(sizeof(LISTA));
				p3->dado = p1->dado;
				p3->prox = NULL;
				if(*pinicio3 == NULL)
				{
					*pinicio3 = p3;
					p3->ant = NULL;
				}
				else
				{
					p4->prox = p3;
					p3->ant = p4;
				}
				p4 = p3;
				p1 = p1->prox;
			}
			else
			{
				p3 = malloc(sizeof(LISTA));
				p3->dado = p2->dado;
				p3->prox = NULL;
				if(*pinicio3 == NULL)
				{
					*pinicio3 = p3;
					p3->ant = NULL;
				}
				else
				{
					p4->prox = p3;
					p3->ant = p4;
				}
				p4 = p3;
				p2 = p2->prox;
			}
			i++;
		}
	}
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------//
int main()
{
	LISTA *pinicio1,*pinicio2,*pinicio3;
	FILE *arq1,*arq2;

		arq1 = fopen ("lista_ordenada1.txt", "r");
		arq2 = fopen ("lista_ordenada2.txt", "r");
	if((!arq1) || (!arq2))
	{
		pinicio1 = NULL;
		pinicio2 = NULL;
		printf("Um dos arquivos ou ambos não podem ser abertos!\n");
		getchar();
		return 0;
	}

	construir_final(&pinicio1, arq1);
	construir_final(&pinicio2, arq2);
	system("clear");
	printf("LISTA 1");
	imprimir_lista(&pinicio1);
	printf("LISTA 2");
	imprimir_lista(&pinicio2);
	printf("LISTA INTERCALADA");
	lista_intercalada(&pinicio1,&pinicio2,&pinicio3);
	imprimir_lista(&pinicio3);
	fclose(arq1);
	fclose(arq2);
	return 0;
}