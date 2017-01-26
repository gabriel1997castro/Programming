#include <stdio.h>
#include <string.h>

#define SUCO_DE_LARANJA 120
#define MORANGO 85
#define MAMAO 85
#define GOIABA 70
#define MANGA 56
#define LARANJA 50
#define BROCOLIS 34

void vitamina(){
	int t, n, i, soma=0;
	char alimento[25];
	scanf("%d", &t);
	while (t!=0){
		for(i=0;i<t;i++){
			scanf("%d %[^\n]s", &n, alimento);

			if(strcmp(alimento, "suco de laranja")==0)
				soma+=(SUCO_DE_LARANJA*n);
			else if(strcmp(alimento, "morango fresco")==0)
				soma+=(MORANGO*n);
			else if(strcmp(alimento, "mamao")==0)
				soma+=(MAMAO*n);
			else if(strcmp(alimento, "goiaba vermelha")==0)
				soma+=(GOIABA*n);
			else if(strcmp(alimento, "manga")==0)
				soma+=(MANGA*n);
			else if(strcmp(alimento, "laranja")==0)
				soma+=(LARANJA*n);
			else if(strcmp(alimento, "brocolis")==0)
				soma+=(BROCOLIS*n);
		}

		if(soma>130)
			printf("Menos %d mg\n", soma-130);
		else if(soma>=110)
			printf("%d mg\n", soma);
		else if(soma<110)
			printf("Mais %d mg\n", 110 - soma);
		scanf("%d", &t);
		soma = 0;	
	}
}

int main(){
	vitamina();
	return 0;
}