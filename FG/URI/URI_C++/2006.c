#include <stdio.h>


int main(){
	int a, v[5], b=0, i;

	scanf("%d", &a);
	for(i=0;i<5;i++){
		scanf("%d", &v[i]);
		if(v[i]==a){
			b++;
		}
	}

	printf("%d\n", b);


	return 0;
}