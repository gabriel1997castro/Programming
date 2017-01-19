// Lista aberta com encadeamento simples

#include <stdio.h>
#include <stdlib.h>


struct elemento{
	char dado;
	struct elemento *prox;
};


void construir_inicio(struct elemento **pinicio){
	FILE *arq;
	struct elemento *p1;
	char c;

	arq = fopen("a.txt", "r");
	if(arq == NULL){
		printf("O arquivo não pode ser aberto\n");
		return;
	}

	*pinicio = NULL;

	while((c=getc(arq))!=EOF){
		
		if(c!='\n' && c!=' ' && c!=EOF){
			p1 = malloc(sizeof(struct elemento));
			p1->dado = c;
			p1->prox = *pinicio;
			*pinicio = p1;	
		}
	}
	fclose(arq);
	return;
}


void construir_final(struct elemento **pinicio){
	struct elemento *p1, *p2;
	char c;
	FILE *arq;

	arq = fopen("a.txt", "r");
	if(arq == NULL){
		printf("O arquivo não pode ser aberto\n");
		return;
	}
	*pinicio = NULL;

	while((c = getc(arq)) != EOF){
		if(c!='\n'&&c!=' '){
			p1 = malloc(sizeof(struct elemento));
			p1->dado = c;
			p1->prox = NULL;
			if(*pinicio == NULL)
				*pinicio = p1;
			else
				p2->prox = p1;
			p2 = p1;			
		}
	}
	fclose(arq);
	return;
}


void imprimir_lista(struct elemento **pinicio){
	int i;
	struct elemento *p1;

	if(pinicio == NULL)
		printf("Lista vazia\n");
	else{
		p1 = *pinicio;
		i=1;
		system("clear");
		printf("\n\n");
		while(p1 != NULL){
			printf("Elemento %3d: %c\n", i, p1->dado);
			p1 = p1->prox;
			i++;
		}
	}
	printf("\n\nTecle enter para ir para o menu principal\n");
	getchar();
	getchar();
	free(p1);
	return;
}


void *procurar(struct elemento **pinicio,char chave){
	struct elemento *p1;
	p1 = *pinicio;
	while((p1!=NULL) && (p1->dado!=chave))
		p1 = p1->prox;
	return p1;
}


int main(){
	int opcao=10;
	char chave,caractere;
	struct elemento *pinicio;

	printf("Construir lista inserindo elementos no inicio ou no fim?\n");
	printf("1)Inicio\n\n2)Final\n\n");
	scanf("%d",&opcao);
	while(opcao!=1&&opcao!=2){
		printf("Digite uma opção válida!\n");
		scanf("%d", &opcao);
	}
	if(opcao==1){
		construir_inicio(&pinicio);
		imprimir_lista(&pinicio);
	}
	if(opcao==2){
		construir_final(&pinicio);
		imprimir_lista(&pinicio);
	}

	while(opcao!=0){
		system("clear");
	
		printf("\n\n1)Inserir elemento no inicio da lista\n\n2)Inserir elemento no final da lista\n\n3)Procurar elemento\n\n4)sair\n\n");
		scanf("%d",&opcao);
		if(opcao==1){
			construir_inicio(&pinicio);
			imprimir_lista(&pinicio);
		}
		if(opcao==2){
			construir_final(&pinicio);
			imprimir_lista(&pinicio);
		}
		if(opcao==3){
			struct elemento *p1;
			printf("Qual é o caractere que você quer procurar na lista?\n");
			getchar();
			chave = getchar();
			getchar();
			p1 = procurar(&pinicio,chave);
			if(p1!=NULL)
				printf("O caractere '%c' foi encontrado na lista\n", p1->dado);
			else
				printf("O caractere não foi encontrado na lista\n");
			printf("\n\nTecle enter para ir para o menu principal\n");
			getchar();
		}
		if(opcao==4)
			return 0;
			system("clear");
	}
}