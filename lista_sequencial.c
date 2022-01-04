// LEDA - 28.10.2021, 04.11.2021

#include <stdio.h>
#include <stdlib.h>
#include "lista_sequencial.h"

#define N 1000
#define FLAG_ERRO -1
#define VERDADEIRO 1
#define FALSO 0

int atribuicao_sequencial, comparacao_sequencial;

struct lista_sequencial {
    unsigned int qtde;
    Item *dados[N];
};

Lista_Sequencial *criar_lista_sequencial() {
    Lista_Sequencial *l = (Lista_Sequencial*) malloc(sizeof(Lista_Sequencial));
    if (l == NULL)
        return NULL;
    l->qtde = 0;
    return l;
}

int lista_cheia(Lista_Sequencial *l) {
    if (l == NULL)
        return FALSO;
    if (l->qtde == N)
        return VERDADEIRO;
    else
        return FALSO;
}

int lista_vazia(Lista_Sequencial *l) {
    if (l == NULL)
        return FALSO;
    return (l->qtde == 0);
}

int lista_tamanho(Lista_Sequencial *l) {
    if (l != NULL)
        return l->qtde;
    else
        return FLAG_ERRO;
}

int inserir_fim_lista(Lista_Sequencial *l, Item *i) {
    if (lista_cheia(l)) {
        return FALSO;
    }
    else {
        comparacao_sequencial++;
        l->dados[l->qtde] = i;
        atribuicao_sequencial++;
        l->qtde++;
        return VERDADEIRO;
    }
}

void exibir_lista(Lista_Sequencial *l){
    if(l == NULL)
        return;
    int i;
    for(i = 0; i < l->qtde; i++)
        imprimir_item(l->dados[i]);
}

int remover_fim_lista(Lista_Sequencial *l){
    if(lista_vazia(l))
        return FALSO;
    liberar_item(&(l->dados[l->qtde-1]));
    l->qtde--;
    return VERDADEIRO;
}

void esvaziar_lista(Lista_Sequencial *l){
    //while (l->qtde > 0)
    while (!lista_vazia(l))
        remover_fim_lista(l);
}

void liberar_lista(Lista_Sequencial **l){
    esvaziar_lista(*l);
    free(*l);
    *l = NULL;
}

int buscar_elemento_seq(Lista_Sequencial *l, float lado){
    int n = 0;
    atribuicao_sequencial++;
    while (n < 100){
        comparacao_sequencial++;
        if(lista_vazia(l)){
            comparacao_sequencial++;
            return FALSO;
        }
        int i;
        atribuicao_sequencial++;
        for (i = 0; i < lista_tamanho(l); i++) {
            if (lado_quadrado(l->dados[i]) == lado) {
                comparacao_sequencial++;
                return i;
            }
            comparacao_sequencial++;
            atribuicao_sequencial++;
        }
        if(i == lista_tamanho(l))
            return FLAG_ERRO;
        n++;
    }
}

// Atribui valor 0 para comparacoes e atribuicoes
void reset_sequencial (){
    atribuicao_sequencial = 0;
    comparacao_sequencial = 0;
}

// Imprime a quantidade de atribuicoes e comparacoes encontradas
// Funcao so pode ser usada depois de inserir ou de busca
void atribuicoes_comparacoes_sequencial(){
    printf("Quantidade de comparacoes: %d\n", comparacao_sequencial);
    printf("Quantidade de atribuicoes: %d\n", atribuicao_sequencial);
    reset_sequencial();
}

// Cria uma lista sequencial e organiza o conteudo de forma crescente
void lista_sequencial_crescente(Lista_Sequencial *l){
    int i, chave = 1;
    float x = 0.0, y = 0.0, lado = 1.0;
    for(i = 0; i < N; i++){
        inserir_fim_lista(l,criar_item(chave,x,y,lado));
        chave++;
        x++, y++, lado++;
    }
    atribuicoes_comparacoes_sequencial();
}

// Cria uma lista sequencial e organiza o conteudo de forma decrescente
void lista_sequencial_decrescente(Lista_Sequencial *l){
    int i, chave = 1;
    float x = 999.0, y = 999.0, lado = 1000.0;
    for(i = 0; i < N; i++){\
        inserir_fim_lista(l,criar_item(chave,x,y,lado));
        chave++;
        x--, y--, lado--;
    }
    atribuicoes_comparacoes_sequencial();
}

// Cria uma lista sequencial e organiza o conteudo de forma aleatoria com base nos valores dos lados dos quadrados
void lista_sequencial_aleatoria(Lista_Sequencial *l, float arr[]){
    int i, chave = 1;
    float x = 0.0, y = 0.0, lado;
    for(i = 0; i < N; i++){
        lado = arr[i];
        inserir_fim_lista(l, criar_item(chave,x,y,lado));
        chave++;
        x++, y++;
    }
    atribuicoes_comparacoes_sequencial();
}

// CEFET-MG Leopoldina, Engenharia de Computação
// Laboratório de Estrutura de Dados
// Profº: Henrique Barros Lopes
// Aluna: Bianca da Silva Pinto
