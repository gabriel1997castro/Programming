#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct livro{
	char nome[30];
	struct livro *prox;
};

struct livro *aloca(){
	return malloc(sizeof(struct livro));
}

void addItem(struct livro *cabeca) {
	struct livro *aux, *novo;
}

int main(){
	struct livro acervo;
return 0;
}