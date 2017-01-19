#include <stdio.h>

int main(){
	int x;
	x = 20;
	int *ponteiro;// ponteiro que aponta um inteiro
	ponteiro = &x;
	printf("o endereço da variável x é :%d e o seu valor é %d\n", &x, x);
	printf("o valor do meu ponteiro é %d\n", *ponteiro);// *algo faz com que seja lido o conteúdo de algo.
	return 0;
}