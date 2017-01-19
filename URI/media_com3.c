#include <stdio.h>

int main(){
	int i,n;
	double T1,T2,T3;
	printf("Digite o número de médias:\n");
	scanf("%d", &n);
	for(i=0;i<n;i++){
		printf("Digite 3 valores:\n");
		scanf("%lf %lf %lf",&T1,&T2,&T3);

		printf("Média %d = %lf\n\n\n",i+1,(T1+T2+T3)/3);
	}
	return 0;
}