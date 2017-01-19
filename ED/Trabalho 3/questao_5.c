#include <stdio.h>
#include <stdlib.h>

typedef struct ARVOREG{
	char c;
	struct ARVOREG *filho,*irmao;
}ARVOREG;

//--------------------------------------------------------------
ARVOREG *ProcuraG(ARVOREG *inicio, char chave){
	ARVOREG *a1;

	a1 = NULL;
	if(inicio != NULL){
		if(inicio->c == chave){
			a1 = inicio;
		}
		if(a1 == NULL){
			a1 = ProcuraG(inicio->filho, chave);		
		}
		if (a1 == NULL){
				a1 = ProcuraG(inicio->irmao, chave);
		}	
	}
	return a1;
}

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
void PercorrerG(ARVOREG *a1){
    if (a1 != NULL){
        printf("%c", a1->c);
        PercorrerG(a1->filho);
        PercorrerG(a1->irmao);
    }
    else
        printf(".");
}

//--------------------------------------------------------------
void InsereG(char dadonovo, char pai){
	FILE *arq;
	ARVOREG *a1, *a2, *a3;

	arq = fopen("arvoreg.txt", "r");
	if(arq == NULL){
		printf("O arquivo não pode ser aberto!\n");
		return;
	}
	ConstroiG(&a1, arq);
	fclose (arq);
	PercorrerG(a1);
	printf("\n");
	a2 = ProcuraG(a1, pai);
	a3 = malloc(sizeof(ARVOREG));
	a3->c = dadonovo;
	a3->filho = NULL;
	a3->irmao = a2->filho;
	a2->filho = a3;
	PercorrerG(a1);
	printf("\n");
}

//--------------------------------------------------------------
int main(){
	char dadonovo, pai;

	printf("Digite o dado que deseja inserir a arvore:\n");
	scanf("%c", &dadonovo);
	getchar();
	printf("Digite quem deseja que seja o pai desse elemento:\n");
	scanf("%c", &pai);
	getchar();
	InsereG(dadonovo, pai);
	return 0;
}