// LEDA - 11.11.2021, 18.11.2021
// LEDA - Implementação de Biblioteca 3 - 28.11.2021

#include <stdlib.h>
#include <stdio.h>
#include "lista_encadeada.h"

#define N 1000
#define FALSO 0
#define VERDADEIRO 1
#define FLAG_ERRO -1

int atribuicao_encadeada, comparacao_encadeada;

struct celula{
    Item *i;
    Celula *prox;
};

struct lista_encadeada{
    Celula *primeiro, *ultimo;
};

Lista_Encadeada *criar_lista_encadeada(){
    Lista_Encadeada *l = (Lista_Encadeada*) malloc(sizeof(Lista_Encadeada));
    if (l == NULL)
        return NULL;
    l->primeiro = (Celula*) malloc(sizeof(Celula));
    if (l->primeiro == NULL) {
        return NULL;
    }
    l->ultimo = l->primeiro;
    l->primeiro->prox = NULL;
    return l;
}

int lista_encadeada_vazia(Lista_Encadeada *l){
    return(l->primeiro == l->ultimo);
}

void imprimir_lista_encadeada(Lista_Encadeada *l){
    Celula *aux = l->primeiro->prox;
    printf("Lista: \n");
    while (aux != NULL){
        imprimir_item(aux->i);
        aux = aux->prox;
    }
}

int inserir_fim_encadeada(Lista_Encadeada *l, Item *i){
    Celula *aux = (Celula*) malloc(sizeof(Celula));
    atribuicao_encadeada++;
    if (aux == NULL) {
        return FALSO;
    }
    comparacao_encadeada++;
    aux->i = i;
    atribuicao_encadeada++;
    aux->prox = NULL;
    atribuicao_encadeada++;
    l->ultimo->prox = aux;
    atribuicao_encadeada++;
    l->ultimo = aux;
    atribuicao_encadeada++;
    return VERDADEIRO;
}

int remover_fim_encadeada(Lista_Encadeada *l, Item *i){
    if (lista_encadeada_vazia(l))
        return FALSO;
    else {
        Celula * anterior = l->primeiro;
        while(anterior->prox->prox != NULL)
            anterior = anterior->prox;
        //i = clonar_item(l->ultimo->i);
        //i = l->ultimo->i;
        anterior->prox = NULL;
        liberar_item(&(l->ultimo->i));
        free(l->ultimo);
        l->ultimo = anterior;
        return VERDADEIRO;
    }
}

void liberar_lista_encadeada(Lista_Encadeada **l){
    Celula * aux;
    while ((*l)->primeiro->prox != NULL) {
        aux = (*l)->primeiro->prox->prox;
        liberar_celula_le(&((*l)->primeiro->prox));
        (*l)->primeiro->prox = aux;
    }
    free(((*l)->primeiro));
    (*l)->primeiro = NULL;
    free(*l);
    *l = NULL;
}

void liberar_celula_le(Celula **c){
    liberar_item(&((*c)->i));
    free(*c);
    *c = NULL;
}

int buscar_elemento_enc(Lista_Encadeada *l, float lado){
    int n = 0;
    atribuicao_encadeada++;
    while (n < 100) {
        comparacao_encadeada++;
        if (lista_encadeada_vazia(l)) {
            comparacao_encadeada++;
            return FALSO;
        }
        Celula *aux = l->primeiro->prox;
        atribuicao_encadeada++;
        while (aux != NULL) {
            comparacao_encadeada++;
            if (lado == buscar_lado(aux->i, lado)){
                comparacao_encadeada++;
                return get_chave(aux->i);
            }
            aux = aux->prox;
            atribuicao_encadeada++;

            if (aux == NULL) {
                comparacao_encadeada++;
                return FLAG_ERRO;
            }
        }
        n++;
    }
}

// Atribui valor 0 para comparacoes e atribuicoes
void reset_encadeada (){
    atribuicao_encadeada = 0;
    comparacao_encadeada = 0;
}

// Imprime a quantidade de atribuicoes e comparacoes encontradas
// Funcao so pode ser usada depois de inserir ou de busca
void atribuicoes_comparacoes_encadeada(){
    printf("Quantidade de comparacoes: %d\n", comparacao_encadeada);
    printf("Quantidade de atribuicoes: %d\n", atribuicao_encadeada);
    reset_encadeada();
}

// Cria uma lista sequencial e organiza o conteudo de forma crescente
void lista_encadeada_crescente(Lista_Encadeada *l){
    int i, chave = 1;
    float x = 0.0, y = 0.0, lado = 1.0;
    for(i = 0; i < N; i++){
        inserir_fim_encadeada(l,criar_item(chave,x,y,lado));
        chave++;
        x++, y++, lado++;
    }
    atribuicoes_comparacoes_encadeada();
}

// Cria uma lista encadeada e organiza o conteudo de forma decrescente
void lista_encadeada_decrescente(Lista_Encadeada *l){
    int i, chave = 1;
    float x = 999.0, y = 999.0, lado = 1000.0;
    for(i = 0; i < N; i++){\
        inserir_fim_encadeada(l,criar_item(chave,x,y,lado));
        chave++;
        x--, y--, lado--;
    }
    atribuicoes_comparacoes_encadeada();
}

// Cria uma lista encadeada e organiza o conteudo de forma aleatoria com base nos valores dos lados dos quadrados
void lista_encadeada_aleatoria(Lista_Encadeada *l, float arr[]){
    int i, chave = 1;
    float x = 0.0, y = 0.0, lado;
    for(i = 0; i < N; i++){
        lado = arr[i];
        inserir_fim_encadeada(l, criar_item(chave,x,y,lado));
        chave++;
        x++, y++;
    }
    atribuicoes_comparacoes_encadeada();
}

// CEFET-MG Leopoldina, Engenharia de Computação
// Laboratório de Estrutura de Dados
// Profº: Henrique Barros Lopes
// Aluna: Bianca da Silva Pinto
