#include <stdio.h>

int main(){
	long long int n,m,i,soma,r;
	while(scanf("%lld %lld", &n, &m)!=EOF){
		soma=0;
		for(i=0;i<n;i++){
			r=m%10;
			soma+=r;
			m=(m-r)/10;
		}
		if(soma%3==0)
			printf("%lld sim\n", soma);
		else
			printf("%lld nao\n", soma);

	}
	return 0;
}