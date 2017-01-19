#include <stdio.h>

int main(){
	unsigned long long int N,i,j,graos,a;

	scanf("%llu", &N);

	for(i=0;i<N;i++){
		graos=2;
		scanf("%llu", &a);
		for(j=0;j<a-1;j++){
			graos*=2;
		}
		graos/=12000;

		if(a<64&&a>=1)
			printf("%llu kg\n", graos);
		else
			printf("1537228672809129 kg\n");
	}


	return 0;
}

