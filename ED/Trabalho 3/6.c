#include <stdio.h>
#include <stdlib.h>

typedef struct element_tree {
    char dado;
    struct element_tree *esq, *dir;
}tree;

void constroi_tree_pre(FILE *arq, tree **ainicio){
    char c;

    if ((c = getc(arq)) != EOF){
        if (c=='.'){
            *ainicio = NULL;
            }
        else{
            *ainicio = malloc(sizeof(tree));
            (*ainicio)->dado = c;
            constroi_tree_pre(arq, &((*ainicio)->esq));
            constroi_tree_pre(arq, &((*ainicio)->dir));
            }
        }
    }

tree *searchant(tree **ainicio, char chave, tree **eant) {
    tree *a1;

    *eant = NULL;
    a1 = *ainicio;
    while ((a1 != NULL) && (a1->dado != chave)){
        if (a1->dado != chave){
            if (chave < a1->dado){
                *eant = a1;
                a1 = a1->esq;
            }
            else{
                *eant = a1;
                a1 = a1->dir;
            }
        }
    }
    return a1;
}

void Remove(tree **eainicio) {
    if (*eainicio != NULL) {
        Remove (&((*eainicio)->esq));
        Remove (&((*eainicio)->dir));
        free (*eainicio);
        *eainicio = NULL;
    }
}

void remove_menores_iguais(tree **ainicio, char c){
    tree *a1, *ant;

    ant = NULL;
    a1 = searchant(ainicio, c, &ant);
    if (a1 == *ainicio){
        *ainicio = NULL;
    }
    else{
        if(a1 != NULL){
            if (a1 == ant->esq){
                ant->esq = a1->dir;
                a1->dir =NULL;
                Remove(&a1);
            }
            if (a1 == ant->dir){
                ant->dir = a1->dir;
                a1->dir = NULL;
                Remove(&a1);
            }
        }
    }
}

void percorrer_tree_pre(tree *ainicio){
    if (ainicio != NULL){
        printf("%c", ainicio->dado);
        percorrer_tree_pre(ainicio->esq);
        percorrer_tree_pre(ainicio->dir);
        }
    else{
        printf(".");
        }
    }

int main(){

    tree *arv1;
    FILE *arq;

    arq = fopen("arvoredebusca.txt", "r");

    constroi_tree_pre(arq, &arv1);
    percorrer_tree_pre(arv1);
    remove_menores_iguais(&arv1, 'B');
    printf("\n");
    percorrer_tree_pre(arv1);
    printf("\n");
    percorrer_tree_pre(arv1);

}