#include <stdio.h>

int main(){
	int a,b, minutos;

	while(scanf("%d:%d", &a, &b)!=EOF){
		minutos=(a*60)+b;
		if((8*60)<minutos+60){
			printf("Atraso maximo: %d\n", (minutos+60)-((8*60)));
		}
		else{
			printf("Atraso maximo: 0\n");
		}
	}

	return 0;
}