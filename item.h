// LEDA - Implementação de Biblioteca 4 - 12.12.2021
// Inclui alterações realizadas na Implementação de Biblioteca 3

#ifndef TRABALHO1_LEDAD_ITEM_H
#define TRABALHO1_LEDAD_ITEM_H

#include "quadrado.h"

typedef struct item Item;

Item *criar_item(unsigned int c, float x, float y, float l);
void liberar_item(Item **i);
void imprimir_item(Item *i);
int buscar_item(Item *i, int v);
unsigned int get_chave(Item *i);
float lado_quadrado (Item *i);
float buscar_lado(Item *i, float l);

#endif //TRABALHO1_LEDAD_ITEM_H

// CEFET-MG Leopoldina, Engenharia de Computação
// Laboratório de Estrutura de Dados
// Profº: Henrique Barros Lopes
// Aluna: Bianca da Silva Pinto