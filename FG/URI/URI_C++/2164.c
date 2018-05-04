#include <stdio.h>
#include <math.h>

int main(){
	int n=0;
	double a=0.0,b=0.0,c=0.0,d=0.0,e=0.0,f=0.0;

	scanf("%d", &n);
	a=(float)n;

	b=((1+sqrt(5))/2);
	c=pow(b,a);
	d=((1-sqrt(5))/2);
	e=pow(d,a);
	f=((c-e)/sqrt(5));
	printf("%.1lf\n", f);
	return 0;
}