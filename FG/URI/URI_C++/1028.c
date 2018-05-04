#include <stdio.h>

int main(){
	int i,n,x,y,j,r;
	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%d %d",&x,&y);

		if(x>y){
			r=x%y;
			j=r;
			if(r==0){
				j=x;
			}
			else{
				while(y%j!=0||x%j!=0){
					j--;
				}
			}
			printf("%d\n",j);
		}
		else if(y>=x){
			r=y%x;
			j=r;
			if(r==0){
				j=x;
			}
			else{
				while(y%j!=0||x%j!=0){
					j--;
				}
			}
			printf("%d\n",j);
		}
	}
	return 0;
}