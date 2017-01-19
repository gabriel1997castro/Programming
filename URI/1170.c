#include <stdio.h>


int main(){
	int n,i,j;
	double a;

	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%lf", &a);
		j=0;
		while(a>1){
			a=a/2;
			j++;
		}
		printf("%d dias\n", j);

	}



	return 0;
}
