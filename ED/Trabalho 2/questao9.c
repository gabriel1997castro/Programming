#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct PILHA
{
  char dado;
  struct PILHA *prox;
}PILHA;

//-------------------------------------------------------------------------------------------------------------------------------//
typedef struct FILA
{
char dado;
struct FILA *prox;
}FILA;

//------------------------------------------------------------------------------------------------------------------------------//
void InicializaPilha(PILHA **pilha)
{                                             
  *pilha = NULL;
  usleep(700000);
  return;
}

//------------------------------------------------------------------------------------------------------------------------------//
void InicializaFila(FILA **fila)
{
  *fila = NULL;
  usleep(700000);
  return;
}

//------------------------------------------------------------------------------------------------------------------------------//
int PilhaVazia(PILHA **pilha)
{
  if((*pilha) == NULL)
    return 1;
  else
    return 0;
}

//-------------------------------------------------------------------------------------------------------------------------------//
int FilaVazia(FILA **fila)
{
  if((*fila)==NULL)
    return 1;
  else
    return 0;
}

//------------------------------------------------------------------------------------------------------------------------------//
char TopoPilha(PILHA *fila)
{
  return fila->dado;
}

//------------------------------------------------------------------------------------------------------------------------------//
void InserePilha(PILHA **pilha,char dadonovo)
{
  PILHA *p1;

  p1 = malloc(sizeof(struct PILHA));
  p1->dado = dadonovo;
  p1->prox = *pilha;
  *pilha = p1;
  return;
}

//------------------------------------------------------------------------------------------------------------------------------//
void InsereFila(FILA **fila, char dadonovo)
{
  FILA *f1, *f2;

  f1 = malloc(sizeof(FILA));
  f1->dado = dadonovo;
  f1->prox = NULL;
  if(*fila == NULL)
    *fila = f1;
  else
  {
    f2 = *fila;
    while(f2->prox != NULL)
      f2 = f2->prox;
    f2->prox = f1;
  }
  f1 = NULL;
  free(f1);
  return;
}

//------------------------------------------------------------------------------------------------------------------------------//
char RetiraPilha(PILHA **pilha)
{
  PILHA *p1;
  char  car;

  p1 = *pilha;
  *pilha = p1->prox;
  car = p1->dado;
  free(p1);
  return car;
}

//------------------------------------------------------------------------------------------------------------------------------//
char RetiraFila(FILA **fila)
{
  FILA *f1;
  char c;

  f1 = *fila;
  *fila = f1->prox;
  c = f1->dado;
  f1 = NULL;
  free(f1);
  return c;
}

//------------------------------------------------------------------------------------------------------------------------------//
void ConversaoParaPosFixada () {
  PILHA *p1;
  FILA *f1;
  char c, aux;
  FILE *arq;

  int Prioridade (char c1) 
  {

    switch (c1) 
    {
      case '^' : return 1; break;
      case '*' : case '/' : return 2; break;
      case '+' : case '-' : return 3; break;
      case '(' : return 4; break;
    }    
  }

  InicializaPilha (&p1);
  InicializaFila (&f1);
  arq = fopen ("t2-9.txt", "r");
  while ((c = getc (arq)) != EOF)
  {
    if (c != '\n')
    {
      if ((c!='^')&&(c!='+')&&(c!='-')&&(c!='*')&&(c!='/')&&(c!='(')&&(c!=')'))
      InsereFila (&f1, c);
      else 
        if (c==')') 
        {
          while (TopoPilha(p1) != '(')
          InsereFila (&f1, RetiraPilha (&p1));
          aux = RetiraPilha (&p1);
        }   
        else 
        {
          if ((c!='(') && (!PilhaVazia (&p1)))
            while ((!PilhaVazia (&p1)) && (Prioridade(TopoPilha (p1)) <= Prioridade (c)))
            InsereFila (&f1, RetiraPilha (&p1));          
            InserePilha (&p1,c);
        }
    }
  }
  fclose (arq);
  printf("Expressão convertida:\n");
  while (!PilhaVazia (&p1))
    InsereFila (&f1, RetiraPilha (&p1));
  while (!FilaVazia (&f1))
    printf ("%c", RetiraFila (&f1));
  printf("\n");
  getchar();
}

//------------------------------------------------------------------------------------------------------------------------------//
int main()
{
  int i,j,n=1,vazia;
  PILHA *pilha;
  FILA *fila;
  char dadonovo,h;
  InicializaPilha(&pilha);

  while(n!=0)
  {
    system("clear");
    printf("______________________________________\n");
    printf("|0) Sair                             |\n");
    printf("|1) Converter para forma pós-fixada  |\n");
    printf("|____________________________________|\n");
    scanf("%d", &n);
    getchar();

    if(n==0)
    {
      system("clear");
      return 0;
    }
    if(n==1)
    {
      ConversaoParaPosFixada();
    }
  }

  return 0;
}