#include <stdio.h>

int main(){
	int h,m,p,N,i;

	scanf("%d",&N);

	for(i=0;i<N;i++){
		scanf("%d %d %d",&h,&m,&p);
		if(h>9)
			printf("%d:", h);
		else
			printf("0%d:", h);
		if(m>9)
			printf("%d ",m);
		else
			printf("0%d ",m);
		if(p==1)
			printf("- A porta abriu!\n");
		else
			printf("- A porta fechou!\n");

	}


	return 0;
}