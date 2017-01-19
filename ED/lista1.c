#include <stdio.h>
#include <unistd.h>


int main(void){

	struct lista{
		int valor;
		struct lista *proximo;
	};

	struct lista m1, m2, m3, m4;
	struct lista *gancho = &m1;

	m1.valor = 10;
	m2.valor = 20;
	m3.valor = 30;
	m4.valor = 40;

	m1.proximo = &m2;
	m2.proximo = &m3;
	m3.proximo = &m4;
	m4.proximo = (struct lista *)0;

	while(gancho != (struct lista *)0){
		printf("%d\n", gancho->valor);
		gancho = gancho->proximo;
		usleep(100000);
	}
return 0;
}