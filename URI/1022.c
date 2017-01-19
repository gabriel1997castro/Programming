#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ler(int *N1, int *D1, int *N2, int *D2, char *c){
	scanf("%d", N1);
	getchar();
	getchar();
	getchar();
	scanf("%d", D1);
	getchar();
	scanf("%c", c);
	getchar();
	scanf("%d", N2);
	getchar();
	getchar();
	getchar();
	scanf("%d", D2);
	return;
}

int MDC(int A, int B){
	int resto;
	while(B != 0){
		resto = A % B;
		A = B;
		B = resto;
	}
	return A;
}

void imprimir(int N1, int D1, int N2, int D2, char c){
	int a,b,mdc;
	if(c == '+'){
		a = ((N1*D2)+(N2*D1));
		b = (D1*D2);
	}
	else if(c == '-'){
		a = ((N1*D2)-(N2*D1));
		b = (D1*D2);
	}
	else if(c == '*'){
		a = (N1*N2);
		b = (D1*D2);
	}
	else if(c == '/'){
		a = (N1*D2);
		b = (N2*D1);
	}
	mdc = MDC(a,b);
	if(mdc<0){
		mdc = mdc*(-1);
	}
	printf("%d/%d = %d/%d\n",a, b, a/mdc, b/mdc);
}

int main(){
	int N1, D1, N2, D2,n,i;
	char c;

	scanf("%d", &n);
	for(i=0;i<n;i++){
		ler(&N1, &D1, &N2, &D2, &c);
		imprimir(N1, D1, N2, D2, c);
	}

	return 0;
}