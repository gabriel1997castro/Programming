#include <stdio.h>


int main(){
	unsigned long long int n, i, roubados=0, nroubados=0, k=0, j=0, c, x=0, h=0;

	scanf("%llu", &n);
	unsigned long long int v[n];

	for(i=0; i<n; i++){
		scanf("%llu", &v[i]);
		k+=v[i];
	}

	for(i=0;i<n;i++){
		if(v[i]%2==0){
			h++;
		}
	}

	i=0;
	while(i>=0&&i<n){
		if(v[i]%2==1){
			c=v[i];
			if(v[i]!=0){
				v[i]=c-1;
				roubados++;
			}
			i++;
			j=i;
		}
		else{

			c=v[i];
			if(v[i]!=0){
				v[i]=c-1;
				roubados++;
			}
			i--;
		}

	}


	if(x>0)
		roubados--;
	nroubados=k-roubados;

	if(h>0)
		j++;
	printf("%llu %llu\n", j, nroubados);
	return 0;
}