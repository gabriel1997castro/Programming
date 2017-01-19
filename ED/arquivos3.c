#include <stdio.h>
#include <stdlib.h>

int main(void){
	FILE *file;
	file = fopen("string.txt","r");
	if(file == 0){
		printf("Não foi possível abrir o arquivo\n");
		getchar();
		exit(0);
	}

	char frase [100];

	while(fgets(frase, 100, file) != NULL){
		printf("%s", frase);
	}
	//É necessário o while para que não pare de ler no \n
	//Na fscanf só será lido a primeira palavra ou até o primeiro espaço

	fclose(file);
}