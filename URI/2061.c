#include <stdio.h>

int main(){
	int a, b, i;
	char v[7];


	scanf("%d %d", &a, &b);
	for(i=0;i<b;i++){
		scanf("%s", v);
		getchar();
		if(v[0]=='f'){
			a++;
		}
		if(v[0]=='c'){
			a--;
		}
	}
	printf("%d\n", a);

	return 0;
}