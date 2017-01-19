/**      @file: Trabalho1.c
 *     @author: Guilherme N. Ramos (gnramos@unb.br)
 *	 @Aluna   : Priscila Andrade da Silva
 *	@Matricula: 160141931
 * @disciplina: Algoritmos e Programação de Computadores
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

typedef struct JOGO{
	char campo[8][8], campoimpresso[8][8];
}JOGO;

void penalidade_100_tentativas();
void imprime_senha();
void jogo_senha(int arrozEfeijao, int valor, int tentativas);
void jogo_senha_penalidade(int arrozEfeijao, int valor, int tentativas);
void limpa();
void CriaCampo(JOGO *campos);



/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/

/*Jogo Senhas comeca aqui*/

void menu_principal(){

	printf("\n");
	system("clear");
	printf("***************************************\n");
	printf("* Skate e Programação de Computadores *\n");
	printf("***************************************\n");
	printf("\n");

	printf("Menu:\n");
	printf("1) Senha\n");
	printf("2) Charadas!\n");
	printf("3) PTP\n");
	printf("4) Campo Minado\n");
	printf("5) Roda a Roda\n");

	printf("6) Sair\n\n");
	printf("Digite o numero de uma das opcoes acima: ");
}
void imprime_senha(){

	printf("\n");
	printf("*********\n");
	printf("* Senha *\n");
	printf("*********\n");
	printf("\n");
}

void jogo_senha(int arrozEfeijao, int valor, int tentativas){

	if (arrozEfeijao < 0 ){
		
		limpa();
		imprime_senha();
		printf("\nInsista, não desita! A vida pode se tornar mais fácil pra quem sempre persiste!\n");
		sleep(2);
		printf("\nE a senha correta era %d :)..\n", valor);
		sleep(2);
		printf("\nO jogo acabou pra você após %d tentativas\n", tentativas+100);
		sleep(2);
	}

	if (arrozEfeijao > 100000){

		printf("Você precisa digitar um valor que esteja entre 0 e 100000.\n");
		sleep(2);

	}

	if ((arrozEfeijao != valor) && (arrozEfeijao <= 100000) && (arrozEfeijao >= 0)) {
			
		if ((arrozEfeijao >= valor-3000) && (arrozEfeijao <= valor+3000)){
			printf("Eita! Lance quentíssimo, você está prestes a acertar!\n");
			if(arrozEfeijao < valor){
				printf("O valor é um pouco maior que %d\n", arrozEfeijao);
			}else{
				printf("O valor é um pouco menor que %d\n", arrozEfeijao);
			}
		}if ((( arrozEfeijao >= valor-10000) && (arrozEfeijao < valor-3000)) || (((arrozEfeijao > valor+3000) && (arrozEfeijao <= valor+10000 )))) {
			printf("Lance quente!Você chegou perto!\n");
			if ((arrozEfeijao < valor)) {
				printf("O valor correto é maior que %d\n", arrozEfeijao);
			}else{
				printf("O valor correto é menor que %d\n", arrozEfeijao);
			}
		}if (((arrozEfeijao >=valor-50000) && (arrozEfeijao < valor-10000)) || ((arrozEfeijao >=valor+10000) && (arrozEfeijao < valor+50000))) {
			
			if (arrozEfeijao < valor){
				printf("Lance frio! O valor é maior que %d\n", arrozEfeijao);
			}else{
				printf("Lance frio! O valor é menor que %d\n", arrozEfeijao);
			}
		}if (((arrozEfeijao > valor-100000) && (arrozEfeijao < valor-50000)) || ((arrozEfeijao > valor + 50000) && (arrozEfeijao < valor+ 100000))){
			if(arrozEfeijao < valor){
				printf("Lance friooooo! O valor é maior que %d\n", arrozEfeijao);
			}else{
				printf("Lance friooooo! O valor é menor que %d\n", arrozEfeijao);
			}
		}
	}else{
		if (tentativas==1 && arrozEfeijao >= 0 && arrozEfeijao <= 100000){
			printf("Parabéns !! %d é o numero correto, e você acertou em apenas %d tentativa!\n\n", arrozEfeijao, tentativas);
			sleep(2);
			printf("Você é fera ! \n\n");
			sleep(1);
			printf("Acredito que você tenha uma grande possibilidade de acertar na mega-sena!\n\n");
			sleep(1);
			printf("Boa sorte! :) \n\n");
			sleep(1);
			
		}else if (tentativas > 1 && arrozEfeijao <= 100000 && arrozEfeijao >= 0){
			printf("Parabéns !! %d é o valor correto. Você acertou em %d tentativas.\n", arrozEfeijao, tentativas);
			sleep(3);
			menu_principal();
		}
	}
}

/*Jogo Senhas termina aqui*/

/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/



/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/
/*Jogo charadas comeca aqui*/

void limpa(){
	system("clear");
}

void menu_charadas(){

	printf("\n");
	limpa();
	printf("*************\n");
	printf("* Charadas! *\n");
	printf("*************\n");
	printf("\n");

	printf("Um 'amigo' foi lhe visitar e levou duas de suas taças favoritas, qual o nome do filme?\n");
	printf("\n1) Exterminador do Futuro 2\n");
	printf("2) O roubo do Banco Central\n");
	printf("3) RoboCop 2\n");
	printf("4) Roubo a Mária\n");
	
}

void acerta_charada(int entrada_charada, int charada_correta, int contador){

	if (entrada_charada == charada_correta){
		printf("\n");
		limpa();
		printf("\nVocê é ninja dos filmes!\n");
		sleep(2);
		printf("Parabéns, você matou a charada! xD\n");
		sleep(2);
		menu_principal();
	}
	if (entrada_charada != charada_correta && contador == 1){
		printf("A vida é assim .. Nem sempre acertamos de primeira :(\n");
		sleep(2);
		printf("Tente outra vez!\n");
		sleep(2);

	}
	if ((entrada_charada != charada_correta) && (contador > 1)){
		printf("Infelizmente você não matou a charada em dois lances =/ \n");
		sleep(2);
		printf("Você está fora do jogo .. \n");
		sleep(3);
		menu_principal();
	}
}

/*Jogo charadas termina aqui*/

/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/






/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/

/*Jogo ppt comeca aqui*/

int max (char a, char b) {
	if (a == 'R') {
		if (b == 'S') return 1;
		return 0;
	}

	if (a == 'S') {
		if (b == 'P') return 1;
		return 0;
	}

	if (a == 'P')
		if (b == 'R') return 1;
	return 0;
}

void menu_ppt(){

	printf("\n");
	limpa();
	printf("  ***********************\n");
	printf("  * Pedra Papel Tesoura *\n");
	printf("  ***********************\n");
	printf("\n\n");

	printf("  R ->> para PEDRA.\n");
	printf("  P ->> para PAPEL. \n");
	printf("  S ->> para TESOURA.\n");
	printf("\n\n");
}

void opcoes_ppt(){

	printf("\n");
	printf(" O que desejam fazer?\n\n");
	printf(" 1) Jogar novamente\n");
	printf(" 2) Voltar ao menu principal\n");

}

void jogoPPT(){
int x;
int beleza = 0;
char g[3];

for (x = 0; x <= 2; x++){

	beleza = 0;
	menu_ppt();
	printf("  Jogador %d: ", x+1);
	scanf("%c", &g[x]);
	getchar();
	if((g[x] == 'R' || g[x] == 'S' || g[x] == 'P')){
		beleza = 1;
	}
	if(beleza == 0){ 
	do{
		limpa();
		menu_ppt();
		printf("Entrada invalida, digite uma das opoes acima.\n");
		printf("  Jogador %d: ", x+1);
		scanf ("%c", &g[x]);
		getchar();
		if((g[x] == 'R' || g[x] == 'S' || g[x] == 'P')){
		beleza = 1;
		}
		limpa();	
	}while(beleza != 1);
	}
}

	if  (((g[0] == g[1]) && (g[1] == g[2]) && (g[2] == g[0])) || ((g[0] != g[1]) && (g[1] != g[2]) && (g[2] != g[0]))){
	printf("\n");
	limpa();
	printf("  Empate triplo\n");
	}
	printf("\n");
	if (max (g[0], g[2])) 
	printf("  Jogador %d ganha do jogador %d\n", 1, 3);
	else if (max (g[2], g[0])) 
	printf("  Jogador %d ganha do jogador %d\n", 3, 1);
	else 
	printf("  Jogador %d empata com jogador %d\n", 1, 3);

	for (x = 0; x < 2; x++){
	if (max (g[x], g[x+1]))
		printf("  Jogador %d ganha do jogador %d\n", x+1, x+2);
	else if (max (g[x+1], g[x]))
		printf("  Jogador %d ganha do jogador %d\n", x+2, x+1);
	else
		printf("  Jogador %d empata com jogador %d\n", x+1, x+2);
	}

}

/*Jogo ppt termina aqui*/

/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/





/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/

/*Jogo Campo minado comeca aqui*/


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

/*Jogo Campo minado termina aqui*/

/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/




int main(){

	int opcao;
	int entrada_cha, p = 1, mata_charada = 3;
	int opcao_ppt;
	int xx=5;
	
	JOGO campos;

	do{	
		limpa();
		menu_principal();
		scanf("%d", &opcao);
		getchar();
		limpa();
		
		switch (opcao){

			case 1: 

				/* (opcao == 1){ */

				srand((unsigned)time(NULL));
				int senha = rand()%100001;
				long long int entrada=0, i=1;

				/* printf("%d\n", senha); */

				imprime_senha();
				printf("O jogo acaba quando:\n");
				sleep(2);
				printf("Você acerta o valor correto ou DESISTE (digitando um valor negativo).\n");
				sleep(3);
				limpa();
				imprime_senha();
				printf("Pense em um numero aee!!\n");
				sleep(2);
				printf("Agora que você ja pensou, digite um valor: ");
				
				do{
					
					if ((i>1) || (i == 1 && entrada > 100000)){
					printf("Digite um novo valor: ");
					}
					scanf(" %lli", &entrada);
					while(getchar()!='\n');


					/* do{ */
					/* }while(getchar()!='\n'); */

					limpa();
					imprime_senha();
					jogo_senha(entrada, senha, i);
					i++;

				}while((entrada!=senha) && (entrada > 0));		
				/*}*/

				break;


			case 2:

				do{
				limpa();
				menu_charadas();
				printf("\nOpção correta: ");
				scanf("%d", &entrada_cha);

				acerta_charada(entrada_cha, mata_charada, p);
				p++;
				}while ((entrada_cha != mata_charada) && (p <= 2));
				menu_principal();
			break;

			case 3:
				do{

					menu_ppt();
					jogoPPT();
					opcoes_ppt();
					scanf("%d", &opcao_ppt);
					getchar();

				}while(opcao_ppt == 1);

				break;

			case 4:
				
				
				system("clear");
				printf("Bem vindo ao jogo Campo Minado, \n\nNão vou gostar nem um pouco de bombardear voce hahahahaaha\n");
				sleep(5);
				system("clear");
				while(xx!=0){
					printf("Digite uma opcao:\n");
					printf("1) Jogar\n");
					printf("2) Sair\n");
					scanf("%d", &xx);
					if(xx==1){
						CriaCampo(&campos);
						IniciaCampoImpresso(&campos);
						jogar(&campos);
						system("clear");
					}
					if(xx==2){
						xx=0;
					}
					else{
						printf("Digite uma opcao valida:\n");
					}
				}
		

		}

			

		/*printf("Digite ENTER para voltar ao menu principal");
		getchar();
		getchar();
		*/
	}while(opcao!=6);

	printf("\n\nEspero que volte novamente para jogar!\n");
	printf("Até mais =)\n\n");
	
	return 0;
}