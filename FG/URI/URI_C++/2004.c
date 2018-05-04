#include <stdio.h>

int main(){
	int Q,i,j,N;

	scanf("%d",&Q);

	for(i=0;i<Q;i++){
		scanf("%d", &N);
		int T[N],P[N];
		for(j=0;j<N;j++){
			scanf("%d %d",&T[j],&P[j]);
		}
		for(j=0;j<N;j++){
			for(k=0;k<N;k++){
				if(T[j]==T[k])
					if(P[j]<=100&&P[j]>=10)
						if(P[j]>P[k])
			}
		}
	}

	return 0;
}