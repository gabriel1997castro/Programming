//Questoes 6 e  7

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct PILHA
{
	char dado;
	struct PILHA *prox;
}PILHA;

//-------------------------------------------------------------------------------------------------------------------------------//
typedef struct FILA
{
char dado;
struct FILA *prox;
}FILA;

//------------------------------------------------------------------------------------------------------------------------------//
void InicializaPilha(PILHA **pilha)
{																							
	*pilha = NULL;
	printf("Pilha inicializada!\n");
	usleep(700000);
	return;
}

//------------------------------------------------------------------------------------------------------------------------------//
int PilhaVazia(PILHA **pilha)
{
	if((*pilha) == NULL)
		return 1;
	else
		return 0;
}

//------------------------------------------------------------------------------------------------------------------------------//
char TopoPilha(PILHA *fila)
{
	return fila->dado;
}

//------------------------------------------------------------------------------------------------------------------------------//
void InserePilha(PILHA **pilha,char dadonovo)
{
	PILHA *p1;

	p1 = malloc(sizeof(struct PILHA));
	p1->dado = dadonovo;
	p1->prox = *pilha;
	*pilha = p1;
	return;
}

//------------------------------------------------------------------------------------------------------------------------------//
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

//------------------------------------------------------------------------------------------------------------------------------//
char RetiraPilha(PILHA **pilha)
{
	PILHA *p1;
	char  car;

	p1 = *pilha;
	*pilha = p1->prox;
	car = p1->dado;
	free(p1);
	return car;
}

//------------------------------------------------------------------------------------------------------------------------------//
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

//------------------------------------------------------------------------------------------------------------------------------//
void imprimir(PILHA **pilha)
{
	PILHA *p1;

	if(*pilha == NULL)
		printf("Pilha vazia!\n");
	else
	{
		p1 = *pilha;
		do
		{
			printf("Elemento: %c\n", p1->dado);
			usleep(500000);
			p1 = p1->prox;
		}while(p1 != NULL);
	}
	return;
}

//QUESTÃO 6 
//------------------------------------------------------------------------------------------------------------------------------//
void invertePilhazuda(PILHA **pilha)
{
	PILHA *p1,*p2;
	char c;
	while(*pilha != NULL)
	{
		c = RetiraPilha(pilha);
		InserePilha(&p1, c);
	}
	*pilha = p1;
	return;
}

//QUESTÃO 7
void invertePilhazuda1(PILHA **pilha)
{
	PILHA *p1;
	FILA *fila;
	char c;

	while(*pilha !=NULL)
	{
		c = RetiraPilha(pilha);
		InsereFila(&fila, c);
	}

	while(fila != NULL)
	{
		c = RetiraFila(&fila);
		InserePilha(pilha, c);
	}
	return;
}

//------------------------------------------------------------------------------------------------------------------------------//
int main()
{
	int i,j,n=1,vazia;
	PILHA *pilha;
	FILA *fila;
	char dadonovo,h;
	InicializaPilha(&pilha);

	while(n!=0)
	{
		system("clear");
		printf("______________________________________\n");
		printf("|0) Sair                             |\n");
		printf("|1) Inicializar ou zerar pilha       |\n");
		printf("|2) Verificar se pilha tem elementos |\n");
		printf("|3) Verificar elemento no topo       |\n");
		printf("|4) Inserir elemento na pilha        |\n");
		printf("|5) Retirar elemento da pilha        |\n");
		printf("|6) Imprimir pilha                   |\n");
		printf("|7) Iverter pilha usando pilha       |\n");
		printf("|8) Inverter pilha usando fila       |\n");
		printf("|____________________________________|\n");
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
			InicializaPilha(&pilha);
		}
		if(n==2){
			system("clear");
			vazia = PilhaVazia(&pilha);
			if(vazia == 1)
			{
				printf("A pilha está vazia!\n");
				getchar();
			}
			else
			{
				printf("A pilha não está vazia!\n");
				getchar();
			}
		}
		if(n==3)
		{
			system("clear");
			vazia = PilhaVazia(&pilha);
			if(vazia == 1)
			{
				printf("A pilha está vazia\n");
				getchar();
			}
			else
			{
				h=TopoPilha(pilha);
				printf("Elemento no topo: '%c'\n", h);
				getchar();
			}
		}
		if(n==4)
		{
			printf("Digite os elementos que deseja inserir:\n");
			dadonovo = ' ';
			while(dadonovo != '\n')
			{
				scanf("%c", &dadonovo);
				if(dadonovo!=' '&& dadonovo!= '\n')
					InserePilha(&pilha, dadonovo);
			}

			printf("Elementos inseridos!\n");
			usleep(700000);
		}
		if(n==5)
		{
			system("clear");
			vazia = PilhaVazia(&pilha);
			if(vazia == 1)
			{
				printf("A pilha está vazia\n");
				getchar();
			}
			else
			{
				h = RetiraPilha(&pilha);
				printf("O elemento '%c' foi retirado da pilha!\n", h);
				getchar();
			}
		}
		
		if(n==6)
		{
			system("clear");
			imprimir(&pilha);
			getchar();
		}
		if(n==7)
		{
			invertePilhazuda(&pilha);
			printf("Pilha invertida!\n");
			usleep(700000);
		}
		if(n==8)
		{
			invertePilhazuda1(&pilha);
			printf("Pilha invertida!\n");
			usleep(700000);
		}
	}

	return 0;
}