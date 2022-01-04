// LEDA - Implementação de Biblioteca 4 - 12.12.2021
// Inclui alterações realizadas na Implementação de Biblioteca 3

#include "item.h"
#include "quadrado.h"
#include <stdlib.h>
#include <stdio.h>

#define FALSO 0
#define FLAG_ERRO -1

struct item {
    Quadrado *quadrado;
    unsigned int chave;
};

Item *criar_item(unsigned int c,float x, float y, float l) {
    Item *i = (Item*) malloc(sizeof(Item));
    if (i == NULL)
        return NULL;
    i->quadrado = criar_quadrado(x,y,l);
    if (i->quadrado == NULL)
        return NULL;
    i->chave = c;
    return i;
}

void liberar_item(Item **i) {
    liberar_quadrado(&((*i)->quadrado));
    free(*i);
    *i = NULL;
}

void imprimir_item(Item *i) {
    printf("Item: %d\n", i->chave);
    exibir_quadrado(i->quadrado);
}

int buscar_item(Item *i, int v){
    if (v == i->chave) {
        printf("\nRESULTADOS DA BUSCA\n");
        printf("\nItem encontrado: ");
        imprimir_item(i);
    }
    else {
        return FALSO;
    }
}

unsigned int get_chave(Item *i){
    return i->chave;
}

float lado_quadrado (Item *i){
    // get_lado declarado em quadrado
    return get_lado(i->quadrado);
}

float buscar_lado(Item *i, float l){
    if (l == lado_quadrado(i)){
        return lado_quadrado(i);
    }
    return FALSO;
}


// CEFET-MG Leopoldina, Engenharia de Computação
// Laboratório de Estrutura de Dados
// Profº: Henrique Barros Lopes
// Aluna: Bianca da Silva Pinto