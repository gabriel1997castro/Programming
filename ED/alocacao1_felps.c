#include  <stdio.h>

// 	int aloca(int numero){

// 		int contador, *numeros;

// 		numeros = (int *)malloc(num*sizeof(int));

// 		for(contador = 0; contador < numero; contador++){
// 			printf("Numero [%d]: ", contador + 1);
// 			scanf("%d", &numeros[contador]);
// 		}

// 	return numeros;
// 	}

// 	float media(int numeros, int numero){

// 		float media = 0.0;
// 		int contador;

// 		for(contador = 0; contador < numero; contador++){

// 			media += numeros[contador];
// 		}
// 	return media/numero;	
// 	}

// 	void exibe(int *numeros, int numero){

// 		int contador;

// 		for(contador = 0; contador < numero; contador++){

// 			printf("%3d", numeros[contador]);
// 		}
// 	}

// 	int main(void){

// 		int numero = 1, *numeros;

// 		while(numero){
// 			printf("Media de quantos numeros (0 para sair): ");
// 			scanf("%d", &numero);

// 			if(numero > 0){
// 				numeros = aloca(numero);
// 				exibe(numeros, numero);
// 				printf("A media dos numeros eh: %.2f\n", media(numeros, numero));
// 				free(numeros);
// 			}
// 		}
// 	}


	void soma(int a, int b){
		int soma;
		soma = 2*a + b;
		printf("%d\n",soma);
	return;
	}

	int main(){
		int a, b;
		scanf("%d %d",&a,&b);
		soma(a,b);
		
	return 0;
	}