#include <stdio.h>

int main(){
	double D, vol, alt, area;

	while(scanf("%lf\n%lf", &vol, &D)!=EOF){
		area=(D/2)*(D/2)*3.14;
		alt=vol/area;
		printf("ALTURA = %.2lf\nAREA = %.2lf\n", alt, area);
	}
	
	return 0;
}