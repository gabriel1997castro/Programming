#include <stdio.h>
#include <string.h>

int main(){
	char str[20];
	int c,j,i;
	scanf("%d", &j);

	for(i=0;i<j;i++){

	scanf("%s %d", str, &c);

		if(strcmp(str, "Thor")==0){
			printf("Y\n");
		}
		else{
			printf("N\n");
		}
	}


	return 0;
}