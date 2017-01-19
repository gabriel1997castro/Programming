#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct PILHA
{
	char dado;
	struct PILHA *prox;
}PILHA;

//------------------------------------------------------------------------------------------------------------------------------//
void InicializaPilha(PILHA **pilha)
{																							
	*pilha = NULL;
	printf("Bem vindo!\n");
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
PILHA *invertePilhazuda(PILHA **pilha)
{
	PILHA *p1,*p2;
	char c;
	while(*pilha != NULL)
	{
		c = RetiraPilha(pilha);
		InserePilha(&p1, c);
	}

	return p1;
}

//------------------------------------------------------------------------------------------------------------------------------//
int VerificarPalindromo(PILHA **pilha){
	int i=0,h=0;
	PILHA *p1, *p2;
	
	p1 = *pilha;
	
	p2 = invertePilhazuda(pilha);
	while(p1!=NULL && p2!=NULL){
		if((p1->dado)!= (p2->dado))
			if(p1->dado != p2->dado+32)
				h++;
		p1 = p1->prox;
		p2 = p2->prox;
	}
	return h;
}

//------------------------------------------------------------------------------------------------------------------------------//
int main()
{
	int i,j,n=1,vazia,x;
	PILHA *pilha;
	char dadonovo,h;
	InicializaPilha(&pilha);

	while(n!=0)
	{
		system("clear");
		printf("_______________________________________________________\n");
		printf("|0) Sair                                              |\n");
		printf("|1) Verificar palíndromo                              |\n");
		printf("|_____________________________________________________|\n");
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
			printf("_______________________________________________________\n");
			printf("|Digite o palíndromo:                                 |\n");
			printf("|                                                     |\n");
			printf("|_____________________________________________________|\n");

			
			dadonovo = ' ';
			while(dadonovo != '\n')
			{
				scanf("%c", &dadonovo);
				if(dadonovo!=' '&& dadonovo!= '\n')
					InserePilha(&pilha, dadonovo);
			}
			x = VerificarPalindromo(&pilha);
			if(x==0){
				system("clear");
				printf("_______________________________________________________\n");
				printf("|É palíndromo!                                        |\n");
				printf("|                                                     |\n");
				printf("|_____________________________________________________|\n");
			}
			else{
				system("clear");
				printf("_______________________________________________________\n");
				printf("|Não é palíndromo!                                    |\n");
				printf("|                                                     |\n");
				printf("|_____________________________________________________|\n");
			}
			getchar();

		}

	}

	return 0;
}