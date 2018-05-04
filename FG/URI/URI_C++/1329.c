#include <stdio.h>

int main(){
	int i,j,J,m,h;

	while(scanf("%d", &i)){
		m=0;
		J=0;
		if(i==0)
			return 0;
		else{
			for(h=0;h<i;h++){
				scanf("%d",&j);
				if(j==0)
					m++;
				else
					J++;
			}
		}
		printf("Mary won %d times and John won %d times\n", m, J);
	}

	return 0;
}