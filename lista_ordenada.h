// LEDA - Implementação de Biblioteca 4 - 12.12.2021
// Biblioteca implementada a partir da aula sincrona de LEDA do dia 25.11.2021 e da Biblioteca 2 - Lista Sequencial


#ifndef TRABALHO1_LEDAD_LISTA_ORDENADA_H
#define TRABALHO1_LEDAD_LISTA_ORDENADA_H

#include "item.h"

typedef struct lista_quadrados_ordenada Lista_Quadrados_Ordenada;

Lista_Quadrados_Ordenada *criar_lista_quad_ordenada();
int lista_ordenada_cheia(Lista_Quadrados_Ordenada *l);
int lista_ordenada_vazia(Lista_Quadrados_Ordenada *l);
int lista_ordenada_tamanho(Lista_Quadrados_Ordenada* l);
int inserir_ordenado(Lista_Quadrados_Ordenada *l, Item *i);
int inserir_ordenado_decrescente(Lista_Quadrados_Ordenada *l, Item *i);
int remover_fim_lista_ordenada(Lista_Quadrados_Ordenada *l);
void exibir_lista_ordenada(Lista_Quadrados_Ordenada *l);
void liberar_lista_ordenada(Lista_Quadrados_Ordenada **l);
void esvaziar_lista_ordenada(Lista_Quadrados_Ordenada *l);
int lo_busca_binaria(Lista_Quadrados_Ordenada *l, float lado);
int lo_busca_binaria_decrescente(Lista_Quadrados_Ordenada *l, float lado);
void lista_ordenada_crescente(Lista_Quadrados_Ordenada *l);
void lista_ordenada_decrescente(Lista_Quadrados_Ordenada *l);
void lista_ordenada_aleatoria(Lista_Quadrados_Ordenada *l, float arr[]);
void reset_ordenada();
void atribuicoes_comparacoes_ordenada();

#endif //TRABALHO1_LEDAD_LISTA_ORDENADA_H

// CEFET-MG Leopoldina, Engenharia de Computação
// Laboratório de Estrutura de Dados
// Profº: Henrique Barros Lopes
// Aluna: Bianca da Silva Pinto