#include <stdio.h>

int main(){
	double A, B, X;
	scanf("%lf %lf", &A, &B);

	X = (100*(B-A))/A;
	printf("%.2lf%%\n", X);

	return 0;
}










