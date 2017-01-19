#include <stdio.h>

int main(){
	int a, b, c;


	scanf("%d %d", &a, &b);
	if(a > b){
		for(i=b;i<=a;i++){
			c+=i;
		}
	}
		
	else
		for(i=b;i<=a;i++){
			c+=i;
		}
		
		printf("%d\n", c);

	return 0;
}