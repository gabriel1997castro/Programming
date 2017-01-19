#include <stdio.h>
#include <stdlib.h>

struct lista{					//Nessa parte do código temos a definição
	char dado;					//de uma estrutura do tipo lista onde ela
	struct lista *ponteiro; 	//possue um caractere e um ponteiro para o
};								//outro elemento da lista.						

struct lista *aux, *p1;			//Nesta linha foi definido ponteiros para 
								//Estruturas do tipo lista
int main(){
	char c;
	FILE *file;					//Nesta linha foi declarado um ponteiro
								//o tipo FILE
	aux = NULL;

	file = fopen("a.txt","r");	//Nesta linha file recebe o endereço do arquivo que será lido
	if(file == NULL){
		printf("O arquivo não pode ser lido\n");
		return 0;
	}

	while(c!=EOF){									// EOF=End of file 
		c = fgetc(file);							//Pega caracteres do arquivo e coloca a variável c
		if(c!='\n'&& c != ' ' && c != EOF){
			p1 = malloc(sizeof(struct lista));
			p1->dado = c;
			p1->ponteiro = aux;
			aux = p1;
		}
	}
	for(;p1->ponteiro != NULL;){
		printf("%c\n", p1->dado);
		p1 = p1->ponteiro;
	}
	printf("%c\n", p1->dado);
	fclose(file);
	
	return 0;

}