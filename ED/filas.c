#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//-------------------------------------------------------------------------------------------------------------------------------//
typedef struct FILA
{
char dado;
struct FILA *prox;
}FILA;

//-------------------------------------------------------------------------------------------------------------------------------//
void InicializaFila(FILA **fila)
{
	*fila = NULL;
	printf("Fila inicializada!\n");
	usleep(700000);
	return;
}

//-------------------------------------------------------------------------------------------------------------------------------//
int FilaVazia(FILA **fila)
{
	if((*fila)==NULL)
		return 1;
	else
		return 0;
}

//-------------------------------------------------------------------------------------------------------------------------------//
char FrenteFila(FILA *fila)
{
	return fila->dado;
}

//-------------------------------------------------------------------------------------------------------------------------------//
void InsereFila(FILA **fila, char dadonovo)
{
	FILA *f1, *f2;

	f1 = malloc(sizeof(FILA));
	f1->dado = dadonovo;
	f1->prox = NULL;
	if(*fila == NULL)
		*fila = f1;
	else
	{
		f2 = *fila;
		while(f2->prox != NULL)
			f2 = f2->prox;
		f2->prox = f1;
	}
	f1 = NULL;
	free(f1);
	return;
}

//-------------------------------------------------------------------------------------------------------------------------------//
char RetiraFila(FILA **fila)
{
	FILA *f1;
	char c;

	f1 = *fila;
	*fila = f1->prox;
	c = f1->dado;
	f1 = NULL;
	free(f1);
	return c;
}

//-------------------------------------------------------------------------------------------------------------------------------//
void imprimir(FILA **fila){
	FILA *f1;

	if(*fila == NULL)
		printf("Fila vazia!\n");
	else{
		f1 = *fila;
		do{
			printf("Elemento: %c\n", f1->dado);
			usleep(500000);
			f1 = f1->prox;
		}while(f1 != NULL);
	}
	return;
}

//-------------------------------------------------------------------------------------------------------------------------------//
int main()
{
	int i,j,n=1,vazia;
	FILA *fila;
	char dadonovo,h;
	InicializaFila(&fila);

	while(n!=0)
	{
		system("clear");
		printf("0)Sair\n1) Inicializar ou zerar fila\n2) Verificar se fila tem elementos\n3) Verificar elemento na frente\n4) Inserir elemento na fila\n5) Retirar elemento da fila\n6) Imprimir fila\n");
		scanf("%d", &n);
		getchar();

		if(n==0)
		{
			system("clear");
			return 0;
		}

		if(n==1)
		{
			system("clear");
			InicializaFila(&fila);
		}
		if(n==2)
		{
			system("clear");
			vazia = FilaVazia(&fila);
			if(vazia == 1){
				printf("A fila está vazia\n");
				getchar();
			}
			else
			{
				printf("A fila não está vazia!\n");
				getchar();
			}
		}
		if(n==3)
		{
			system("clear");
			vazia = FilaVazia(&fila);
			if(vazia == 1)
			{
				printf("A fila está vazia\n");
				getchar();
			}
			else
			{
				h=FrenteFila(fila);
				printf("Elemento no topo: %c\n", h);
				getchar();
			}
		}
		if(n==4)
		{
			system("clear");
			printf("Digite quantos elementos deseja inserir na fila:\n");
			scanf("%d", &i);
			getchar();
			printf("Digite os elementos que deseja inserir(sem espaço):\n");
			for(j=0;j<i;j++)
			{
				scanf("%c",&dadonovo);
				if(dadonovo!=' '&& dadonovo!= '\n')
					InsereFila(&fila, dadonovo);
			}
			printf("Elementos inseridos!\n");
			getchar();
			getchar();
		}
		if(n==5)
		{
			system("clear");
			vazia = FilaVazia(&fila);
			if(vazia == 1)
			{
				printf("A fila está vazia\n");
				getchar();
			}
			else
			{
				h = RetiraFila(&fila);
				printf("O elemento %c foi retirado da fila!\n", h);
				getchar();
			}
		}
		if(n==6)
		{
			system("clear");
			imprimir(&fila);
			getchar();
		}
	}

	return 0;
}
