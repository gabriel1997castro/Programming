#include <stdio.h>

int main(){
	int n,i,mat1;
	float maior;

	scanf("%d", &n);

	int mat[n];
	float nota[n];

	for(i=0;i<n;i++){
		scanf("%d %f", &mat[i], &nota[i]);
	}
	maior = nota[0];

	for(i=1;i<n;i++){
		if(maior<nota[i]){
			maior = nota[i];
			mat1=mat[i];
		}
	}
	if(maior>=8.0)
		printf("%d\n",mat1);
	else
		printf("Minimum note not reached\n");

	return 0;
}