#include <stdio.h>
#include <stdlib.h> // necessário p/ as funções rand() e srand()
#include <time.h>   //necessário p/ função time()
#include <locale.h> //só pra corrigir o idioma (usar acentos e etc)

#define TAM 5000

void gerarDados(int vetor[]);
void printDados(int vetor[]);
void bubbleSortLow(int vetor[], int n);
void bubbleSort(int vetor[], int n);
void selectionSort(int vet[], int tam);

int main(void)
{
    setlocale(LC_ALL, "");

    int m[TAM];
    gerarDados(m);

    clock_t t_inicio, t_fim;

    float tempo_B;
    float tempo_BL;
    float tempo_S;

    int n = m;
    t_inicio = clock();
    bubbleSortLow(n, TAM);
    t_fim = clock();
    tempo_BL = (difftime(t_fim, t_inicio));
    printDados(n);

    n = m;
    t_inicio = clock();
    bubbleSort(n, TAM);
    t_fim = clock();
    tempo_B = (difftime(t_fim, t_inicio));
    printDados(n);
    
    n = m;
    t_inicio = clock();
    selectionSort(n, TAM);
    t_fim = clock();
    tempo_S = (difftime(t_fim, t_inicio));
    printDados(n);

    printf("\nRELATORIO:\n");
    printf("\nTempo de ordenação com bubbleSort Simples: %f ms", tempo_BL);
    printf("\nTempo de ordenação com bubbleSort Otimizada: %f ms", tempo_B);
    printf("\nTempo de ordenação com selectionSort: %f ms", tempo_S);

    return 0;
}

void printDados(int vetor[])
{
    int i, j, c = 0;
    printf("\n\nExibindo Dados: \n");

    for (j = 0; j < TAM; j++)
    {
        printf(" [%4d]", vetor[c]);
        c++;

        if ((j + 1) % 10 == 0)
            printf("\n");
    }
    printf("\nquantidade de dados: %d\n", c);
}

void gerarDados(int vetor[])
{
    int i;
    srand(time(NULL));

    for (i = 0; i < TAM; i++)
    {
        // gerando valores aleatórios na faixa de 0 a 9999
        vetor[i] = rand() % 9999;
    }
    printf("\n>> Dados gerados:\n\n");
    printDados(vetor);
}

void bubbleSortLow(int vetor[], int n)
{
    int k, j, aux;

    for (k = 1; k < n; k++)
    {
        printf("\n[%d] ", k);

        for (j = 0; j < n - 1; j++)
        {
            printf("%d, ", j);

            if (vetor[j] > vetor[j + 1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

void bubbleSort(int vetor[], int n)
{
    int k, j, aux;

    for (k = n - 1; k > 0; k--)
    {
        printf("\n[%d] ", k);

        for (j = 0; j < k; j++)
        {
            printf("%d, ", j);

            if (vetor[j] > vetor[j + 1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

void selectionSort(int v[], int n)
{
    printf("\n\nOrdenação por Seleção:\n\n");
    int i, j, menor, aux, count = 0;

    for (i = 0; i < (n - 1); i++)
    {
        menor = i;
        for (j = (i + 1); j < n; j++)
        {
            if (v[j] < v[menor])
                menor = j;
        }
        if (v[i] != v[menor])
        {
            aux = v[i];
            v[i] = v[menor];
            v[menor] = aux;
        }
        count++;
    }

    //imprime_dados(v);
}