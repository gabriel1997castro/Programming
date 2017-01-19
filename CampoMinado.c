#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

typedef struct JOGO{
	char campo[8][8], campoimpresso[8][8];
}JOGO;

/*Cria um campo*/
void CriaCampo(JOGO *campos){
	int i,j,k,contador;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			campos->campo[i][j]='0';
		}
	}																					
	/*Gera posição da bomba aleatoriamente*/
	srand(time(NULL));																	
	i=(rand()%6)+1;																		
	j=(rand()%6)+1;													
	for(k=0;k<5;k++){	
		i = ((i+15)%6)+1;
		j = ((j+10)%6)+1;
		campos->campo[i][j]='X';
	}

	/*Coloca o número de bombas adjacentes*/
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			contador = 0;
			if(i!=0&&j!=0&&i!=8&&j!=8&&campos->campo[i][j]=='0'){
				if(campos->campo[i-1][j-1]=='X')
					contador++;
				if(campos->campo[i-1][j]=='X')
					contador++;
				if(campos->campo[i-1][j+1]=='X')
					contador++;
				if(campos->campo[i][j-1]=='X')
					contador++;
				if(campos->campo[i][j+1]=='X')
					contador++;
				if(campos->campo[i+1][j-1]=='X')
					contador++;
				if(campos->campo[i+1][j]=='X')
					contador++;
				if(campos->campo[i+1][j+1]=='X')
					contador++;
				campos->campo[i][j]=(char)contador+48;
			}		
		}
	}

	return;
}

void imprime(JOGO *campos){
	int i, j;
	printf(" | 0   1   2   3   4   5 |\n");
	for(i=1;i<7;i++){
		printf("-+---+---+---+---+---+---+\n");
		for(j=1;j<7;j++){
			if(j==1)
				printf("%d| %c |", i-1,campos->campoimpresso[i][j]);
			else
				printf("%2c |", (campos->campoimpresso[i][j]));
		}
		printf("\n");
	}
		printf("-+---+---+---+---+---+---+\n");
}

void IniciaCampoImpresso(JOGO *campos){
int i, j;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			campos->campoimpresso[i][j] = '#';
		}
	}
}

void Abrir0(JOGO *campos,int j, int i){
	campos->campoimpresso[i][j]     = campos->campo[i][j];
	campos->campoimpresso[i-1][j-1] = campos->campo[i-1][j-1];
	campos->campoimpresso[i-1][j]   = campos->campo[i-1][j];
	campos->campoimpresso[i-1][j+1] = campos->campo[i-1][j+1];
	campos->campoimpresso[i][j-1]   = campos->campo[i][j-1];
	campos->campoimpresso[i][j+1]   = campos->campo[i][j+1];
	campos->campoimpresso[i+1][j-1] = campos->campo[i+1][j-1];
	campos->campoimpresso[i+1][j]   = campos->campo[i+1][j];
	campos->campoimpresso[i+1][j+1]   = campos->campo[i+1][j+1];

	return;
}

int VerificaVitoria(JOGO *campos){
	int i,j,contador;
	for(i=1;i<7;i++)
		for(j=1;j<7;j++)
			if(campos->campoimpresso[i][j] == '#')
				contador++;
	return contador;
	
}

void jogar(JOGO *campos){
	int x, y, a, b;
	system("clear");
	imprime(campos);
	while(scanf("%d %d", &x, &y)){
		x++;
		y++;
		while(x<=0 || y<=0 || x>6 || y>6 || campos->campoimpresso[y][x] != '#'){
			if(campos->campoimpresso[y][x] != '#'&&x<=0 && y<=0 && x>6 && y>6){
				printf("Essa cordenada ja foi decoberta! %c\n", campos->campoimpresso[y][x]);
				printf("Digite uma cordenada valida:\n");
			}
			scanf("%d %d", &x, &y);
			x++;
			y++;
		}
		
		if(campos->campo[y][x]=='X'){
			campos->campoimpresso[y][x] = campos->campo[y][x];
			system("clear");
			imprime(campos);
			printf("Kabummmmmmmm! Você perdeu! Jogue Novamente!\n");
			sleep(3);
			return;
		}
		else if(campos->campo[y][x]>'0'&&campos->campo[y][x]<'8'){
			campos->campoimpresso[y][x] = campos->campo[y][x];
		}
		else if(campos->campo[y][x]=='0'){
			Abrir0(campos, x, y);
			a = x;
			b = y;
			while(campos->campo[y][x+1]=='0' && (x+1)<7){
				x++;
				Abrir0(campos, x, y);
			}
			x = a;
			while(campos->campo[y][x-1]=='0' && (x-1)>0){
				x--;
				Abrir0(campos, x, y);
			}
			x = a;
			while(campos->campo[y+1][x]=='0' && (y+1)<7){
				y++;
				Abrir0(campos, x, y);
			}
			y = b;
			while(campos->campo[y-1][x]=='0' && (y-1)>0){
				y--;
				Abrir0(campos, x, y);
			}
			y = b;



		}
		if(VerificaVitoria(campos)==0){
			printf("Parabéns! Você venceu!!!\n");
			return;
		}
		system("clear");
		imprime(campos);
	}
}

int main(){
	int i,j,x=5;
	JOGO campos;

	system("clear");
	printf("Bem vindo ao jogo Campo Minado, \nnão vou gostar nem um pouco de bombardear voce hahahahaaha\n");
	sleep(4);
	system("clear");
	
	while(x!=0){
		printf("Digite uma opcao:\n");
		printf("1) Jogar\n2) Sair\n");
		scanf("%d", &x);
		if(x=1){
			CriaCampo(&campos);
			IniciaCampoImpresso(&campos);
			jogar(&campos);
			system("clear");
		}
		if(x=2){
			x=0;
		}
		else{
			printf("Digite uma opcao valida:\n");
		}
		
	}

	return 0;
}