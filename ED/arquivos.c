#include <stdio.h>

int main(void){

		FILE *file;
		//Cria se um ponteiro para o tipo arquivo
		file = fopen("/home/gabriel/Desktop/ED/teste.txt","w");
		//Abre um arquivo com fopen, o primeiro argumento é um
		//endereço do local onde o arquivo será criado mais o nome,
		//o pode-se escrever apenas o nome criando na pasta do programa
		//e temos o segundo argumento que é modo como o arquivo será 
		//aberto onde r-read, w-write, a-append
		fprintf(file, "Este é o meu arquivo\n");
		fclose(file);

		return 0;
}