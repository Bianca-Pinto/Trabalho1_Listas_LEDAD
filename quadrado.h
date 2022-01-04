// LEDA - Implementação de Biblioteca 1 - 31.10.2021

#ifndef TRABALHO1_LEDAD_QUADRADO_H
#define TRABALHO1_LEDAD_QUADRADO_H

typedef struct quad Quadrado;
Quadrado* criar_quadrado (float x, float y, float l);
void liberar_quadrado (Quadrado **q);
void exibir_quadrado (Quadrado *q);
float get_lado (Quadrado *q);
void vetorCrescente(float arr[], int n);
void vetorDecrescente(float arr[], int n);
void swap(float *a, float *b);
void randomize(float arr[], int n);
void imprimirVetor(float arr[]);

#endif //TRABALHO1_LEDAD_QUADRADO_H

// CEFET-MG Leopoldina, Engenharia de Computação
// Laboratório de Estrutura de Dados
// Profº: Henrique Barros Lopes
// Aluna: Bianca da Silva Pinto
