// LEDA - Implementação de Biblioteca 4 - 12.12.2021
// Biblioteca implementada a partir da aula sincrona de LEDA do dia 25.11.2021 e da Biblioteca 2 - Lista Sequencial

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "lista_ordenada.h"

#define N 1000
#define FLAG_ERRO -1
#define VERDADEIRO 1
#define FALSO 0

int atribuicao_ordenada, comparacao_ordenada;

struct lista_quadrados_ordenada {
    unsigned int qtde;
    Item * dados[N];
};

// Operação para criar uma lista ordenada de quadrados [ordenação crescente por chave do item]
Lista_Quadrados_Ordenada *criar_lista_quad_ordenada(){
    Lista_Quadrados_Ordenada *l = (Lista_Quadrados_Ordenada*) malloc(sizeof(Lista_Quadrados_Ordenada));
    if (l == NULL)
        return NULL;
    l->qtde = 0;
    return l;
}

// Verifica o tamanho da lista ordenada; na função main mostra a quantidade de elementos
int lista_ordenada_tamanho(Lista_Quadrados_Ordenada *l){
    if (l == NULL)
        return FLAG_ERRO;
    else
        return l->qtde;
}

// Verifica se a lista ordenada está cheia ou não
int lista_ordenada_cheia(Lista_Quadrados_Ordenada *l){
    if (l == NULL)
        return FLAG_ERRO;
    if (l->qtde == N)
        return VERDADEIRO;
    else
        return FALSO;
}

// Verifica se a lista ordenada está vazia ou não
int lista_ordenada_vazia(Lista_Quadrados_Ordenada *l){
    if (l == NULL)
        return FLAG_ERRO;
    return (l->qtde == 0);
}

// Remove no fim os elementos da lista ordenada; é possível ativar ou não a liberação dos itens
int remover_fim_lista_ordenada(Lista_Quadrados_Ordenada *l){
    if (lista_ordenada_vazia(l))
        return FALSO;
    //liberar_item(&(l->dados[l->qtde-1]));
    l->qtde--;
    return VERDADEIRO;
}

// Exibe os elementos da lista ordenada
void exibir_lista_ordenada(Lista_Quadrados_Ordenada *l){
    if (l == NULL)
        return;
    int i;
    for (i = 0; i < l->qtde; i++)
        imprimir_item(l->dados[i]);
}

// Insere o item de forma ordenada na lista [somente no início da lista]
int inserir_ordenado(Lista_Quadrados_Ordenada *l, Item *i){
    if(lista_ordenada_cheia(l)) {
        return FALSO;
    }
    comparacao_ordenada++;
    int v;
    atribuicao_ordenada++;
    for (v = 0; v < lista_ordenada_tamanho(l); v++){
        if (lado_quadrado(l->dados[v]) > lado_quadrado(i)){
            comparacao_ordenada++;
            int j;
            atribuicao_ordenada++;
            for(j = lista_ordenada_tamanho(l); j >= v; j--) {
                comparacao_ordenada++;
                l->dados[j + 1] = l->dados[j];
                atribuicao_ordenada++;
            }
            break;
        }
    }
    l->dados[v] = i;
    atribuicao_ordenada++;
    l->qtde++;
    return VERDADEIRO;
}

// Insere o item de forma ordenada na lista [somente no início da lista]
int inserir_ordenado_decrescente(Lista_Quadrados_Ordenada *l, Item *i){
    if(lista_ordenada_cheia(l)) {
        return FALSO;
    }
    comparacao_ordenada++;
    int v;
    atribuicao_ordenada++;
    for (v = 0; v < lista_ordenada_tamanho(l); v++){
        if (lado_quadrado(l->dados[v]) < lado_quadrado(i)){
            comparacao_ordenada++;
            int j;
            atribuicao_ordenada++;
            for(j = lista_ordenada_tamanho(l); j >= v; j--) {
                comparacao_ordenada++;
                l->dados[j + 1] = l->dados[j];
                atribuicao_ordenada++;
            }
            break;
        }
    }
    l->dados[v] = i;
    atribuicao_ordenada++;
    l->qtde++;
    return VERDADEIRO;
}

// Realiza a busca binária na lista ordenada através do lado do quadrado
int lo_busca_binaria(Lista_Quadrados_Ordenada *l, float lado){
    atribuicao_ordenada++;
    comparacao_ordenada++;
    int inicio = 0;
    atribuicao_ordenada++;
    int fim = lista_ordenada_tamanho(l)-1;
    atribuicao_ordenada++;
    int meio;
        while (fim - inicio >= 0){
            comparacao_ordenada++;
            meio = (fim+inicio)/2;
            atribuicao_ordenada++;
            if (lado_quadrado(l->dados[meio]) == lado) {
                comparacao_ordenada++;
                return meio;
            }
            else if (lado_quadrado(l->dados[meio]) > lado) {
                fim = meio - 1;
                atribuicao_ordenada++;
            }
            else {
                inicio = meio + 1;
                atribuicao_ordenada++;
            }
        }
            return FLAG_ERRO;
}

int lo_busca_binaria_decrescente(Lista_Quadrados_Ordenada *l, float lado){
    atribuicao_ordenada++;
    comparacao_ordenada++;
    int inicio = 0;
    atribuicao_ordenada++;
    int fim = lista_ordenada_tamanho(l)-1;
    atribuicao_ordenada++;
    int meio;
    while (fim - inicio >= 0){
        comparacao_ordenada++;
        meio = (fim+inicio)/2;
        atribuicao_ordenada++;
        if (lado_quadrado(l->dados[meio]) == lado) {
            comparacao_ordenada++;
            return meio;
        }
        else if (lado_quadrado(l->dados[meio]) < lado) {
            fim = meio - 1;
            atribuicao_ordenada++;
        }
        else {
            inicio = meio + 1;
            atribuicao_ordenada++;
        }
    }
    return FLAG_ERRO;
}

// Esvazia a lista ordenada
void esvaziar_lista_ordenada(Lista_Quadrados_Ordenada *l){
    while (!lista_ordenada_vazia(l))
        remover_fim_lista_ordenada(l);
}

// Libera a lista ordenada
void liberar_lista_ordenada(Lista_Quadrados_Ordenada **l){
    esvaziar_lista_ordenada(*l);
    free(*l);
    *l = NULL;
}

// Atribui valor 0 para comparacoes e atribuicoes
void reset_ordenada (){
    atribuicao_ordenada = 0;
    comparacao_ordenada = 0;
}

// Imprime a quantidade de atribuicoes e comparacoes encontradas
// Funcao so pode ser usada depois de inserir ou de busca
void atribuicoes_comparacoes_ordenada(){
    printf("Quantidade de comparacoes: %d\n", comparacao_ordenada);
    printf("Quantidade de atribuicoes: %d\n", atribuicao_ordenada);
    reset_ordenada();
}

// Cria uma lista ordenada e organiza o conteudo de forma decrescente
void lista_ordenada_crescente(Lista_Quadrados_Ordenada *l){
    int i, chave = 1;
    float x = 0.0, y = 0.0, lado = 1.0;
    for(i = 0; i < N; i++){
        inserir_ordenado(l,criar_item(chave,x,y,lado));
        chave++;
        x++, y++, lado++;
    }
    atribuicoes_comparacoes_ordenada();
}

// Cria uma lista ordenada e organiza o conteudo de forma decrescente
void lista_ordenada_decrescente(Lista_Quadrados_Ordenada *l){
    int i, chave = 1;
    float x = 999.0, y = 999.0, lado = 1000.0;
    for(i = 0; i < N; i++){
        inserir_ordenado_decrescente(l,criar_item(chave,x,y,lado));
        chave++;
        x--, y--, lado--;
    }
    atribuicoes_comparacoes_ordenada();
}

// Cria uma lista ordenada e organiza o conteudo de forma aleatoria com base nos valores dos lados dos quadrados
void lista_ordenada_aleatoria(Lista_Quadrados_Ordenada *l, float arr[]){
    int i, chave = 1;
    float x = 0.0, y = 0.0, lado;
    for(i = 0; i < N; i++){
        lado = arr[i];
        inserir_ordenado(l, criar_item(chave,x,y,lado));
        chave++;
        x++, y++;
    }
    atribuicoes_comparacoes_ordenada();
}

// CEFET-MG Leopoldina, Engenharia de Computação
// Laboratório de Estrutura de Dados
// Profº: Henrique Barros Lopes
// Aluna: Bianca da Silva Pinto