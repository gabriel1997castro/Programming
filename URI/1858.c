# include <stdio.h>

int main(){
	int n,i,menor,k=0;
scanf("%d", &n);
	int v[n];
for(i=0;i<n;i++){
	scanf("%d", &v[i]);
}
menor=v[0];
for(i=0;i<n;i++){
	if(v[i]<menor){
		menor=v[i];
		k=i;
	}
}
printf("%d\n", k+1);

return 0;
}