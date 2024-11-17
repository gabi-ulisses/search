# Sistema de Operação de Busca

Este projeto implementa um sistema de `operação de busca` em um vetor de `1 milhão de registros`. Os números do vetor são aleatórios, únicos e não sequenciais. O vetor é ordenado utilizando o método de ordenação Merge Sort, e o sistema utiliza a técnica de **busca sequencial indexada** para localizar elementos de maneira eficiente.

A busca sequencial indexada combina tabelas de índice com uma busca sequencial dentro de blocos menores do vetor, otimizando o número de comparações necessárias.

## Estrutura do Projeto

O projeto é composto pelos seguintes arquivos:

- **main.c**: Contém a lógica principal do programa, incluindo a geração do vetor, salvamento no arquivo `vetor.txt` e o fluxo principal da busca.
- **busca.c**: Implementa a lógica da **busca sequencial indexada** e as funções auxiliares necessárias.
- **lib.h**: Define as estruturas de dados, incluindo a tabela de índices, e declara as funções utilizadas no projeto.
- **Makefile**: Facilita a compilação do projeto.

## Funcionalidades

- Geração de um vetor de números aleatórios únicos.
- Salvamento do vetor gerado em um arquivo `vetor.txt` para validação.
- Ordenação do vetor utilizando o algoritmo Merge Sort.
- Criação de tabelas de índice para otimizar a busca.
- Realização de busca sequencial indexada.

## Busca Sequencial Indexada

A **busca sequencial indexada** combina a eficiência da indexação com a simplicidade da busca sequencial. Essa técnica divide o vetor em blocos menores, armazenando os intervalos e posições de cada bloco em uma tabela de índices. Isso permite localizar o bloco correto antes de realizar a busca sequencial.

### Funcionamento:

1. **Divisão em Blocos**: 
   - O vetor é dividido em blocos menores, e cada bloco possui um intervalo de valores (`valorInicio` e `valorFim`) e as posições correspondentes (`posInicio` e `posFim`) no vetor.

2. **Verificação de Intervalo**:
   - Durante a busca, a tabela de índices é usada para identificar o bloco onde o valor pode estar, reduzindo o número de elementos a serem verificados.

3. **Busca Sequencial no Bloco**:
   - Após identificar o bloco correto, uma busca sequencial é realizada apenas nesse bloco, localizando o número de forma eficiente.

Essa abordagem é eficiente para vetores grandes, pois limita a busca a uma porção menor do vetor.

## Compilação

Para compilar o projeto, utilize o Makefile incluído. Execute o seguinte comando no terminal:

```bash
make
```

Isso irá compilar os arquivos `main.c` e `busca.c`, gerando um executável.

## Execução

Após a compilação, execute o programa com:

```bash
./nome_do_executavel
```

Substitua `nome_do_executavel` pelo nome do arquivo gerado pelo Makefile.

## Como Usar

1. O programa gera um vetor de números aleatórios e salva em um arquivo chamado `vetor.txt`.
   - Este arquivo é usado apenas para validação e testes, mas a busca é realizada diretamente no vetor em memória.

2. Ao executar o programa, você pode buscar por um número digitando-o quando solicitado.
   - Para sair, digite 'S'.

3. O programa informará se o número foi encontrado e, caso positivo, a posição onde ele se encontra no vetor.

## Sugestões de Melhoria

- Implementar múltiplos índices para diferentes intervalos de busca, dividindo o vetor em faixas menores, o que pode melhorar a eficiência.
- Adicionar suporte a uma busca binária dentro dos blocos, reduzindo ainda mais o tempo de busca.
- Desenvolver uma interface gráfica para facilitar a interação do usuário.