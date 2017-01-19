#include <stdio.h>

int main(){
	unsigned long long int n,s;
	scanf("%llu", &n);

	s=((n*n)-(3*n))/2;

	printf("%llu\n", s);
	return 0;
}




#include <stdio.h> 

int main (){
	int a,b,c,d;

		scanf("%d %d %d %d", &a, &b , &c, &d);

		if(a+b>c||a+b>d||a+c>b||a+c>d)
			printf("S\n");
		else if(a+d>c||a+d>b||b+c>a||b+c>d)
			printf("S\n");
		else if(b+d>a||b+d>c||c+d>a||c+d>b)
			printf("S\n");
		else
			printf("N\n");
	return 0;
}