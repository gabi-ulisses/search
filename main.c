#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

#define TOTAL_REGISTROS 1000000

int main() {
    int *vetor = (int *)malloc(TOTAL_REGISTROS * sizeof(int));

    // Aloca memória para as tabelas de índice
    TabelaIndice tabelas[3];
    int tamanho_bloco = TOTAL_REGISTROS / 3;

    for (int i = 0; i < 3; i++) {
        tabelas[i].tamanho_bloco = tamanho_bloco;
        tabelas[i].indices = (int *)malloc(tamanho_bloco * sizeof(int));

        if (tabelas[i].indices == NULL) {
            printf("Erro de alocação de memória para a tabela %d.\n", i + 1);
            return 1;
        }
    }

    if (vetor == NULL) {
        printf("Erro de alocação de memória para o vetor.\n");
        return 1;
    }

    gerarVetorAleatorioOrdenado(vetor, TOTAL_REGISTROS);
    criarTabelasDeIndice(vetor, tabelas, TOTAL_REGISTROS);

    FILE *arquivo = fopen("vetor.txt", "w");
    if (arquivo != NULL) {
        for (int i = 0; i < TOTAL_REGISTROS; i++) {
            fprintf(arquivo, "%d\n", vetor[i]);
        }
        fclose(arquivo);
        printf("Vetor salvo no arquivo vetor.txt com sucesso!\n");
    }

    char input[10];
    int valor;

    while (1) {
        printf("Digite o valor para buscar (ou 'S' para sair): ");
        fgets(input, sizeof(input), stdin);

        if (input[0] == 'S' || input[0] == 's') {
            break;
        }

        sscanf(input, "%d", &valor);

        int posicao = buscaSequencialIndexada(vetor, tabelas, valor, TOTAL_REGISTROS);

        if (posicao == -1) {
            printf("O valor %d não foi encontrado.\n", valor);
        } else {
            printf("O valor %d foi encontrado na posição %d.\n", valor, posicao);
        }
    }

    free(vetor);
    for (int i = 0; i < 3; i++) {
        free(tabelas[i].indices);
    }

    return 0;
}
