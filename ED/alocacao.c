#include <stdio.h>
#include <stdlib.h>


int main(void)
{
 char *senha;
 
 senha = (char *) malloc(21*sizeof(char));
 printf("Digite sua senha [ate 20 caracteres]: ");
 scanf("%[^\n]s", senha);
 
 printf("Senha: %s\n", senha);
 printf("Endereço antes da free(): %d\n", &senha);
 
 free(senha);
 
 printf("Endereço depois da free(): %d\n", &senha);

 return 0;
}
