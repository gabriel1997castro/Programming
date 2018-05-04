#include <stdio.h>

int main(){
	int n,i;

	while(scanf("%d",&n)!=EOF){
		long long int v[n];
		v[0]=0;
		v[1]=1;
		for(i=2;i<n;i++){
			if(i%2==0)
				v[i]=v[i-1]+v[i-2];
			else
				v[i]=v[i-1]*v[i-2];
		}
		printf("%lld\n",v[n-1]);
	}



	return 0;
}