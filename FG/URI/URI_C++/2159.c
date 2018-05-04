#include <stdio.h>
#include <math.h>

int main(){
	int n;
	double P, M, i;

	scanf("%d", &n);
	i=(float)n;
	P = i/log(i);
	M = 1.25506*P;
	printf("%.1lf %.1lf\n",P,M);

	return 0;

}