# include <stdio.h>

int main(){
	int dia1, hora1, minuto1, segundo1;
	int dia2, hora2, minuto2, segundo2;
	int dia, hora, minuto, segundo;

	scanf("Dia %d", &dia1); 
	getchar();
	scanf("%d : %d : %d", &hora1, &minuto1, &segundo1);
	getchar();
	scanf("Dia %d",&dia2);
	getchar();
	scanf("%d : %d : %d", &hora2, &minuto2, &segundo2);
	getchar();
	if (segundo1>segundo2)
		segundo	= segundo2 + (60 - segundo1);
	else
		segundo = segundo2 - segundo1;

	if (segundo2>=segundo1 && minuto2>=minuto1)
		minuto = minuto2 - minuto1;
	if (segundo2<segundo1  && minuto2>minuto1)
		minuto = minuto2 - minuto1 - 1;
	if ((minuto2-minuto1>=0 && hora2>=hora1) || (segundo2-segundo1>=0 && minuto2-minuto1>=0 && hora2>hora1))
		hora = hora2 - hora1;
	else
		hora = hora2 + (24 - hora1);
	if (dia2>dia1){
		if (hora2>=hora1){
			if (minuto2>=minuto1){
				if(segundo2>=segundo1){
					dia = dia2-dia;
				}
				else{
					dia = dia2 -dia1 -1;
				}
			}
			else{
				dia = dia2 -dia1 -1;
			}
		}
		else{
			dia = dia2 -dia1 -1;
		}
	}
	else{
		dia =0;
	}

	printf ("%d dia(s)\n", dia);
	printf ("%d hora(s)\n", hora);
	printf ("%d minuto(s)\n", minuto);
	printf ("%d segundo(s)\n", segundo);
	return 0;
}

