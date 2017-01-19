#include <stdio.h>

int main(){
	double a, b;
	int n;
	scanf("%d", &n);

	for(i=0;i<n;i++){
		a+=6.0;
		a=1/a;
	}
	printf("%.10lf\n", a+3);

	return 0;
}