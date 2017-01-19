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

int main(){
    treeG *a1;
    FILE *arq;

    arq = fopen("arvoreG.txt", "r");

    constroi_tree_pre(arq, &a1);

    percorrer_tree_pre(a1);

    printf("\n");

    le_treeG_transforma_txt(&a1);
    }