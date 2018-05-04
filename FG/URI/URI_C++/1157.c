#include <stdio.h>

int main(){
	int n,i,j,g,h,o,p,k;
	scanf("%d", &n);
	int v[n][n];
	v[0][0]=1;
	if(n>1){
		for (i=1;i<n+1;i++){
			for(j=1;j<n;j++){
				if(j>=1&&i==1){
					v[i-1][j]=2*v[i-1][j-1];
				}
				else{
					v[i-1][0]=2*v[i-2][0];
					v[i-1][j]=2*v[i-1][j-1];
				}
			}
		}
	}

	g=v[n-1][n-1]/2;
	if(g<5)
		h=1;
	if(g<50)
		h=2;
	if(g<500)
		h=3;
	if(g<5000)
		h=4;
	if(g<50000)
		h=5;
	if(g<500000)
		h=6;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			o=v[i][j+1]/2;
			if(o<5)
				p=1;
			if(o<50)
				p=2;
			if(o<500)
				p=3;
			if(o<5000)
				p=4;
			if(o<50000)
				p=5;
			if(o<500000)
				p=6;

			if(j>0&&j<n){
				for(k=0;k<=h-p;k++)
					printf(" ");
			}

			printf("%d", v[i][j]);
		}
		printf("\n");
	}

	return 0;
}