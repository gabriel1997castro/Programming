#include <stdio.h>


int main(){
	int v[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
	int i=0, x=0, mes, dia;

	while(scanf("%d %d",&mes,&dia) != EOF){
		if(mes==12){
			if(dia==25){
				printf("E natal!\n");
			}
			if(dia>25){
				printf("Ja passou!\n");
			}
			if(dia==24){
				printf("E vespera de natal!\n");
			}
			if(dia<24){
				x = 25 - dia;
				printf("Faltam %d dias para o natal!\n", x);
			}
		}
		else if(mes<12){
				x = v[mes]-dia;
				for(i=mes+1;i<12;i++){
					x+=v[i];
				}
				x=x+(25);
				printf("Faltam %d dias para o natal!\n", x);
		}
	}


	return 0;
}