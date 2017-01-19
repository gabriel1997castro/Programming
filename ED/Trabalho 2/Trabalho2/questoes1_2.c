// Lista  aberta  com  encadeamento  simples
// em que cada elemento armazene 2 elementos
// inteiros(Tópicos 1 e 2 do trabalho)

#include <stdio.h>
#include <stdlib.h>

typedef struct LISTA
{
	int dado1, dado2;
	struct LISTA *prox;
}LISTA;


//QUESTÃO 1
//------------------------------------------------------------------------------//
void construir_inicio(LISTA **pinicio)
{
	FILE *arq;
	LISTA *p1;
	int d1,d2;

	arq = fopen("t2-1.txt", "r");

	if(arq!=NULL)
	{
		*pinicio = NULL;

		while((fscanf(arq,"%d%d", &d2, &d1)) != EOF)
		{
			p1 = malloc(sizeof(LISTA));
			p1->dado1 = d1;
			p1->dado2 = d2;
			p1->prox = *pinicio;
			*pinicio = p1;
		}
		fclose(arq);
	}
	else
	{
		printf("O arquivo não pode ser aberto\n");
		*pinicio = NULL;
		getchar();
		getchar();
		return;
	}

	return;
}

//QUESTÃO 2
//------------------------------------------------------------------------------//
void construir_final(LISTA **pinicio)
{
	LISTA *p1,*p2;
	int d1,d2;
	FILE *arq;

	arq = fopen("t2-1.txt", "r");
	if(arq == NULL)
	{
		printf("O arquivo não pode ser aberto!\n");
		getchar();
		getchar();
		(*pinicio) = NULL;
		return;
	}
	*pinicio = NULL;
	while((fscanf(arq,"%d%d", &d1, &d2)) != EOF)
	{
		p1 = malloc(sizeof(LISTA));
		p1->dado1 = d1;
		p1->dado2 = d2;
		if(*pinicio == NULL)
			*pinicio = p1;
		else
			p2->prox = p1;
		p2 = p1;
	}
	fclose(arq);
	return;
}

//------------------------------------------------------------------------------//
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
		system("clear");
		printf("\n\n");
		while(p1 != NULL)
		{
			printf("Elemento %3d.1: %3d | Elemento %3d.2: %3d \n",i,p1->dado1,i,p1->dado2);
			p1 = p1->prox;
			i++;
		}
	}
	printf("\nTecle enter para ir para o menu principal\n");
	getchar();
	getchar();
	free(p1);
	return;
}

//------------------------------------------------------------------------------//
int main()
{
	int opcao=10;
	char chave,caractere;
	LISTA *pinicio;

	printf("Construir lista inserindo elementos no inicio ou no fim?\n");
	printf("1)Inicio\n\n2)Final\n\n");
	scanf("%d",&opcao);
	while(opcao!=1&&opcao!=2)
	{
		printf("Digite uma opção válida!\n");
		scanf("%d", &opcao);
	}
	if(opcao==1)
	{
		construir_inicio(&pinicio);
		imprimir_lista(&pinicio);
	}
	if(opcao==2)
	{
		construir_final(&pinicio);
		imprimir_lista(&pinicio);
	}

	while(opcao!=0)
	{
		system("clear");
	
		printf("\n\n1)Inserir elemento no inicio da lista\n\n2)Inserir elemento no final da lista\n\n3)Sair\n\n");
		scanf("%d",&opcao);
		if(opcao==1)
		{
			construir_inicio(&pinicio);
			imprimir_lista(&pinicio);
		}
		if(opcao==2)
		{
			construir_final(&pinicio);
			imprimir_lista(&pinicio);
		}
		if(opcao==3)
			return 0;
			system("clear");
	}
	return 0;
}