#include <stdio.h>

struct lista{
	int valor;
	struct lista *proximo;
};



struct lista *procurarValor(struct lista *pLista, int valor){
	while(pLista != (struct lista *)0){
		if(pLista->valor==valor){
			return (pLista);
		}
		else{
			pLista = pLista->proximo;
		}
	}
	return 0;
}

int main(){
	struct lista m1, m2, m3;
	struct lista *resultado, *gancho = &m1;
	int valor;
	m1.valor = 5;
	m2.valor = 10;
	m3.valor = 15;

	m1.proximo = &m2;
	m2.proximo = &m3;
	m3.proximo = 0;

	printf("Digite o valor a ser procurado:\n");
	scanf("%d", &valor);

	resultado = procurarValor(gancho,valor);
	if(resultado==(struct lista*)0)
		printf("Valor não encontrado\n");
	else
		printf("Valor %d encontrado\n", resultado->valor);



	return 0;
}