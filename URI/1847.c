#include <stdio.h>

int main(){
	int a,b,c,y;
	scanf("%d %d %d", &a, &b, &c);

	y=(a+c)/2;

	if(y>b)
		printf(":)\n");
	else
		printf(":(\n");

	return 0;
}