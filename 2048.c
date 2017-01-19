/**      @file: Trabalho 2
 *     @author: Gabriel Guimaraes Almeida de Castro
 * @disciplina: Algoritmos e Programação de Computadores */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

typedef struct{
	char nome[30], dificuldade;
	int tabuleiro[5][5],tam;

}jogo_t;
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void parabens(){
	system("clear");
				printf("#############################################################################\n");
				printf("##        ###      ##  ##    ###      ##      ###      ##    ####  ##      ##\n");
				printf("##   ##   #######  ##  #   #########  ##  ##   ##  ######  #  ###  #  #######\n");
				printf("##        ###      ##   ########      ##       ##      ##  ##  ##  ##    ####\n");
				printf("##   #######   #   ##  ########   ##  ##  ##   ##  ######  ###  #  #####   ##\n");
				printf("##   ########      ##  #########      ##      ###      ##  ####    #      ###\n");
				printf("#############################################################################\n");
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void cima(jogo_t* jogo){
	int i,j,k;
	for(k=0;k<(jogo->tam);k++){
		for(i=1;i<(jogo->tam);i++){
			for(j=(jogo->tam)-1;j>=0;j--){
				if(jogo->tabuleiro[i][j]!=0&&jogo->tabuleiro[i-1][j]==0){
					jogo->tabuleiro[i-1][j]=jogo->tabuleiro[i][j];
					jogo->tabuleiro[i][j]=0;
				}
			}
		}
	}


	for(i=1;i<(jogo->tam);i++){
		for(j=(jogo->tam)-1;j>=0;j--){
			if(jogo->tabuleiro[i][j]!=0&&jogo->tabuleiro[i-1][j]!=0){
				if(jogo->tabuleiro[i][j]==jogo->tabuleiro[i-1][j]){
					jogo->tabuleiro[i-1][j]=2*jogo->tabuleiro[i][j];
					jogo->tabuleiro[i][j]=0;
				}
			}
		}
	}
	for(k=0;k<(jogo->tam);k++){
		for(i=1;i<(jogo->tam);i++){
			for(j=(jogo->tam)-1;j>=0;j--){
				if(jogo->tabuleiro[i][j]!=0&&jogo->tabuleiro[i-1][j]==0){
					jogo->tabuleiro[i-1][j]=jogo->tabuleiro[i][j];
					jogo->tabuleiro[i][j]=0;
				}
			}
		}
	}
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void baixo(jogo_t* jogo){
	int i,j,k;
	for(k=0;k<(jogo->tam);k++){
		for(i=(jogo->tam)-2;i>=0;i--){
			for(j=(jogo->tam)-1;j>=0;j--){
				if(jogo->tabuleiro[i][j]!=0&&jogo->tabuleiro[i+1][j]==0){
					jogo->tabuleiro[i+1][j]=jogo->tabuleiro[i][j];
					jogo->tabuleiro[i][j]=0;
				}
			}
		}
	}
	for(i=jogo->tam-2;i>=0;i--){
		for(j=(jogo->tam)-1;j>=0;j--){
			if(jogo->tabuleiro[i][j]!=0&&jogo->tabuleiro[i+1][j]!=0){
				if(jogo->tabuleiro[i][j]==jogo->tabuleiro[i+1][j]){
					jogo->tabuleiro[i+1][j]=2*jogo->tabuleiro[i][j];
					jogo->tabuleiro[i][j]=0;
				}
			}
		}
	}
	for(k=0;k<(jogo->tam);k++){
		for(i=(jogo->tam)-2;i>=0;i--){
			for(j=(jogo->tam)-1;j>=0;j--){
				if(jogo->tabuleiro[i][j]!=0&&jogo->tabuleiro[i+1][j]==0){
					jogo->tabuleiro[i+1][j]=jogo->tabuleiro[i][j];
					jogo->tabuleiro[i][j]=0;
				}
			}
		}
	}
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void direita(jogo_t* jogo){
	int i,j,k;
	for(k=0;k<(jogo->tam);k++){
		for(i=(jogo->tam)-1;i>=0;i--){
			for(j=(jogo->tam)-2;j>=0;j--){
				if(jogo->tabuleiro[i][j]!=0&&jogo->tabuleiro[i][j+1]==0){
					jogo->tabuleiro[i][j+1]=jogo->tabuleiro[i][j];
					jogo->tabuleiro[i][j]=0;
				}
			}
		}
	}
	for(i=(jogo->tam)-1;i>=0;i--){
		for(j=(jogo->tam)-2;j>=0;j--){
			if(jogo->tabuleiro[i][j]!=0&&jogo->tabuleiro[i][j+1]!=0){
				if(jogo->tabuleiro[i][j]==jogo->tabuleiro[i][j+1]){
					jogo->tabuleiro[i][j+1]=2*jogo->tabuleiro[i][j];
					jogo->tabuleiro[i][j]=0;
				}
			}
		}
	}
	for(k=0;k<(jogo->tam);k++){
		for(i=(jogo->tam)-1;i>=0;i--){
			for(j=(jogo->tam)-2;j>=0;j--){
				if(jogo->tabuleiro[i][j]!=0&&jogo->tabuleiro[i][j+1]==0){
					jogo->tabuleiro[i][j+1]=jogo->tabuleiro[i][j];
					jogo->tabuleiro[i][j]=0;
				}
			}
		}
	}
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void esquerda(jogo_t* jogo){
	int i,j,k;
	for(k=0;k<(jogo->tam);k++){
		for(i=(jogo->tam)-1;i>=0;i--){
			for(j=1;j<=(jogo->tam)-1;j++){
				if(jogo->tabuleiro[i][j]!=0&&jogo->tabuleiro[i][j-1]==0){
					jogo->tabuleiro[i][j-1]=jogo->tabuleiro[i][j];
					jogo->tabuleiro[i][j]=0;
				}
			}
		}
	}
	for(i=(jogo->tam-1);i>=0;i--){
		for(j=1;j<=(jogo->tam)-1;j++){
			if(jogo->tabuleiro[i][j]!=0&&jogo->tabuleiro[i][j-1]!=0){
				if(jogo->tabuleiro[i][j]==jogo->tabuleiro[i][j-1]){
					jogo->tabuleiro[i][j-1]=2*jogo->tabuleiro[i][j];
					jogo->tabuleiro[i][j]=0;
				}
			}
		}
	}
	for(k=0;k<(jogo->tam);k++){
		for(i=(jogo->tam)-1;i>=0;i--){
			for(j=1;j<=(jogo->tam)-1;j++){
				if(jogo->tabuleiro[i][j]!=0&&jogo->tabuleiro[i][j-1]==0){
					jogo->tabuleiro[i][j-1]=jogo->tabuleiro[i][j];
					jogo->tabuleiro[i][j]=0;
				}
			}
		}
	}
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void sair(){
	system("clear");
		printf("Até a próxima!\n");
		sleep(2);
		system("clear");
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void inicio(jogo_t* jogo){
int y,x,k,i,j,r;
	for(y=0;y<(jogo->tam);y++){
		for(x=0;x<(jogo->tam);x++){
		jogo->tabuleiro[y][x]=0;
		}
	}

	for(k=0;k<2;k++){
		do{
		i=rand()%5;
		j=rand()%5;
		r=rand()%8;

			if(jogo->tabuleiro[i][j]==0){
				if(r==0){
				jogo->tabuleiro[i][j]=4;
				}
				if(r!=0){
				jogo->tabuleiro[i][j]=2;
				}
			}

		}while(jogo->tabuleiro==0);
	}
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void novapeca(jogo_t* jogo){
int k,i,j,r;
	

	for(k=0;k<2;k++){

		do{
		i=rand()%5;
		j=rand()%5;
		r=rand()%8;

			if(jogo->tabuleiro[i][j]==0){
				if(r==0){
				jogo->tabuleiro[i][j]=4;
				}
				if(r!=0){
				jogo->tabuleiro[i][j]=2;
				}
			}

		}while(jogo->tabuleiro[i][j]==0);

	}
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void dificuldade(jogo_t *jogo, char menu){
	char teste='0';
	printf("Escolha um nível:\n");
		printf(" 1) FÁCIL \n 2) DIFÍCIL \n 3) VOLTAR AO MENU\n");
		teste=getchar();
		while(teste<'1'||teste>'3'){
			teste=getchar();
			}
			if(teste=='1'){
				jogo->dificuldade='1';
				printf("Nivel FÁCIL escolhido!\n");
				sleep(1);
				system("clear");
				jogo->tam=5;
			}
			if(teste=='2'){
				jogo->dificuldade='2';
				printf("Nivel DIFÍCIL escolhido!\n");
				sleep(1);
				system("clear");
				jogo->tam=4;
			}
			if(teste=='3'){
				system("clear");

			}

}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void jogar(jogo_t*jogo){
int x,z, y,tecla,menu=1,vetor[5][5];
if(jogo->tam!=4&&jogo->tam!=5){
	jogo->tam=5;
}
	inicio(jogo);
	while(menu==1&&(jogo->tam==5)){
		system("clear");
		for(x=0;x<5;x++){
			printf("+");
			for (y=0; y<5;y++){
				printf("------+");
			}
			printf("\n");
			for(y=0;y<5;y++){
				if(jogo->tabuleiro[x][y]!=0)
					printf("| %4d ", jogo->tabuleiro[x][y]);
				else
					printf("|      ");
			
			}
		printf("|\n");
		}
	printf("+------+------+------+------+------+\n");

	printf("0_Para voltar ao menu principal!\n");
	tecla=getchar();

		if(tecla=='w'||tecla=='W'){
			for(y=0;y<(jogo->tam);y++){
				for(x=0;x<(jogo->tam);x++){
					vetor[x][y]=jogo->tabuleiro[x][y];
				}
			}
			cima(jogo);
			z=0;
			for(y=0;y<(jogo->tam);y++){
				for(x=0;x<(jogo->tam);x++){
					if((vetor[x][y])==(jogo->tabuleiro[x][y])){
					z++;
					}
				}
			}
			
			if(z!=25){
			novapeca(jogo);
			}
		}
		else if(tecla=='s'||tecla=='S'){
			for(y=0;y<(jogo->tam);y++){
				for(x=0;x<(jogo->tam);x++){
					vetor[x][y]=jogo->tabuleiro[x][y];
				}
			}
			baixo(jogo);
			z=0;
			for(y=0;y<(jogo->tam);y++){
				for(x=0;x<(jogo->tam);x++){
					if((vetor[x][y])==(jogo->tabuleiro[x][y])){
					z++;
					}
				}
			}
			if(z!=25){
			novapeca(jogo);
			};
		}
		else if(tecla=='d'||tecla=='D'){
			for(y=0;y<(jogo->tam);y++){
				for(x=0;x<(jogo->tam);x++){
					vetor[x][y]=jogo->tabuleiro[x][y];
				}
			}
			direita(jogo);
			z=0;
			for(y=0;y<(jogo->tam);y++){
				for(x=0;x<(jogo->tam);x++){
					if((vetor[x][y])==(jogo->tabuleiro[x][y])){
					z++;
					}
				}
			}
			if(z!=25){
			novapeca(jogo);
			}
		}
		else if(tecla=='a'||tecla=='A'){
			for(y=0;y<(jogo->tam);y++){
				for(x=0;x<(jogo->tam);x++){
					vetor[x][y]=jogo->tabuleiro[x][y];
				}
			}
			esquerda(jogo);
			z=0;
			for(y=0;y<(jogo->tam);y++){
				for(x=0;x<(jogo->tam);x++){
					if((vetor[x][y])==(jogo->tabuleiro[x][y])){
					z++;
					}
				}
			}
			if(z!=25){
			novapeca(jogo);
			}

		}
		else if(tecla=='0'){
			system("clear");
			printf("Tem certeza que deseja sair?\n");
			printf("0_sim\n1_não\n");
			scanf("%d",&menu);
			if(menu==0){
				menu='0';
				system("clear");
			}

		}

	for(y=0;y<(jogo->tam);y++){
		for(x=0;x<(jogo->tam);x++){
			if(jogo->tabuleiro[y][x]==2048){
				parabens();
				sleep(2);
				printf("Você venceu o jogo 2048 %s\n", jogo->nome);
				sleep(3);
				system("clear");
				menu='0';
			}
			
		}
	}
for(y=0;y<(jogo->tam);y++){
		for(x=0;x<(jogo->tam);x++){
			if(jogo->tabuleiro==0){
				z++;
			}
				for(x=1;x<(jogo->tam)-1;x++){
					for(y=0;y<(jogo->tam);y++){
						if(jogo->tabuleiro[x-1][y]==jogo->tabuleiro[x][y]||jogo->tabuleiro[x+1][y]==jogo->tabuleiro[x][y]){
							z++;
						}
					}
				}
				for(x=0;x<(jogo->tam);x++){
					for(y=1;y<(jogo->tam)-1;y++){
						if(jogo->tabuleiro[x][y]==jogo->tabuleiro[x][y+1]||jogo->tabuleiro[x][y]==jogo->tabuleiro[x][y-1]){
							z++;
						}
					}
				}
				for(x=0;x<1;x++){
					for(y=1;y<(jogo->tam)-1;y++){
						if(jogo->tabuleiro[x][y]==jogo->tabuleiro[x][y+1]||jogo->tabuleiro[x][y]==jogo->tabuleiro[x][y-1]){
							z++;
						}
					}
				}
				for(x=4;x<5;x++){
					for(y=1;y<(jogo->tam)-1;y++){
						if(jogo->tabuleiro[x][y]==jogo->tabuleiro[x][y+1]||jogo->tabuleiro[x][y]==jogo->tabuleiro[x][y-1]){
							z++;
						}
					}
				}
				for(x=1;x<(jogo->tam)-1;x++){
					for(y=0;y<1;y++){
						if(jogo->tabuleiro[x][y]==jogo->tabuleiro[x+1][y]||jogo->tabuleiro[x][y]==jogo->tabuleiro[x-1][y]){
							z++;
						}
					}
				}
				for(x=1;x<(jogo->tam)-1;x++){
					for(y=4;y<5;y++){
						if(jogo->tabuleiro[x][y]==jogo->tabuleiro[x+1][y]||jogo->tabuleiro[x][y]==jogo->tabuleiro[x-1][y]){
							z++;
						}
					}
				}

		}
	}
	if(z==0){
		printf("Você perdeu!!! Tente novamente\n");
		sleep(3);
		system("clear");
		menu='0';
	}


	}




		while(menu==1&&(jogo->tam==4)){
		system("clear");
		for(x=0;x<4;x++){
			printf("+");
			for (y=0; y<4;y++){
				printf("------+");
			}
			printf("\n");
			for(y=0;y<4;y++){
				if(jogo->tabuleiro[x][y]!=0)
					printf("| %4d ", jogo->tabuleiro[x][y]);
				else
					printf("|      ");
			
			}
		printf("|\n");
		}
	printf("+------+------+------+------+\n");
	printf("0_Para voltar ao menu principal!\n");
	tecla=getchar();

		if(tecla=='w'||tecla=='W'){
			for(y=0;y<(jogo->tam);y++){
				for(x=0;x<(jogo->tam);x++){
					vetor[x][y]=jogo->tabuleiro[x][y];
				}
			}
			cima(jogo);
			z=0;
			for(y=0;y<(jogo->tam);y++){
				for(x=0;x<(jogo->tam);x++){
					if((vetor[x][y])==(jogo->tabuleiro[x][y])){
					z++;
					}
				}
			}
			
			if(z!=16){
			novapeca(jogo);
			}
		}
		else if(tecla=='s'||tecla=='S'){
			for(y=0;y<(jogo->tam);y++){
				for(x=0;x<(jogo->tam);x++){
					vetor[x][y]=jogo->tabuleiro[x][y];
				}
			}
			baixo(jogo);
			z=0;
			for(y=0;y<(jogo->tam);y++){
				for(x=0;x<(jogo->tam);x++){
					if((vetor[x][y])==(jogo->tabuleiro[x][y])){
					z++;
					}
				}
			}
			if(z!=16){
			novapeca(jogo);
			};
		}
		else if(tecla=='d'||tecla=='D'){
			for(y=0;y<(jogo->tam);y++){
				for(x=0;x<(jogo->tam);x++){
					vetor[x][y]=jogo->tabuleiro[x][y];
				}
			}
			direita(jogo);
			z=0;
			for(y=0;y<(jogo->tam);y++){
				for(x=0;x<(jogo->tam);x++){
					if((vetor[x][y])==(jogo->tabuleiro[x][y])){
					z++;
					}
				}
			}
			if(z!=16){
			novapeca(jogo);
			}
		}
		else if(tecla=='a'||tecla=='A'){
			for(y=0;y<(jogo->tam);y++){
				for(x=0;x<(jogo->tam);x++){
					vetor[x][y]=jogo->tabuleiro[x][y];
				}
			}
			esquerda(jogo);
			z=0;
			for(y=0;y<(jogo->tam);y++){
				for(x=0;x<(jogo->tam);x++){
					if((vetor[x][y])==(jogo->tabuleiro[x][y])){
					z++;
					}
				}
			}
			if(z!=16){
			novapeca(jogo);
			}

		}
		else if(tecla=='0'){
			system("clear");
			printf("Tem certeza que deseja sair?\n");
			printf("0_sim\n1_não\n");
			scanf("%d",&menu);
			if(menu==0){
				menu='0';
				system("clear");
			}

		}

	for(y=0;y<(jogo->tam);y++){
		for(x=0;x<(jogo->tam);x++){
			if(jogo->tabuleiro[y][x]==2048){
				parabens();
				sleep(2);
				printf("Você venceu o jogo 2048 %s\n", jogo->nome);
				sleep(3);
				system("clear");
				menu='0';
			}
		}
	}




for(y=0;y<(jogo->tam);y++){
		for(x=0;x<(jogo->tam);x++){
			if(jogo->tabuleiro==0){
				z++;
			}
				for(x=1;x<(jogo->tam)-1;x++){
					for(y=0;y<(jogo->tam);y++){
						if(jogo->tabuleiro[x-1][y]==jogo->tabuleiro[x][y]||jogo->tabuleiro[x+1][y]==jogo->tabuleiro[x][y]){
							z++;
						}
					}
				}
				for(x=0;x<(jogo->tam);x++){
					for(y=1;y<(jogo->tam)-1;y++){
						if(jogo->tabuleiro[x][y]==jogo->tabuleiro[x][y+1]||jogo->tabuleiro[x][y]==jogo->tabuleiro[x][y-1]){
							z++;
						}
					}
				}
				for(x=0;x<1;x++){
					for(y=1;y<(jogo->tam)-1;y++){
						if(jogo->tabuleiro[x][y]==jogo->tabuleiro[x][y+1]||jogo->tabuleiro[x][y]==jogo->tabuleiro[x][y-1]){
							z++;
						}
					}
				}
				for(x=3;x<4;x++){
					for(y=1;y<(jogo->tam)-1;y++){
						if(jogo->tabuleiro[x][y]==jogo->tabuleiro[x][y+1]||jogo->tabuleiro[x][y]==jogo->tabuleiro[x][y-1]){
							z++;
						}
					}
				}
				for(x=1;x<(jogo->tam)-1;x++){
					for(y=0;y<1;y++){
						if(jogo->tabuleiro[x][y]==jogo->tabuleiro[x+1][y]||jogo->tabuleiro[x][y]==jogo->tabuleiro[x-1][y]){
							z++;
						}
					}
				}
				for(x=1;x<(jogo->tam)-1;x++){
					for(y=3;y<4;y++){
						if(jogo->tabuleiro[x][y]==jogo->tabuleiro[x+1][y]||jogo->tabuleiro[x][y]==jogo->tabuleiro[x-1][y]){
							z++;
						}
					}
				}

		}
	}
	if(z==0){
		printf("Você perdeu!!! Tente novamente\n");
		system("clear");
		menu='0';
	}

	}
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------*/


int main(){
char menu='0';
jogo_t jogo;
jogo.dificuldade='1';
system("clear");
printf("#####################################################################\n");
printf("##        ######     ########     ###    ###     #########         ##\n");
printf("##      #########   ##########    ###    ###    ###     ###        ##\n");
printf("##     ###    ####  ###     ###   ###    ###   ###       ###       ##\n");
printf("##          ####    ###     ###   ###    ###    ###     ###        ##\n");
printf("##        ###       ###     ###   ##########    ###########        ##\n");
printf("##      ###         ###     ###   ###########  ####     ####       ##\n");
printf("##    ####          ###     ###          ###   ###       ###       ##\n");
printf("##    ###########   ###########          ###   ####     ####       ##\n");
printf("##    ###########    #########           ###    ##########         ##\n");
printf("#####################################################################\n");

sleep(3);
system("clear");

printf("Qual é seu nome?\n");
scanf("%s", &jogo.nome[0]);

system("clear");
printf("+++++++++++++++++++++++++++++++++++++++++++\n");
printf("Seja bem vindo %s ao jogo 2048!\n", &jogo.nome[0]);
printf("+++++++++++++++++++++++++++++++++++++++++++\n");
sleep(2);

system("clear");


do{
printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");	
printf("@@    @@@@@   @@@@   @   @  @@@@@@  @@\n");
printf("@@   @   @@  @@  @@  @   @  @    @  @@\n");
printf("@@      @@   @@  @@  @@@@@  @@@@@@  @@\n");
printf("@@    @@     @@  @@      @  @    @  @@\n");
printf("@@   @@@@@@   @@@@       @  @@@@@@  @@\n");
printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n");


printf("O que deseja fazer %s?\n\n", &jogo.nome[0]);
printf(" 1) JOGAR\n\n 2) CONFIGURAÇÕES\n\n 3) INSTRUÇÕES\n\n 4) SAIR\n\n");
	while(menu<'1'||menu>'4'){
	menu=getchar();
	}
	if(menu=='3'){
		system("clear");
		printf("A ideia do jogo 2048 é bem simples: juntar os blocos para formar um no valor de\n 2048. Entretanto, fazer isso não é tão fácil. É necessário usar o raciocínio \npara movimentar os blocos da melhor maneira possível e atingir  o objetivo antes que você fiquei sem movimentos. As teclas usadas para fazer os movimentos são: W,A,S e D.\n 0) Para voltar ao menu\n");
		menu=getchar();
		while(menu!='0'){
		menu=getchar();	
		}
		system("clear");
	}
	if(menu=='4'){
		sair();
		return 0;
	}
	if(menu=='2'){
		system("clear");
		dificuldade(&jogo, menu);
	}
	if(menu=='1'){
		system("clear");
		jogar(&jogo);
	}
	menu='0';
}
while(menu=='0');



	return 0;
}