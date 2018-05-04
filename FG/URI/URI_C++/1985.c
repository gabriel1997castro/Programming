#include <stdio.h>


int main(){
	int n, i, prod, q;
	double preco, soma=0;

	scanf("%d", &n);

	for(i=0;i<n;i++){
		scanf("%d %d", &prod, &q);
		if(prod==1001){
			preco = 1.5*q;
		}
		if(prod==1002){
			preco = 2.5*q;
		}
		if(prod==1003){
			preco = 3.5*q;
		}
		if(prod==1004){
			preco = 4.5*q;
		}
		if(prod==1005){
			preco = 5.5*q;
		}
		soma+=preco;
	}

	printf("%.2lf\n", soma);

	return 0;
}