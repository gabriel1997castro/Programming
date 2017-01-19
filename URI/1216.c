#include <stdio.h>

int main(){
	int i,k=1,m;
	char nome[50];
	double media;

	while(gets(nome)){
		scanf("%d",&i);
		m+=i;
		k++;
		media=(double)m/k;
	}
	printf("%.1lf\n", media);
	return 0;
}