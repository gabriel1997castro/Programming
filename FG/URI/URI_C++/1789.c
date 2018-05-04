#include <stdio.h>

int main(){
	int grupos,i,maior=0,n;
while(scanf("%d", &grupos)!=EOF){
	maior=0;
	for(i=0;i<grupos;i++){
		scanf("%d", &n);
		if(maior<n){
			maior=n;
		}
	} 
	if(maior<10){
		printf("1\n");
	}
	if(maior>=10&&maior<20){
		printf("2\n");
	}
	if(maior>=20){
		printf("3\n");
	}
}

	return 0;
}