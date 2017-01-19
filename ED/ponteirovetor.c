#include <stdio.h>


int main(){
	int vetor[3] = {1,2,3};
	int *ponteiro = vetor; // Não é necessário identificar o tamanho do ponteiro
//Não é necessário identificar que é o endereço (&)
//ele vai apontar o primeiro elemento

//Se colocassemos int *ponteiro = &vetor[4], ele vai apontar só o quarto membro do vetor
	printf("O primeiro elemento do vetor é%d\n", *ponteiro);
	printf("O endereço de memória do primeiro elemento do vetor é %d\n", ponteiro);
	//O mais certo é colocar %p ao invés de %d para endereço de ponteiro
	//Se eu fizer ++ponteiro ele pula para o próximo membro do vetor

	return 0;
}