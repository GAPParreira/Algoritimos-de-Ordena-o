#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

double time1, timef;
double conta[30];

void Bubble_sort(int *vet, int n);

main(){
    int z;
    int a,tDados,i;
    printf("Entre com a quantidade de dados:");
    scanf("%d",&tDados);
    int *vet=(int*)malloc(tDados*sizeof(int));
    srand(time(NULL));
    for(int i=0;i<tDados;i++)
    {
        vet[i]=rand();
    }
    Bubble_sort(vet,tDados);
}

void Bubble_sort(int *vet, int n){
    int continuar, aux;long cont=0;

   time1 = (double) clock();
    time1 = time1 / CLOCKS_PER_SEC;
    for(int j=0;j<n;j++)
    {
        for(int i=0; i<n-1-i; i++)
        {
            if(vet[i]>vet[i+1])
            {
                aux=vet[i];
                vet[i]=vet[i+1];
                vet[i+1]=aux;
                continuar=i;
                cont++;
            }
        }
    }
    timef = (((double)clock())/CLOCKS_PER_SEC)-time1;
    printf("Tempo gasto %f\n",timef);
    printf("Numero de trocas %d\n",cont);
}
