/*
 * Simples jogo do campo minado para terminal.
 *
 * Autores:
 * 	- Tales A. Mendonça (talesam@gmail.com)
 *	- Rogério Amorim Gomes (rag.inf@gmail.com)
 *
 * Este programa é software livre; você pode redistribuí-lo e / ou modificá-lo
 * sob os termos da GNU General Public License conforme publicada pela
 * Free Software Foundation; para a versão 2
 *
 * Este programa é distribuído na esperança que possa ser útil,
 * Mas SEM NENHUMA GARANTIA; inclusive, sem a garantia implícita de
 * COMERCIALIZAÇÃO ou de ADEQUAÇÃO A UM DETERMINADO FIM. Veja a
 * GNU General Public License para mais detalhes. 
 */


#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define tmat 10 //31

/*
COR DO FUNDO:
 	preta \033[40m
  	vermelha \033[41m
  	verde \033[42m
  	laranja \033[43m
  	azul \033[44m
  	magenta \033[45m
  	ciano \033[46m
  	branca \033[47m
COR DO PRIMEIRO PLANO:
	preta \033[30m
	vermelha \033[31m
	verde \033[32m
	laranja \033[33m
	azul \033[34m
	magenta \033[35m
	ciano \033[36m
	branca \033[37m
*/

#define cordaborda printf("\033[32m")
#define cordacoordenada printf("\033[33m")
#define cordabomba printf("\033[31m")
#define cordatela printf("\033[35m")
#define cordozero printf("\033[30m")
#define cordofundo printf("\033[37m")
#define cordamensagem printf("\033[37m")

#define bordacima1 printf("┏━━")
#define bordacima2 printf("━━┳━━")
#define bordacima3 printf("━━┓\n")
#define bordabaixo1 printf("┗━━")
#define bordabaixo2 printf("━━┻━━")
#define bordabaixo3 printf("━━┛\n")
#define divisoria1 printf("┣━━")
#define divisoria2 printf("━━╋━━")
#define divisoria3 printf("━━┫\n")
#define lateral printf("┃")

//--------------------------------------------------------------------------------------------------------------
// Declaração dos registros da matriz
typedef struct
{
	int coordenada;
	bool status;
	int tela;
}tmatriz;
//---------------------------------------------------------------------------------------------------------------
// Inicia a matriz
void inicia_matriz(tmatriz matriz[tmat][tmat])
{
	int i,j,ini=0;
	for (i=0;i<tmat;i++)
	{
		for (j=0;j<tmat;j++)
		{
			matriz[i][j].coordenada=ini;  //numero do campo da matriz. Para o jogador escolher qual campo abrir
			matriz[i][j].status=false;  //true=aberto false=fechado
			matriz[i][j].tela=0;  //conteúdo do campo da matriz
			ini+=1;
		}
	}
}
//---------------------------------------------------------------------------------------------------------------
// Coloca as Bombas
void coloca_bomba(tmatriz matriz[tmat][tmat],int bomba)
{
	int i,j,l=0;
	while (l<bomba)
	{
		i=rand()%tmat;
		j=rand()%tmat;
		if (matriz[i][j].tela!=10)
		{
			matriz[i][j].tela=10;
			l+=1;
		}
	}
}
//---------------------------------------------------------------------------------------------------------------
// Calcula quantas bombas estão no quadrante próximo
void calcula_bomba(tmatriz matriz[tmat][tmat])
{
	int i,j,k,l,maxi,maxj,cont;
	for (i=0;i<tmat;i++) 
	{		
		for (j=0;j<tmat;j++)
		{
			if (matriz[i][j].tela!=10)
			{
				cont=0;
				if (i==0)
				{
					maxi=i+2;
					if (j==0)
					{
						maxj=j+2;
						for (k=i;k<maxi;k++) 
						{		
							for (l=j;l<maxj;l++)
							{
								if (matriz[k][l].tela==10)
								{
									cont+=1;
								}
							}
						}	
					}
					if (j==tmat-1)
					{
						maxj=j+1;
						for (k=i;k<maxi;k++) 
						{		
							for (l=j-1;l<maxj;l++)
							{
								if (matriz[k][l].tela==10)
								{
									cont+=1;
								}
							}
						}	
					}
					if (j>0 && j<tmat-1)
					{
						maxj=j+2;
						for (k=i;k<maxi;k++) 
						{		
							for (l=j-1;l<maxj;l++)
							{
								if (matriz[k][l].tela==10)
								{
									cont+=1;
								}
							}
						}
					}
				}
				if (i==tmat-1)
				{
					maxi=i+1;
					if (j==0)
					{
						maxj=j+2;
						for (k=i-1;k<maxi;k++) 
						{		
							for (l=j;l<maxj;l++)
							{
								if (matriz[k][l].tela==10)
								{
									cont+=1;
								}
							}
						}
					}
					if (j==tmat-1)
					{
						maxj=j+1;
						for (k=i-1;k<maxi;k++) 
						{		
						for (l=j-1;l<maxj;l++)
							{
								if (matriz[k][l].tela==10)
								{
									cont+=1;
								}
							}
						}
					}
					if (j>0 && j<tmat-1)
					{
						maxj=j+2;
						for (k=i-1;k<maxi;k++) 
						{		
							for (l=j-1;l<maxj;l++)
							{
								if (matriz[k][l].tela==10)
								{
									cont+=1;
								}
							}
						}
					}
				}
				if (i>0 && i<tmat-1)
				{
					maxi=i+2;
					if (j==0)
					{
						maxj=j+2;
						for (k=i-1;k<maxi;k++) 
						{		
							for (l=j;l<maxj;l++)
							{
								if (matriz[k][l].tela==10)
								{
									cont+=1;
								}
							}
						}
					}
					if (j==tmat-1)
					{
						maxj=j+1;
						for (k=i-1;k<maxi;k++) 
						{		
							for (l=j-1;l<maxj;l++)
							{
								if (matriz[k][l].tela==10)
								{
									cont+=1;
								}
							}
						}
					}
					if (j>0 && j<tmat-1)
					{
						maxj=j+2;
						for (k=i-1;k<maxi;k++) 
						{		
							for (l=j-1;l<maxj;l++)
							{
								if (matriz[k][l].tela==10)
								{
									cont+=1;
								}
							}
						}
					}
				}
			matriz[i][j].tela=cont;
			}
		}
	}
}
//---------------------------------------------------------------------------------------------------------------
// Desenha o tabuleiro, mostrando coordenadas e o valor dos campos
void desenhar(tmatriz matriz[tmat][tmat])
{
int i,j,k;
//Desenha a borda superior
cordaborda;
bordacima1;
for (k=1;k<tmat;k++) 
{
	bordacima2;
}
bordacima3;
//Loop para desenhar o meio e colocar os valores
for (i=0;i<tmat;i++)
{
	for (j=0;j<tmat;j++)
	{
		cordaborda;
		lateral;
		// Teste para desenhar os valores
		if (matriz[i][j].status==true)
		{
			if (matriz[i][j].tela==9)
			{
				cordozero;
				printf(" %02d ",matriz[i][j].tela);
			}
			if (matriz[i][j].tela==10)
			{
				cordabomba;
				printf(" BB ");
			}
			if (matriz[i][j].tela<9)
			{
				cordatela;
				printf(" %02d ",matriz[i][j].tela);
			}
		}
		if (matriz[i][j].status==false)
		{
		cordacoordenada;
		printf(" %02d ",matriz[i][j].coordenada);
		}
		// fim do teste
	}
	cordaborda;
	lateral;
	printf("\n");
	if (i<tmat-1)
	{
		divisoria1;
		for (k=1;k<tmat;k++) 
		{
			divisoria2;
		}
		divisoria3;
	}
}
//Desenha a borda inferior
bordabaixo1;
for (k=1;k<tmat;k++) 
{
	bordabaixo2;
}
bordabaixo3;
}
//---------------------------------------------------------------------------------------------------------------
// Abre os campos em volta com 0
int abrindo_zero(tmatriz matriz[tmat][tmat],int i,int j,int& acerto)
{
int maxi,maxj,k,l;
	matriz[i][j].tela=9;
	if (i==0)
	{
		maxi=i+2;
		if (j==0)
		{
			maxj=j+2;
			for (k=i;k<maxi;k++) 
			{		
				for (l=j;l<maxj;l++)
				{
					if (matriz[k][l].status==false)
					{
						matriz[k][l].status=true;
						acerto+=1;
					}
					if (matriz[k][l].tela==0)	
					{
						abrindo_zero(matriz,k,l,acerto);
					}
				}
			}	
		}
		if (j==tmat-1)
		{
			maxj=j+1;
			for (k=i;k<maxi;k++) 
			{		
				for (l=j-1;l<maxj;l++)
				{
					if (matriz[k][l].status==false)
					{
						matriz[k][l].status=true;
						acerto+=1;
					}
					if (matriz[k][l].tela==0)	
					{
						abrindo_zero(matriz,k,l,acerto);
					}
				}
			}	
		}
		if (j>0 && j<tmat-1)
		{
			maxj=j+2;
			for (k=i;k<maxi;k++) 
			{		
				for (l=j-1;l<maxj;l++)
				{
					if (matriz[k][l].status==false)
					{
						matriz[k][l].status=true;
						acerto+=1;
					}
					if (matriz[k][l].tela==0)	
					{
						abrindo_zero(matriz,k,l,acerto);
					}
				}
			}
		}
	}
	if (i==tmat-1)
	{
		maxi=i+1;
		if (j==0)
		{
			maxj=j+2;
			for (k=i-1;k<maxi;k++) 
			{		
				for (l=j;l<maxj;l++)
				{
					if (matriz[k][l].status==false)
					{
						matriz[k][l].status=true;
						acerto+=1;
					}
					if (matriz[k][l].tela==0)	
					{
						abrindo_zero(matriz,k,l,acerto);
					}
				}
			}
		}
		if (j==tmat-1)
		{
			maxj=j+1;
			for (k=i-1;k<maxi;k++) 
			{		
				for (l=j-1;l<maxj;l++)
				{
					if (matriz[k][l].status==false)
					{
						matriz[k][l].status=true;
						acerto+=1;
					}
					if (matriz[k][l].tela==0)	
					{
						abrindo_zero(matriz,k,l,acerto);
					}
				}
			}
		}
		if (j>0 && j<tmat-1)
		{
			maxj=j+2;
			for (k=i-1;k<maxi;k++) 
			{		
				for (l=j-1;l<maxj;l++)
				{
					if (matriz[k][l].status==false)
					{
						matriz[k][l].status=true;
						acerto+=1;
					}
					if (matriz[k][l].tela==0)	
					{
						abrindo_zero(matriz,k,l,acerto);
					}
				}
			}
		}
	}
	if (i>0 && i<tmat-1)
	{
		maxi=i+2;
		if (j==0)
		{
			maxj=j+2;
			for (k=i-1;k<maxi;k++) 
			{		
				for (l=j;l<maxj;l++)
				{
					if (matriz[k][l].status==false)
					{
						matriz[k][l].status=true;
						acerto+=1;
					}
					if (matriz[k][l].tela==0)	
					{
						abrindo_zero(matriz,k,l,acerto);
					}
				}
			}
		}
		if (j==tmat-1)
		{
			maxj=j+1;
			for (k=i-1;k<maxi;k++) 
			{		
				for (l=j-1;l<maxj;l++)
				{
					if (matriz[k][l].status==false)
					{
						matriz[k][l].status=true;
						acerto+=1;
					}
					if (matriz[k][l].tela==0)	
					{
						abrindo_zero(matriz,k,l,acerto);
					}
				}
			}
		}
		if (j>0 && j<tmat-1)
		{
			maxj=j+2;
			for (k=i-1;k<maxi;k++) 
			{		
				for (l=j-1;l<maxj;l++)
				{
					if (matriz[k][l].status==false)
					{
						matriz[k][l].status=true;
						acerto+=1;
					}
					if (matriz[k][l].tela==0)	
					{
						abrindo_zero(matriz,k,l,acerto);
					}
				}
			}
		}
	}
}
//---------------------------------------------------------------------------------------------------------------
// Loop para ler a opçao escolhida pelo jogador
void escolha_coordenada(tmatriz matriz[tmat][tmat],int x,bool& parada,int& acerto)
{
int i,j,k,l;
	for (i=0;i<tmat;i++) 
	{		
		for (j=0;j<tmat;j++)
		{	
			if (matriz[i][j].coordenada==x)
			{
				if (matriz[i][j].tela==10) //se for bomba a opçao escolhida fim de jogo
				{
					for (k=0;k<tmat;k++)
					{
						for (l=0;l<tmat;l++)
						{
							matriz[k][l].status=true;  //true=aberto false=fechado
						}
					}
					printf("\n>>>>>>>>>>>>>> Você perdeu!! <<<<<<<<<<<<<<\n");
					printf(">>>>>>>>>>>> Tente Novamente <<<<<<<<<<<<<<\n\n");
					desenhar(matriz);
					parada=false;break;
				}
				if (matriz[i][j].tela==0) //se a opçao escolhida for um 0 vai abrir os q estiverem em volta
				{
					abrindo_zero(matriz,i,j,acerto);break;
				}
				if (matriz[i][j].tela>0 && matriz[i][j].tela<10) //qualquer outra opçao abre e continua o jogo
				{
					acerto+=1;
					matriz[i][j].status=true;break;
				}
			}
		}
	}	
}
//---------------------------------------------------------------------------------------------------------------
int lendo_bombas()
{
int x;
	printf("Escolha a dificuldade:\n\n");
	printf("1 - Super Mega Ultra facil!\n");
	printf("2 - Fácil\n");
	printf("3 - Médio\n");
	printf("4 - Difícil\n");
	printf("5 - Extremamente difícil\n");
	printf("6 - Deus!\n");
	printf("0 - SAIR\n");
	printf("\nDigite a opção desejada: ");
	scanf("%d", &x);
return (x);
}
//---------------------------------------------------------------------------------------------------------------
void cabecario()
{
	cordamensagem;
	printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ PSEUDO CAMPO MINADO ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ por TALES e RAG ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n\n\n");
}
//---------------------------------------------------------------------------------------------------------------
int lendo_escolhas()
{
int x;
	cordamensagem;
	printf("\n\nDigite o código do campo para abrí-lo: ");
	scanf("%d", &x);
return (x);
}
//---------------------------------------------------------------------------------------------------------------
// Programa Principal
int main()
{
//---------------------------------------------------------------------------------------------------------------
// Declaraçao
	tmatriz matriz[tmat][tmat];
	int qtdbomb,escolha,acerto,k,l;
	bool parada,opcao=true;
	srand(time(NULL));
//---------------------------------------------------------------------------------------------------------------
// Codigo Principal
	printf("\033[40m");
	printf("\033[2J");
	cabecario();
//loop principal
while (opcao==true)
{
	inicia_matriz(matriz);
	qtdbomb=lendo_bombas();
	while (qtdbomb<0 || qtdbomb>6)
	{
		printf("\033[2J");
		cabecario();
		printf(">>>>>>> Valor digitado inválido, por favor, digite números de 1 a 6 <<<<<<<\n\n");
		qtdbomb=lendo_bombas();
	}
	switch (qtdbomb)
	{
		case 1:qtdbomb=1;break;
		case 2:qtdbomb=tmat*1;break;
		case 3:qtdbomb=tmat*2;break;
		case 4:qtdbomb=tmat*3;break;
		case 5:qtdbomb=(tmat*tmat)/2;break;
		case 6:qtdbomb=(tmat*tmat)-1;break;
		case 0:return 1;break;
	}
	printf("\n\n");
	coloca_bomba(matriz,qtdbomb);
	calcula_bomba(matriz);
	parada=true;
	acerto=0;
//loop para a escolha do jogador
	while (parada==true)
	{
		printf("\033[2J");
		cabecario();
		desenhar(matriz);
		printf("\nVocê já abriu %d campos, faltam apenas %d !!!\n",acerto,(tmat*tmat)-(qtdbomb+acerto));
		escolha=lendo_escolhas();
		while (escolha<0 || escolha>99)
		{
			printf("\n\n>>>>>>> Valor digitado inválido, por favor, digite números de 0 a 99 <<<<<<<\n\n");
			escolha=lendo_escolhas();		
		}
		escolha_coordenada(matriz,escolha,parada,acerto);
		if (acerto==(tmat*tmat)-qtdbomb) // teste de vitoria
		{
			printf("\033[2J");
			cabecario();
			printf(">>>>>>>>>>>>>>>> Parabêns !!! <<<<<><<<<<<<<<\n");
			printf(">>>>>>>>>>>>>> Você Ganhou !!! <<<<<<<<<<<<<<\n");
			desenhar(matriz);
			parada=true;break; //incluido, Tales
			printf("\n\n");
			for (k=0;k<tmat;k++)
			{
				for (l=0;l<tmat;l++)
				{
					matriz[k][l].status=true;  //true=aberto false=fechado
				}
			}
			parada=false;
			desenhar(matriz);
		}
	}
// teste para começar um novo jogo ou nao
	cordamensagem;
	printf("\nDeseja jogar novamente?\n\n");
	printf("1 - Sim\n");
	printf("2 - Não\n\n");
	printf("Digite a opção desejada: ");
	scanf("%d", &opcao);
	switch (opcao)
	{
		case 1:opcao=true;break;
		case 2:opcao=false;break;
	}
	printf("\033[2J");
}
//---------------------------------------------------------------------------------------------------------------
// Fim do programa ^^
	return 0;
}
//---------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------
