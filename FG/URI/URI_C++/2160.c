#include <stdio.h>


int main(){
	char a;
	int i;
	i=0;
	while((a=getchar()) != '\n'){
		i++;
	}
	if(i>80)
		printf("NO\n");
	else
		printf("YES\n");
}