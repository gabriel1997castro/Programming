#include <stdio.h>
// Impar, par ou Roubo

int main(){
	int p, j1, j2, r, a, soma;
	scanf("%d", &p);// 1--par   0--impar para o jogador 1
	scanf("%d %d", &j1, &j2);// números escolhidos
	scanf("%d", &r);// r = 0 -> jogador 1 não roubou
	scanf("%d", &a);// a = 0 -> jogador 2 não acusou
	soma =  j1+j2;
	if(r==0 && a==0){
		if(soma%2==0){
			if(p==1)
				printf("Jogador 1 ganha!\n");
			if(p==0)
				printf("Jogador 2 ganha!\n");
		}
		if(soma%2==1){
			if(p==1)
				printf("Jogador 2 ganha!\n");
			if(p==0)
				printf("Jogador 1 ganha!\n");
		}
	}
	else{
		if(r==1 && a==0){
				printf("Jogador 1 ganha!\n");
		}
		if(r==1 && a==1){
			printf("Jogador 2 ganha!\n");
		}
		if(r==0 && a==1){
			printf("Jogador 1 ganha!\n");
		}
	}
	return 0;
}