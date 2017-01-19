#include <stdio.h>

int main(){
	long double a, x;
	int i=0;
	
	scanf("%Lf", &a);
	x=a;
	if(a>=10){
		while(x>=10){
			x/=10.0;
			i++;
		}
		if(i>=10)
			printf("+%.4fE+%d\n", x, i);
		else
			printf("+%.4fE+0%d\n", x, i);
	}

	if((a>=1&&a<10)||(a>-10&&a<=-1)){
		printf("%+.4fE+00\n", x);
	}

	if(a>=0&&a<1){
		while(x<1){
			x*=10;
			i++;
		}
		if(i>=10)
			printf("+%.4fE-%d\n", x, i);
		else
			printf("+%.4fE-0%d\n", x, i);
	}
	
	if(a<=-10){
		while(x<=-10){
			x/=10;
			i++;
		}
		if(i<10)
			printf("%.4fE+0%d\n", x, i);
		else
			printf("%.4fE+%d\n", x, i);
	}

	if(a>-1&&a<0){
		while(x>-1){
			x*=10;
			i++;
		}
		if(i>=10)
			printf("%.4fE-%d\n", x, i);
		else
			printf("%.4fE-0%d\n", x, i);
	}

	return 0;
}