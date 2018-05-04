#include <stdio.h>
int main(){
	int d,a,r,r1,d1;
	char *v1[]={"I","II","III","IV","V","VI","VII","VIII","IX"};
	char *v2[]={"X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
	char *v3[]={"C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};

	scanf("%d", &a);

	if(a>0&&a<10){
		printf("%s\n", v1[a-1]);
	}

	if(a>=10&&a<100){
		r=a%10;
		d=(a-r)/10;
		if(r>0)
			printf("%s%s\n", v2[d-1], v1[r-1]);
		else
			printf("%s\n", v2[d-1]);
	}

	if(a>=100&&a<1000){
		r=a%100;
		d=(a-r)/100;

		printf("%s", v3[d-1]);
		if(r>=10){
			r1=r%10;
			d1=(r-r1)/10;
			printf("%s", v2[d1-1]);
			if(r1>0){
				printf("%s", v1[r1-1]);
			}
		}
		else
			if(r>0){
				printf("%s", v1[r-1]);
			}
		printf("\n");

	}
	return 0;
}