#include <stdio.h>
#include <stdlib.h>

typedef struct element_tree {
    char dado;
    struct element_tree *filho, *irmao;
    }treeG;

void constroi_tree_pre(FILE *arq, treeG **ainicio){
    char c;

    if ((c = getc(arq)) != EOF){
        if (c=='.'){
            *ainicio = NULL;
            }
        else{
            *ainicio = malloc(sizeof(treeG));
            (*ainicio)->dado = c;
            constroi_tree_pre(arq, &((*ainicio)->filho));
            constroi_tree_pre(arq, &((*ainicio)->irmao));
            }
        }
    }

void le_treeG_transforma_txt(treeG **ainicio){
    treeG *a1;
    int n;

    if (*ainicio != NULL){
        printf("%c", (*ainicio)->dado);
        a1 = (*ainicio)->filho;
        n = 0;
        while (a1 != NULL){
            n+=1;
            a1 = a1->irmao;
            }
        printf("%d\n", n);
        le_treeG_transforma_txt(&((*ainicio)->irmao));
        le_treeG_transforma_txt(&((*ainicio)->filho));
        }
    }

treeG *procura_tree(treeG *ainicio, char chave) {
    treeG *x;
    x = NULL;

    if (ainicio != NULL){
        if (ainicio->dado == chave){
            x = ainicio;
        }
        if (x == NULL){
            x = procura_tree(ainicio->filho, chave);
        }
        if (x == NULL){
            x = procura_tree(ainicio->irmao, chave);
        }
    }
    return x;
}


void percorrer_tree_pre(treeG *ainicio){
    if (ainicio != NULL){
        printf("%c", ainicio->dado);
        percorrer_tree_pre(ainicio->filho);
        percorrer_tree_pre(ainicio->irmao);
        }
    else{
        printf(".");
        }
    }

void insertG(char dadonovo, char dadopai){
    FILE *arq;
    treeG *a1, *a2, *a3;

    arq = fopen("arvoreg.txt", "r");
    constroi_tree_pre(arq, &a1);
    percorrer_tree_pre(a1);
    a2 = procura_tree(a1, dadopai);
        a3 = malloc(sizeof(treeG));
        a3->dado = dadonovo;
        a3->filho = NULL;
        a3->irmao = a2->filho;
        a2->filho = a3;
    printf("\n");

    percorrer_tree_pre(a1);
}


int main(){
    insertG('Z', 'C');
    return(0);
}