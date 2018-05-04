#include <stdio.h>

int main(){
	int n, i, j;
	scanf("%d", &i);
		for(j=0;j<i;j++){
		scanf("%d", &n);
		if(n<2015)
			printf("%d D.C.\n", 2015-n);
		if(n>=2015){
			printf("%d A.C.\n", n-2014);
		}
	}


	return 0;
}