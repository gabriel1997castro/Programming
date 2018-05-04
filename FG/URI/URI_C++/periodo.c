#include <stdio.h>
#include <math.h>

int main(){
	double T,g=9.81,pi=3.141592654,aux1,aux2,M1=0.348,L1,M2=0.345,L2=0.89;
	L1=0.04;
	while(L1<0.84){
		printf("\n");
		aux1=((M1*pow(L1,2))+(M2*pow(L2,2)));
		aux2=(M1*L1)+(M2*L2);
		T=2*pi;
		T *= sqrt((1/g)*(aux1/aux2));
		printf("Para L1=%.2lf -------- Período = %lf\n",L1, T);
		L1+=0.06;
	}
	return 0;
}