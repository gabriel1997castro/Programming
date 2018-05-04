#include <stdio.h>
#include <string.h>

int main(){
	int n,i,a, soma, number1, number2;
	char nome1[101], nome2[101], esc1[6], esc2[6];

	scanf("%d", &n);

	for (i=0;i<n;i++){

		scanf("%s %s %s %s", nome1, esc1, nome2, esc2);
		scanf("%d", &number1);
		scanf("%d", &number2);
		
		soma=number1+number2;
		a=soma%2;
		
		if(a==0){
			if(esc1[0]=='P'){
				printf("%s\n", nome1);
			}
			if(esc2[0]=='P'){
				printf("%s\n", nome2);
			}
		}
		else if(a!=0){
			if(esc1[0]=='I'){
				printf("%s\n", nome1);
			}
			if(esc2[0]=='I'){
				printf("%s\n", nome2);
			}
		
		}


	}

	return 0;
}