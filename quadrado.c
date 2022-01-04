// LEDA - Implementação de Biblioteca 1 - 31.10.2021
// LEDA - Implementação de Biblioteca 3 - 28.11.2021
// 28.11.2021 - Alterações no Struct Quadrado

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "quadrado.h"

int n = 1000;

struct quad {
    float x, y, l;
};

Quadrado* criar_quadrado (float x, float y, float l) {
    Quadrado *q = malloc(sizeof(Quadrado));
    if (q == NULL)
        return NULL;
    (*q).x = x;
    (*q).y = y;
    (*q).l = l;
    return q;
}

void liberar_quadrado (Quadrado **q) {
    free(*q);
    *q = NULL;
}

void exibir_quadrado (Quadrado *q) {
    printf("Quadrado: (%.2f, %.2f) com lado %.2f\n", (*q).x, (*q).y, (*q).l);
}

float get_lado (Quadrado *q){
    return (*q).l;
}

void vetorCrescente(float arr[], int n){
    int i;
    float a = 1.0;
    for(i = 0; i < n; i++){
        arr[i] = a;
        a++;
    }
}

void vetorDecrescente(float arr[], int n){
    int i;
    float a = 1000.0;
    for(i = 0; i < n; i++){
        arr[i] = a;
        a--;
    }
}

void swap(float *a, float *b){
    float temp = *a;
    *a = *b;
    *b = temp;
}

void randomize(float arr[], int n){
    srand (time(NULL));
    for(int i = n - 1; i > 0; i--){
        int j = rand() % (i + 1);
        swap(&arr[i], &arr[j]);
    }
}

void imprimirVetor(float arr[]){
    int i;
    for(i = 0; i < n; i++){
        printf("%.1f, \n", arr[i]);
    }
}

// CEFET-MG Leopoldina, Engenharia de Computação
// Laboratório de Estrutura de Dados
// Profº: Henrique Barros Lopes
// Aluna: Bianca da Silva Pinto