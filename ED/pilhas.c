#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//-------------------------------------------------------------------------------------------------------------------------------//
struct tipopilha{
	char dado;
	struct tipopilha *prox;
};

//-------------------------------------------------------------------------------------------------------------------------------//
void InicializaPilha(struct tipopilha **pilha){
	*pilha = NULL;
	printf("Pilha inicializada!\n");
	usleep(700000);
	return;
}

//-------------------------------------------------------------------------------------------------------------------------------//
int PilhaVazia(struct tipopilha **pilha){
	if((*pilha) == NULL)
		return 1;
	else
		return 0;
}

//-------------------------------------------------------------------------------------------------------------------------------//
char TopoPilha(struct tipopilha *pilha){
	return pilha->dado;
}

//-------------------------------------------------------------------------------------------------------------------------------//
void InserePilha(struct tipopilha **pilha,char dadonovo){
	struct tipopilha *p1;
	p1 = malloc(sizeof(struct tipopilha));
	p1->dado = dadonovo;
	p1->prox = *pilha;
	*pilha = p1;
	return;
}

//-------------------------------------------------------------------------------------------------------------------------------//
char RetiraPilha(struct tipopilha **pilha){
	struct tipopilha *p1;
	char  car;
	p1 = *pilha;
	*pilha = p1->prox;
	car = p1->dado;
	free(p1);
	return car;
}

//-------------------------------------------------------------------------------------------------------------------------------//
void imprimir(struct tipopilha **pilha){
	struct tipopilha *p1;

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

//-------------------------------------------------------------------------------------------------------------------------------//
int main(){
	int i,j,n=1,vazia;
	struct tipopilha *pilha;
	char dadonovo,h;
	InicializaPilha(&pilha);

	while(n!=0){
		system("clear");
		printf("0)Sair\n1) Inicializar ou zerar pilha\n2) Verificar se pilha tem elementos\n3) Verificar elemento no topo\n4) Inserir elemento na pilha\n5) Retirar elemento da pilha\n6) Imprimir pilha\n");
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
				printf("Elemento no topo: %c\n", h);
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
				printf("A pilha está vazia!\n");
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
	}

	return 0;
}