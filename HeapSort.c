#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double time1, timedif;

void criaHeap(int *vet, int i, int f)
{
    int AU = vet[i];
    int j = i * 2 + 1;
    while (j <= f)
    {
        if (j < f)
        {
            if (vet[j] < vet[j + 1])
            {
                j = j + 1;
            }
        }
        if (AU < vet[j])
        {
            vet[i] = vet[j];
            i = j;
            j = 2 * i + 1;
        }
        else
        {
            j = f + 1;
        }
    }
    vet[i] = AU;
}

void heapSort(int *vet, int N)
{
    int x, AU;
    for (x = (N - 1) / 2; x >= 0; x--)
    {
        criaHeap(vet, x, N - 1);
    }
    for (x = N - 1; x >= 1; x--)
    {
        AU = vet[0];
        vet[0] = vet[x];
        vet[x] = AU;
        criaHeap(vet, 0, x - 1);
    }

}

int main(void)
        {
            int i, tDados;
            printf("Entre com a quantidade de dados:");
            scanf("%d",&tDados);
            int *array=(int*)malloc(tDados*sizeof(int));
            srand(time(NULL));
                for (i = 0; i < tDados; i++)
                {
                    array[i]=rand()%100;
                }
                time1 = (double)clock();
                time1 = time1 / CLOCKS_PER_SEC;
                heapSort(array, tDados); //Função
                timedif = (((double)clock()) / CLOCKS_PER_SEC) - time1;
                printf("\nTempo da Ordenação: %.3fs\n--------------------------\n",timedif);
            return 0;
        }
