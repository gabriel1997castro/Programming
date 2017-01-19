#include <stdio.h>

int main(){
	int n=0;
	double x=0.0,y=0.0;

	scanf("%d",&n);
	while(n--){
		x+=2.0;
		x=1.0/x;
	}

	y=x+1;

	printf("%.10lf\n", y);
	return 0;
}