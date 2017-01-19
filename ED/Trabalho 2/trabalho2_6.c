/* Na lista pedia para inverter elementos com 2 pilhas, mas consegui fazer usando apenas uma,
 *o que é mais eficiente, então deixei assim*/ 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct PILHA
{
	char dado;
	struct PILHA *prox;
}PILHA;

//------------------------------------------------------------------------------------------------------------------------------//
void InicializaPilha(PILHA **pilha){																							
	*pilha = NULL;
	printf("Pilha inicializada!\n");
	usleep(700000);
	return;
}

//------------------------------------------------------------------------------------------------------------------------------//
int PilhaVazia(PILHA **pilha){
	if((*pilha) == NULL)
		return 1;
	else
		return 0;
}

//------------------------------------------------------------------------------------------------------------------------------//
char TopoPilha(PILHA *pilha){
	return pilha->dado;
}

//------------------------------------------------------------------------------------------------------------------------------//
void InserePilha(PILHA **pilha,char dadonovo){
	PILHA *p1;

	p1 = malloc(sizeof(struct PILHA));
	p1->dado = dadonovo;
	p1->prox = *pilha;
	*pilha = p1;
	return;
}

//------------------------------------------------------------------------------------------------------------------------------//
char RetiraPilha(PILHA **pilha){
	PILHA *p1;
	char  car;

	p1 = *pilha;
	*pilha = p1->prox;
	car = p1->dado;
	free(p1);
	return car;
}

//------------------------------------------------------------------------------------------------------------------------------//
void imprimir(PILHA **pilha){
	PILHA *p1;

	if(*pilha == NULL)
		printf("Pilha vazia!\n");
	else{
		p1 = *pilha;
		do{
			printf("Elemento: %c\n", p1->dado);
			usleep(500000);
			p1 = p1->prox;
		}while(p1 != NULL);
	}
	return;
}

//------------------------------------------------------------------------------------------------------------------------------//
void invertePilhazuda(PILHA **pilha){
	PILHA *p1,*p2;
	char c;
	while(*pilha != NULL){
		c = RetiraPilha(pilha);
		InserePilha(&p1, c);
	}
	*pilha = p1;
}

//------------------------------------------------------------------------------------------------------------------------------//
int main(){
	int i,j,n=1,vazia;
	PILHA *pilha;
	char dadonovo,h;
	InicializaPilha(&pilha);

	while(n!=0){
		system("clear");
		printf("0)Sair\n1) Inicializar ou zerar pilha\n2) Verificar se pilha tem elementos\n");
		printf("3) Verificar elemento no topo\n4) Inserir elemento na pilha\n");
		printf("5) Retirar elemento da pilha\n6) Imprimir pilha\n7) Iverter pilha usando pilha\n");
		scanf("%d", &n);
		getchar();

		if(n==0){
			system("clear");
			return 0;
		}

		if(n==1){
			system("clear");
			InicializaPilha(&pilha);
		}
		if(n==2){
			system("clear");
			vazia = PilhaVazia(&pilha);
			if(vazia == 1){
				printf("A pilha está vazia\n");
				getchar();
			}
			else{
				printf("A pilha não está vazia!\n");
				getchar();
			}
		}
		if(n==3){
			system("clear");
			vazia = PilhaVazia(&pilha);
			if(vazia == 1){
				printf("A pilha está vazia\n");
				getchar();
			}
			else{
				h=TopoPilha(pilha);
				printf("Elemento no topo: '%c'\n", h);
				getchar();
			}
		}
		if(n==4){
			system("clear");
			printf("Digite quantos elementos deseja inserir na pilha:\n");
			scanf("%d", &i);
			getchar();
			printf("Digite os elementos que deseja inserir(sem espaço):\n");
			for(j=0;j<i;j++){
				scanf("%c",&dadonovo);
				if(dadonovo!=' '&& dadonovo!= '\n')
					InserePilha(&pilha, dadonovo);
			}
			printf("Elementos inseridos!\n");
			getchar();
			getchar();
		}
		if(n==5){
			system("clear");
			vazia = PilhaVazia(&pilha);
			if(vazia == 1){
				printf("A pilha está vazia\n");
				getchar();
			}
			else{
				h = RetiraPilha(&pilha);
				printf("O elemento '%c' foi retirado da pilha!\n", h);
				getchar();
			}
		}
		
		if(n==6){
			system("clear");
			imprimir(&pilha);
			getchar();
		}
		if(n==7){
			invertePilhazuda(&pilha);
			printf("Pilha invertida!\n");
			usleep(700000);
		}
	}

	return 0;
}