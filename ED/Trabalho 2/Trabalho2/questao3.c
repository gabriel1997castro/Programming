//Lista aberta com ecadeamento duplo
//Questão 3 do trabalho 2

//Como no trabalho não foi especificado eu fiz a função que compara as duas dizer que são iguais
//apenas quando todos os caracteres são iguais e estão na mesma ordem

#include <stdio.h>
#include <stdlib.h>

typedef struct elemento
{
	int chave;
	struct elemento *ant,*prox;
}LISTA;

//---------------------------------------------------------------------------------------------------------------------------------------------------------//
void construir_inicio(LISTA **pinicio, FILE *arq) 
{
	int c;
	LISTA *p1;
	
	*pinicio = NULL;
	
	while ((fscanf(arq,"%d",&c)) != EOF) 
	{
		
		p1 = malloc (sizeof (LISTA));
		p1->chave = c;
		p1->prox = *pinicio;
		
		if (*pinicio != NULL)
			(*pinicio)->ant = p1;
			
		p1->ant = NULL;
		*pinicio = p1;
	}

	p1 = NULL;
	free(p1);
	return;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------//
void construir_final(LISTA **pinicio, FILE *arq) 
{
	LISTA *p1, *p2;
	int c;

	*pinicio = NULL;
	while ((fscanf(arq,"%d",&c)) != EOF) 
	{
		p1 = malloc (sizeof (LISTA));
		p1->chave = c;
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
		getchar();
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
			printf("Elemento %3d: %3d\n",i,p1->chave);
			p1 = p1->prox;
			i++;
		}
	}
	printf("\nTecle enter...\n");
	getchar();
	getchar();
	return;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------//
int comparar(LISTA **pinicio, LISTA **pinicio1)
{
	int i=0,h=0;
	LISTA *p1, *p2;
	p1 = *pinicio;
	p2 = *pinicio1;
	while(p1!=NULL && p2!=NULL)
	{
		if((p1->chave)!= (p2->chave))
			h++;
		p1 = p1->prox;
		p2 = p2->prox;
	}
	return h;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------//
int main()
{
	int opcao=10,h=0;
	char chave,caractere;
	LISTA *pinicio,*pinicio1;
	FILE *arq1,*arq2;

		arq1 = fopen ("t2-3.txt", "r");
		arq2 = fopen ("t2-3-1.txt", "r");
	if((!arq1) || (!arq2))
	{
		pinicio = NULL;
		pinicio1 = NULL;
		printf("Um dos arquivos ou ambos não podem ser abertos!\n");
		getchar();
		return 0;
	}

	printf("Construir lista 1 inserindo elementos no inicio ou no fim?(arquivo t2-3.txt)\n");
	printf("1)Inicio\n\n2)Final\n\n");
	scanf("%d",&opcao);
	while(opcao!=1&&opcao!=2)
	{
		printf("Digite uma opção válida!\n");
		scanf("%d", &opcao);
	}
	if(opcao==1)
	{
		construir_inicio(&pinicio, arq1);
		imprimir_lista(&pinicio);
	}
	if(opcao==2)
	{
		construir_final(&pinicio, arq1);
		imprimir_lista(&pinicio);
	}
	fclose(arq1);
	fclose(arq2);
	while(opcao!=0)
	{
		system("clear");
	
		printf("\n1)Construir (lista1) inseririndo elementos no inicio da lista (arquivo t2-3.txt)\n\n");
		printf("2)Construir (lista1) inserindo elementos no final da lista (arquivo t2-3.txt)\n\n");
		printf("3)Criar(lista2) e comparar com lista1, inserindo no inicio (arquivo2-3-1.txt)\n\n");
		printf("4)Criar(lista2) e comparar com lista1, inserindo no final (arquivo2-3-1.txt)\n\n");
		scanf("%d",&opcao);
		if(opcao==1)
		{
			arq1 = fopen ("t2-3.txt", "r");
			construir_inicio(&pinicio, arq1);
			imprimir_lista(&pinicio);
			fclose(arq1);
		}
		if(opcao==2)
		{
			arq1 = fopen ("t2-3.txt", "r");
			construir_final(&pinicio, arq1);
			imprimir_lista(&pinicio);
			fclose(arq1);
		}
		if(opcao==3)
		{
			arq2 = fopen ("t2-3-1.txt", "r");
			construir_inicio(&pinicio1, arq2);
			imprimir_lista(&pinicio1);
			h = comparar(&pinicio,&pinicio1);
			if(h==0)
				printf("As listas são iguais!\n");
			else
				printf("As listas são diferentes!\n");
			fclose(arq2);
			getchar();
		}
		if(opcao==4)
		{
			arq2 = fopen ("t2-3-1.txt", "r");
			construir_final(&pinicio1, arq2);
			imprimir_lista(&pinicio1);
			int h = comparar(&pinicio,&pinicio1);
			if(h==0)
				printf("As listas são iguais!\n");
			else
				printf("As listas são diferentes!\n");
			fclose(arq2);
			getchar();
		}
	}

	return 0;
}

