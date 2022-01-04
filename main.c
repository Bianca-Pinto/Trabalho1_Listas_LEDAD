#include <stdio.h>
#include "quadrado.h"
#include "lista_sequencial.h"
#include "lista_encadeada.h"
#include "lista_ordenada.h"

int main() {
    int n = 0;

    // Criacao de um vetor com valores de 1.0 a 1000
    float v[1000];
    vetorCrescente(v, 1000);
    // A funcao 'imprimirVetor' pode ser usada como teste
    //imprimirVetor(v);

    printf("\n======= LISTAS EM ORDEM CRESCENTE =======\n");
    printf("\nCriando as Listas...");
    Lista_Sequencial *ls = criar_lista_sequencial();
    Lista_Encadeada *le = criar_lista_encadeada();
    Lista_Quadrados_Ordenada *lo = criar_lista_quad_ordenada();

    // Os valores do vetor crescente são colocados nas listas
    printf("\nInserindo Itens na Lista Sequencial Crescente... \n");
    lista_sequencial_crescente(ls);
    printf("\nInserindo Itens na Lista Encadeada Crescente... \n");
    lista_encadeada_crescente(le);
    printf("\nInserindo Itens na Lista Ordenada Crescente... \n");
    lista_ordenada_crescente(lo);

    // Funcoes de teste (se usar vetores menores, precisa trocar em main e arquivos .c de lista)
    //printf("\nElementos nas Listas... \n");
    //exibir_lista(ls);
    //imprimir_lista_encadeada(le);
    //exibir_lista_ordenada(lq);

    printf("\n======= BUSCAS NAS LISTAS CRESCENTES =======\n");
    printf("\nRealizando Busca na Lista Sequencial Crescente...\n");
    printf("Elemento na posicao %d\n", buscar_elemento_seq(ls,1.0));
    atribuicoes_comparacoes_sequencial();
    printf("Elemento na posicao %d\n", buscar_elemento_seq(ls,1001.0));
    atribuicoes_comparacoes_sequencial();
    printf("Elemento na posicao %d\n", buscar_elemento_seq(ls,500.0));
    atribuicoes_comparacoes_sequencial();
    printf("Elemento na posicao %d\n", buscar_elemento_seq(ls,1000.0));
    atribuicoes_comparacoes_sequencial();

    printf("\nRealizando Busca na Lista Encadeada Crescente...\n");
    printf("Elemento na posicao %d\n", buscar_elemento_enc(le,1.0));
    atribuicoes_comparacoes_encadeada();
    printf("Elemento na posicao %d\n", buscar_elemento_enc(le,1001.0));
    atribuicoes_comparacoes_encadeada();
    printf("Elemento na posicao %d\n", buscar_elemento_enc(le,500.0));
    atribuicoes_comparacoes_encadeada();
    printf("Elemento na posicao %d\n", buscar_elemento_enc(le,1000.0));
    atribuicoes_comparacoes_encadeada();

    printf("\nRealizando Busca Binaria na Lista Ordenada Crescente...\n");
    printf("\nBusca pelo quadrado de lado 1\n");
    printf("Elemento na posicao %d\n", lo_busca_binaria(lo,1.0));
    while (n < 99){
        lo_busca_binaria(lo,1.0);
        n++;
    }
    n = 0;
    atribuicoes_comparacoes_ordenada();

    printf("\nBusca pelo quadrado de lado 1001\n");
    printf("Elemento na posicao %d\n", lo_busca_binaria(lo,1001.0));
    while (n < 99){
        lo_busca_binaria(lo,1001.0);
        n++;
    }
    n = 0;
    atribuicoes_comparacoes_ordenada();

    printf("\nBusca pelo quadrado de lado 500\n");
    printf("Elemento na posicao %d\n", lo_busca_binaria(lo,500.0));
    while (n < 99){
        lo_busca_binaria(lo,500.0);
        n++;
    }
    n = 0;
    atribuicoes_comparacoes_ordenada();

    printf("\nBusca pelo quadrado de lado 1000\n");
    printf("Elemento na posicao %d\n", lo_busca_binaria(lo,1000.0));
    while (n < 99){
        lo_busca_binaria(lo,1000.0);
        n++;
    }
    n = 0;
    atribuicoes_comparacoes_ordenada();

    printf("\nLiberando as Listas... \n");
    liberar_lista(&ls);
    liberar_lista_encadeada(&le);
    liberar_lista_ordenada(&lo);

    printf("\n======= LISTAS EM ORDEM DECRESCENTE =======\n");
    // Criacao de um vetor com 1000 elementos dispostos de forma decrescente
    float d[1000];
    vetorDecrescente(d,1000);

    printf("\nCriando as Listas...");
    Lista_Sequencial *lse = criar_lista_sequencial();
    Lista_Encadeada *len = criar_lista_encadeada();
    Lista_Quadrados_Ordenada *lor = criar_lista_quad_ordenada();

    // Os valores do vetor decrescente são colocados nas listas
    printf("\nInserindo Itens na Lista Sequencial Decrescente... \n");
    lista_sequencial_decrescente(lse);
    printf("\nInserindo Itens na Lista Encadeada Decrescente... \n");
    lista_encadeada_decrescente(len);
    printf("\nInserindo Itens na Lista Ordenada Decrescente... \n");
    lista_ordenada_decrescente(lor);

    //printf("\nElementos nas Listas... \n");
    //exibir_lista(lse);
    //imprimir_lista_encadeada(len);
    //exibir_lista_ordenada(lor);

    printf("\n======= BUSCAS NAS LISTAS DECRESCENTES =======\n");
    printf("\nRealizando Busca na Lista Sequencial Decrescente...\n");
    printf("\nBusca pelo quadrado de lado 1\n");
    printf("Elemento na posicao %d\n", buscar_elemento_seq(lse,1.0));
    atribuicoes_comparacoes_sequencial();
    printf("\nBusca pelo quadrado de lado 1001\n");
    printf("Elemento na posicao %d\n", buscar_elemento_seq(lse,1001.0));
    atribuicoes_comparacoes_sequencial();
    printf("\nBusca pelo quadrado de lado 500\n");
    printf("Elemento na posicao %d\n", buscar_elemento_seq(lse,500.0));
    atribuicoes_comparacoes_sequencial();
    printf("\nBusca pelo quadrado de lado 1000\n");
    printf("Elemento na posicao %d\n", buscar_elemento_seq(lse,1000.0));
    atribuicoes_comparacoes_sequencial();

    printf("\nRealizando Busca na Lista Encadeada Decrescente...\n");
    printf("\nBusca pelo quadrado de lado 1\n");
    printf("Elemento na posicao %d\n", buscar_elemento_enc(len,1.0));
    atribuicoes_comparacoes_encadeada();
    printf("\nBusca pelo quadrado de lado 1001\n");
    printf("Elemento na posicao %d\n", buscar_elemento_enc(len,1001.0));
    atribuicoes_comparacoes_encadeada();
    printf("\nBusca pelo quadrado de lado 500\n");
    printf("Elemento na posicao %d\n", buscar_elemento_enc(len,500.0));
    atribuicoes_comparacoes_encadeada();
    printf("\nBusca pelo quadrado de lado 1000\n");
    printf("Elemento na posicao %d\n", buscar_elemento_enc(len,1000.0));
    atribuicoes_comparacoes_encadeada();

    printf("\nRealizando Busca Binaria na Lista Ordenada Decrescente...\n");
    printf("\nBusca pelo quadrado de lado 1\n");
    printf("Elemento na posicao %d\n", lo_busca_binaria_decrescente(lor,1.0));
    while (n < 99){
        lo_busca_binaria(lor,1.0);
        n++;
    }
    n = 0;
    atribuicoes_comparacoes_ordenada();

    printf("\nBusca pelo quadrado de lado 1001\n");
    printf("Elemento na posicao %d\n", lo_busca_binaria_decrescente(lor,1001.0));
    while (n < 99){
        lo_busca_binaria(lor,1001.0);
        n++;
    }
    n = 0;
    atribuicoes_comparacoes_ordenada();

    printf("\nBusca pelo quadrado de lado 500\n");
    printf("Elemento na posicao %d\n", lo_busca_binaria_decrescente(lor,500.0));
    while (n < 99){
        lo_busca_binaria(lor,500.0);
        n++;
    }
    n = 0;
    atribuicoes_comparacoes_ordenada();

    printf("\nBusca pelo quadrado de lado 1000\n");
    printf("Elemento na posicao %d\n", lo_busca_binaria_decrescente(lor,1000.0));
    while (n < 99){
        lo_busca_binaria(lor,1000.0);
        n++;
    }
    n = 0;
    atribuicoes_comparacoes_ordenada();

    printf("\nLiberando as Listas... \n");
    liberar_lista(&lse);
    liberar_lista_encadeada(&len);
    liberar_lista_ordenada(&lor);

    printf("\n======= LISTAS EM ORDEM ALEATORIA =======\n");

    printf("\nCriando as Listas...");
    Lista_Sequencial *lseq = criar_lista_sequencial();
    Lista_Encadeada *lenc = criar_lista_encadeada();
    Lista_Quadrados_Ordenada *lord = criar_lista_quad_ordenada();

    // A funcao 'randomize' aleatoriza os elementos do vetor crescente criado anteriormente

    // Os valores do vetor aleatorio são colocados nas listas
    printf("\nInserindo Itens na Lista Sequencial Aleatoria... \n");
    randomize(v,1000);
    lista_sequencial_aleatoria(lseq,v);
    printf("\nInserindo Itens na Lista Encadeada Aleatoria... \n");
    //randomize(v,1000);
    lista_encadeada_aleatoria(lenc,v);
    printf("\nInserindo Itens na Lista Ordenada Aleatoria... \n");
    //randomize(v,1000);
    lista_ordenada_aleatoria(lord,v);

    //printf("\nElementos nas Listas... \n");
    //exibir_lista(lseq);
    //imprimir_lista_encadeada(lenc);
    //exibir_lista_ordenada(lor);

    printf("\n======= BUSCAS NAS LISTAS ALEATORIAS =======\n");
    printf("\nRealizando Busca na Lista Sequencial Aleatoria...\n");
    printf("\nBusca pelo quadrado de lado 1\n");
    printf("Elemento na posicao %d\n", buscar_elemento_seq(lseq,1.0));
    atribuicoes_comparacoes_sequencial();
    printf("\nBusca pelo quadrado de lado 1001\n");
    printf("Elemento na posicao %d\n", buscar_elemento_seq(lseq,1001.0));
    atribuicoes_comparacoes_sequencial();
    printf("\nBusca pelo quadrado de lado 500\n");
    printf("Elemento na posicao %d\n", buscar_elemento_seq(lseq,500.0));
    atribuicoes_comparacoes_sequencial();
    printf("\nBusca pelo quadrado de lado 1000\n");
    printf("Elemento na posicao %d\n", buscar_elemento_seq(lseq,1000.0));
    atribuicoes_comparacoes_sequencial();

    printf("\nRealizando Busca na Lista Encadeada Aleatoria...\n");
    printf("\nBusca pelo quadrado de lado 1\n");
    printf("Elemento na posicao %d\n", buscar_elemento_enc(lenc,1.0));
    atribuicoes_comparacoes_encadeada();
    printf("\nBusca pelo quadrado de lado 1001\n");
    printf("Elemento na posicao %d\n", buscar_elemento_enc(lenc,1001.0));
    atribuicoes_comparacoes_encadeada();
    printf("\nBusca pelo quadrado de lado 500\n");
    printf("Elemento na posicao %d\n", buscar_elemento_enc(lenc,500.0));
    atribuicoes_comparacoes_encadeada();
    printf("\nBusca pelo quadrado de lado 1000\n");
    printf("Elemento na posicao %d\n", buscar_elemento_enc(lenc,1000.0));
    atribuicoes_comparacoes_encadeada();

    printf("\nRealizando Busca Binaria na Lista Ordenada Aleatoria...\n");
    printf("\nBusca pelo quadrado de lado 1\n");
    printf("Elemento na posicao %d\n", lo_busca_binaria(lord,1.0));
    while (n < 99){
        lo_busca_binaria(lord,1.0);
        n++;
    }
    n = 0;
    atribuicoes_comparacoes_ordenada();

    printf("\nBusca pelo quadrado de lado 1001\n");
    printf("Elemento na posicao %d\n", lo_busca_binaria(lord,1001.0));
    while (n < 99){
        lo_busca_binaria(lord,1001.0);
        n++;
    }
    n = 0;
    atribuicoes_comparacoes_ordenada();

    printf("\nBusca pelo quadrado de lado 500\n");
    printf("Elemento na posicao %d\n", lo_busca_binaria(lord,500.0));
    while (n < 99){
        lo_busca_binaria(lord,500.0);
        n++;
    }
    n = 0;
    atribuicoes_comparacoes_ordenada();

    printf("\nBusca pelo quadrado de lado 1000\n");
    printf("Elemento na posicao %d\n", lo_busca_binaria(lord,1000.0));
    while (n < 99){
        lo_busca_binaria(lord,1000.0);
        n++;
    }
    n = 0;
    atribuicoes_comparacoes_ordenada();

    printf("\nLiberando as Listas... \n");
    liberar_lista(&lseq);
    liberar_lista_encadeada(&lenc);
    liberar_lista_ordenada(&lord);

    return 0;
}
