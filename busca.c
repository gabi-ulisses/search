#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "lib.h"

#define INTERVALO 10000000  // Define um intervalo maior para os números

int gerarVetorAleatorioOrdenado(int *vetor, int tamanho_vetor) {
    if (tamanho_vetor > INTERVALO) {
        return -1;  // Retorna -1 se o tamanho do vetor for maior que o intervalo
    }

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Usando um vetor para rastrear números únicos
    int *usados = malloc(INTERVALO * sizeof(int));
    if (usados == NULL) {
        return -1;  // Retorna -1 em caso de erro de alocação
    }

    // Inicializa o vetor de usados com zero
    for (int i = 0; i < INTERVALO; i++) {
        usados[i] = 0;
    }

    int count = 0;
    while (count < tamanho_vetor) {
        int numero = rand() % INTERVALO;

        // Verifica se o número já foi usado
        if (!usados[numero]) {
            usados[numero] = 1;  // Marca o número como usado
            vetor[count++] = numero;  // Adiciona ao vetor
        }
    }

    free(usados);

    // Ordena o vetor (usando a função mergeSort do projeto)
    mergeSort(vetor, 0, tamanho_vetor - 1);
    
    return 0;  // Retorna 0 em caso de sucesso
}

// Função Merge Sort para ordenar o vetor
void mergeSort(int *vetor, int esq, int dir) {
    if (esq < dir) {
        int meio = (esq + dir) / 2;
        mergeSort(vetor, esq, meio);        // Ordena a metade esquerda
        mergeSort(vetor, meio + 1, dir);   // Ordena a metade direita
        merge(vetor, esq, meio, dir);      // Junta as duas metades ordenadas
    }
}

// Função auxiliar para o Merge Sort
void merge(int *vetor, int esq, int meio, int dir) {
    int n1 = meio - esq + 1;
    int n2 = dir - meio;

    int *esq_temp = (int *)malloc(n1 * sizeof(int));
    int *dir_temp = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) esq_temp[i] = vetor[esq + i];
    for (int i = 0; i < n2; i++) dir_temp[i] = vetor[meio + 1 + i];

    int i = 0, j = 0, k = esq;
    while (i < n1 && j < n2) {
        if (esq_temp[i] <= dir_temp[j]) {
            vetor[k++] = esq_temp[i++];
        } else {
            vetor[k++] = dir_temp[j++];
        }
    }

    while (i < n1) vetor[k++] = esq_temp[i++];
    while (j < n2) vetor[k++] = dir_temp[j++];

    free(esq_temp);
    free(dir_temp);
}

void criarTabelasDeIndice(int *vetor, TabelaIndice *tabelas, int tamanho_vetor) {
    int tamanho_bloco = (tamanho_vetor + 2) / 3;  // Divide em 3 blocos igualmente

    for (int i = 0; i < 3; i++) {
        tabelas[i].indices[0] = i * tamanho_bloco;  // Índice inicial
        tabelas[i].indices[1] = (i + 1) * tamanho_bloco - 1 < tamanho_vetor 
                               ? (i + 1) * tamanho_bloco - 1 
                               : tamanho_vetor - 1;  // Índice final
    }
}

// Função de busca sequencial indexada
int buscaSequencialIndexada(int *vetor, TabelaIndice *tabelas, int valor, int tamanho_vetor) {
    for (int i = 0; i < 3; i++) {
        int inicio = tabelas[i].indices[0];
        int fim = tabelas[i].indices[1];

        if (valor >= vetor[inicio] && valor <= vetor[fim]) {
            for (int j = inicio; j <= fim; j++) {  // Busca dentro do bloco
                if (vetor[j] == valor) {
                    return j;  // Retorna a posição
                }
            }
        }
    }

    return -1;  // Valor não encontrado
}
