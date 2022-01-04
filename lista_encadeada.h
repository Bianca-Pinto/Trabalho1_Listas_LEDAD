// LEDA - 11.11.2021, 18.11.2021
// LEDA - Implementação de Biblioteca 3 - 28.11.2021

#ifndef TRABALHO1_LEDAD_LISTA_ENCADEADA_H
#define TRABALHO1_LEDAD_LISTA_ENCADEADA_H

#include "item.h"

typedef struct celula Celula;
typedef struct lista_encadeada Lista_Encadeada;

Lista_Encadeada * criar_lista_encadeada();
int lista_encadeada_vazia(Lista_Encadeada *l);
void imprimir_lista_encadeada(Lista_Encadeada *l);
int inserir_fim_encadeada(Lista_Encadeada *l, Item *i);
int remover_fim_encadeada(Lista_Encadeada *l, Item *i);
void liberar_lista_encadeada(Lista_Encadeada **l);
void liberar_celula_le(Celula **c);
int buscar_elemento_enc(Lista_Encadeada *l, float lado);
void reset_encadeada ();
void atribuicoes_comparacoes_encadeada();
void lista_encadeada_crescente(Lista_Encadeada *l);
void lista_encadeada_decrescente(Lista_Encadeada *l);
void lista_encadeada_aleatoria(Lista_Encadeada *l, float arr[]);

#endif //TRABALHO1_LEDAD_LISTA_ENCADEADA_H

// CEFET-MG Leopoldina, Engenharia de Computação
// Laboratório de Estrutura de Dados
// Profº: Henrique Barros Lopes
// Aluna: Bianca da Silva Pinto
