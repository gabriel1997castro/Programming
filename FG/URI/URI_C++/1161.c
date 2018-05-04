#include <stdio.h>

long long int fatorial(long long unsigned int n){
	if(n){
		return n*fatorial(n-1);
	}
	else return 1;
}
int main(){
	long long unsigned int a,b,fat1,fat2;
		while(scanf("%llu %llu",&a,&b)!=EOF){
			fat1=fatorial(a);
			fat2=fatorial(b);
			printf("%llu\n",fat1+fat2);
	}
	return 0;
}