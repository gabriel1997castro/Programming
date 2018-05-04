#include <stdio.h>
#include <string.h>


int main(){
	char a[65];
	int b, i;

scanf("%s", a);

b=strlen(a);

for(i=b-1;i>=0;i--){
	printf("%d", (int)a[i]-48);
}
printf("\n");
	return 0;
}