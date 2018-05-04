#include <stdio.h>
#include <string.h>

int main(){
	char v[10001];
	int n,a,i;
	float b;


	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",v);
		a=strlen(v);
		b=(float)a/100;
		printf("%.2f\n", b);
	}


	return 0;
}