#include <stdio.h>

int main(){
	int i, j, x, n, h=0,g=0;

	while(scanf("%d", &x)!=EOF){
		g++;
		n=0;
		for(i=0;i<x+1;i++){
			n+=i;
		}
		if(x>0){
			printf("Caso %d: %d numeros\n", g, n+1);
			printf("%d ", h);
		}
		else{
			printf("Caso %d: %d numero\n", g, n+1);
			printf("%d\n", h);
		}
		for (i=1;i<x;i++){
			for(j=1;j<=i;j++){
				printf("%d ", i);
			}
		}
		if(x !=0 ){
			for(i=0;i<x-1;i++)
				printf("%d ", x);
			printf("%d\n", x);
		}
		printf("\n");
	}



	return 0;
}