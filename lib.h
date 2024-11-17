#ifndef LIB_H
#define LIB_H

// Estrutura para armazenar os índices de cada bloco
typedef struct {
    int *indices;           // Array de índices para o bloco
    int tamanho_bloco;      // Tamanho do bloco
} TabelaIndice;

// Função para gerar um vetor aleatório ordenado
int gerarVetorAleatorioOrdenado(int *vetor, int tamanho_vetor);

// Função para ordenar o vetor usando Merge Sort
void mergeSort(int *vetor, int esq, int dir);

// Função para juntar as metades do vetor (Merge)
void merge(int *vetor, int esq, int meio, int dir);

// Função para criar as tabelas de índice
void criarTabelasDeIndice(int *vetor, TabelaIndice *tabelas, int tamanho_vetor);

// Função para realizar a busca sequencial indexada
int buscaSequencialIndexada(int *vetor, TabelaIndice *tabelas, int valor, int tamanho_vetor);

#endif 
