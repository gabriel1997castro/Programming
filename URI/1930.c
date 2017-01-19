#include <stdio.h>

int main(){
	int T1, T2 , T3, T4, n;

	scanf("%d %d %d %d", &T1, &T2, &T3, &T4);

	n = T1+T2+T3+T4-3;
	printf("%d\n", n);

	return 0;
}