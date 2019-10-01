#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

void Insercao_sort(int *vet, int n);

main(){
    int n=100000,vet[n];
    for(int i=0;i<n;i++)
    {
        vet[i]=rand()%n;
    }
    Insercao_sort(vet,n);
}

void Insercao_sort(int *vet, int n){
    int i,j,aux, cont=0;
    double time,timef;
    time = (double) clock();
    time = time/CLOCKS_PER_SEC;
    for(i=1;i<n;i++)
    {
        aux = vet[i];
        for(j=i;(j>0)&&(aux<vet[j-1]);j--)
        {
            vet[j]=vet[j-1];
            cont++;
        }
        vet[j]=aux;
    }
    timef = (((double)clock())/CLOCKS_PER_SEC)-time;
    printf("Tempo gasto %f\n",timef);
    printf("Numero de trocas %lu\n",cont);
}
