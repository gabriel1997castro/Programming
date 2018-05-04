#include <stdio.h>

int main(){
	int n,i,j,h4,h1;
	while(scanf("%d",&n)!=EOF){
		int v[n][n];
		h1 = n / 3;
		h4 = ((n-1)/2);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				v[i][j]=0;

		for(i=h1;i<n-h1;i++){
			for(j=h1;j<n-h1;j++){
				v[i][j]=1;
			}
		}
		v[h4][h4]=4;

		for(i=0;i<h1;i++){
			for(j=0;j<h1;j++){
				if(i==j){
					v[i][j]=2;
				}
			}
		}

		for(i=n-h1;i<n;i++){
			for(j=n-h1;j<n;j++){
				if(i==j){
					v[i][j]=2;
				}
			}
		}

		for(i=n-h1;i<n;i++){
			for(j=0;j<h1;j++){
				if(i+j==n-1){
					v[i][j]=3;
					v[j][i]=3;
				}
			}
		}


		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf("%d", v[i][j]);
			}
			printf("\n");
		}
		printf("\n");

	}


	return 0;
}