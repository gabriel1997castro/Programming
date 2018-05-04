#include <stdio.h>

int main(){
    unsigned long int a,b,soma,n;
    scanf("%lu %lu",&a,&b);
    n = b - a + 1;
    if(a<b){
    	soma = ((a+b)*n)/2;
    }
    if(a==b)
    	soma = a;

    printf("%lu\n",soma);
	return 0;
}