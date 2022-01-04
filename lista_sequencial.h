// LEDA - 28.10.2021, 04.11.2021

#ifndef TRABALHO1_LEDAD_LISTA_SEQUENCIAL_H
#define TRABALHO1_LEDAD_LISTA_SEQUENCIAL_H

#include "item.h"

typedef struct lista_sequencial Lista_Sequencial;

Lista_Sequencial* criar_lista_sequencial();
int lista_cheia(Lista_Sequencial *l);
int lista_vazia(Lista_Sequencial *l);
int lista_tamanho(Lista_Sequencial *l);
int inserir_fim_lista(Lista_Sequencial *l, Item *i);
int remover_fim_lista(Lista_Sequencial *l);
void exibir_lista(Lista_Sequencial *l);
void esvaziar_lista(Lista_Sequencial *l);
void liberar_lista(Lista_Sequencial **l);
int buscar_elemento_seq(Lista_Sequencial *l, float lado);
void reset_sequencial ();
void atribuicoes_comparacoes_sequencial();
void lista_sequencial_crescente(Lista_Sequencial *l);
void lista_sequencial_decrescente(Lista_Sequencial *l);
void lista_sequencial_aleatoria(Lista_Sequencial *l, float arr[]);


#endif //TRABALHO1_LEDAD_LISTA_SEQUENCIAL_H

// CEFET-MG Leopoldina, Engenharia de Computação
// Laboratório de Estrutura de Dados
// Profº: Henrique Barros Lopes
// Aluna: Bianca da Silva Pinto
