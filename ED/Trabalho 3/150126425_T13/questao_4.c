#include <stdio.h>
#include <stdlib.h>

typedef struct ARVOREG{
	char c;
	struct ARVOREG *filho,*irmao;
}ARVOREG;

//--------------------------------------------------------------
void ConstroiG(ARVOREG **eainicio,FILE *arq){
	char c;
	if ((c = getc(arq)) != EOF){
        if (c=='.'){
            *eainicio = NULL;
        }
        else{
            *eainicio = malloc(sizeof(ARVOREG));
            (*eainicio)->c = c;
            ConstroiG(&((*eainicio)->filho), arq);
            ConstroiG(&((*eainicio)->irmao), arq);
        }
    }
}

//--------------------------------------------------------------
void LeG(ARVOREG **eainicio){
	ARVOREG *a1;
	int n;

	if(*eainicio != NULL){
		printf("%c%c", (*eainicio)->c,' ');
		a1 = (*eainicio)->filho;
		n = 0;
		while(a1 != NULL){
			n = n + 1;
			a1 = a1->irmao;
		}
		printf("%d", n);
		a1 = (*eainicio)->filho;
		while(a1 != NULL){
			printf("%c %c",' ', a1->c);
			a1 = a1->irmao;
		}
		printf("\n");
		LeG(&((*eainicio)->irmao));
		LeG(&((*eainicio)->filho));
	}
}

//--------------------------------------------------------------
int main(){
	FILE *arq,*arq1;
	ARVOREG *eainicio, *procura;
	arq = fopen("arvoreg.txt","r");

	if(arq == NULL){
		printf("O arquivo não pode ser aberto!\n");
		return 0;;
	}

	ConstroiG(&eainicio, arq);
	fclose (arq);
	LeG(&eainicio);

	return 0;
}