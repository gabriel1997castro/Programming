#include <stdio.h>
#include <stdlib.h>

int main(void){
	int x, y, z;
	FILE *file;
	file = fopen("numero.txt","r");
	if(file!=0){
		fscanf(file,"%i %i %i", &x, &y, &z);
		printf("%i %i %i\n", x, y, z);
		fclose(file);
	}
	else
		printf("O arquivo não pode ser aberto\n");

		return 0;
}