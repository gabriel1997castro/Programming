#include <stdio.h>

int main(){
	int S, T, F, R;

	scanf("%d %d %d", &S, &T, &F);

	R = S + T + F;
	if(R>=24){
		R-=24;
	}
	if(R<0){
		R+=24;
	}

	printf("%d\n", R);

	return 0;
}