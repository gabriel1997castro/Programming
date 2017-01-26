#include <stdio.h>
#include <stdlib.h>

int main(){
	int a,b,c,moduloa,modulob,moduloc,i=0;
	scanf("%d %d %d", &a, &b, &c);
	if(a==b&&a==c){
		printf("Valido-Equilatero\n");
		printf("Retangulo: S\n");
	}
	else{
		moduloa = abs(b-c);
		modulob = abs(a-c);
		moduloc = abs(a-b);

		if(a)
	}
	return 0;
}