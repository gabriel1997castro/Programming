// Universidade de Brasília
// Autor: Gabriel Guimarães Almeida de Castro
// Descrição: Programa abre ou cria 2 arquivos, escreve neles e depois lê o
// que foi escrito e escreve em um terceiro arquivo.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Allow to use the sleep function
#include <string.h> //Allow to use strcmp function

int check_open(FILE *fd) //check if the file can be opened or created
{
	if(fd == NULL)
	{
		printf("The file can't be opened!\n");
		exit(0);
	}
	printf("File opened\n");
	return 0;
}

void check_names(char file_name1[100],char file_name2[100]) //check if the names aren't the same
{
	while(strcmp(file_name1, file_name2)==0){
		printf("The names of the files can't be the same! Type another name:\n");
		scanf("%s", file_name2);
	}

}

int main(int argc, char const *argv[])
{
	// Create file descriptor variables
	FILE *fd1;  
	FILE *fd2;
	FILE *fd3;
	
	int i = 0;

	char aux;
	char file_name1[100], file_name2[100], file_name3[100];

	printf("Type the name of the first file that you want concatenate:\n");
	scanf("%s", file_name1);
	//open or create a file called file1.txt in write mode
	printf("Opening %s...\n", file_name1);
	fd1 = fopen(file_name1, "r");  
	check_open(fd1);

	//open or create a file called file2.txt in write mode
	printf("Type the name of the second file that you want concatenate:\n");
	scanf("%s", file_name2);
	check_names(file_name1, file_name2);

	fd2 = fopen(file_name2, "r");
	check_open(fd2); 

	//Open or create a new file called file3.txt
	printf("Type the name of the destiny file:\n");
	scanf("%s", file_name3);
	check_names(file_name1, file_name3);
	check_names(file_name2, file_name3);

	printf("Opening file 3...\n");
	fd3 = fopen(file_name3, "w+");
	check_open(fd3);

	//Read the file 1 and write the content in the file 3 
	printf("Writing content of file 1 in file 3\n");
	while((aux = fgetc(fd1))!= EOF)
	{
		fprintf(fd3, "%c", aux);
	}

	//Read the file 2 and write the content in the file 3 
	printf("Writing content of file 2 in file 3\n");
	while((aux = fgetc(fd2))!= EOF)
	{
		fprintf(fd3, "%c", aux);
	}

	//wait 2 sec to the next instruction
	sleep(2);
	//clear the screen
	system("clear");

	//Move to the beggining of the file
	fseek( fd1, 0, SEEK_SET);
	printf("FILE 1 content:\n\n");
	printf("--------------------------------\n");
	while((aux = fgetc(fd1))!= EOF)
	{
		printf("%c", aux);
	}
	printf("--------------------------------\n\n");


	//Move to the beggining of the file
	fseek( fd2, 0, SEEK_SET);
	printf("FILE 2 content:\n\n");
	printf("--------------------------------\n");
	while((aux = fgetc(fd2))!= EOF)
	{
		printf("%c", aux);
	}
	printf("--------------------------------\n\n");


	//Move to the beggining of the file
	fseek( fd3, 0, SEEK_SET);
	printf("FILE 3 content:\n\n");
	printf("--------------------------------\n");
	while((aux = fgetc(fd3))!= EOF)
	{
		printf("%c", aux);
	}
	printf("--------------------------------\n\n");


	printf("Closing all files...\n");
	fclose(fd1);
	fclose(fd2);
	fclose(fd3);
	printf("Files closed!\n");

	return 0;
}
