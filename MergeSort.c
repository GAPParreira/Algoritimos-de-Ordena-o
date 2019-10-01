#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

void Merge_sort(int *vet,int ini,int fim,int *cont);
void Merge(int *vet,int ini,int meio,int fim,int *cont);

main(){
    int n=30000,vet[n],cont=0;
    double time,timef;
    time = (double) clock();
    time = time/CLOCKS_PER_SEC;
    for(int i=0;i<n;i++)
    {
        vet[i]=rand()%n;
    }
    Merge_sort(vet,0,n,&cont);
    timef = (((double)clock())/CLOCKS_PER_SEC)-time;
    for(int i=0;i<n;i++)
    {
        printf("%d\n",vet[i]);
    }
    printf("Tempo gasto %f\n",timef);
    printf("Numero de trocas %d\n",cont);
}

void Merge_sort(int *vet, int ini,int fim,int *cont){
    int meio;
    if(ini<fim)
    {
        meio = floor((ini+fim)/2);
        Merge_sort(vet,ini,meio,&cont);
        Merge_sort(vet,meio+1,fim,&cont);
        Merge(vet,ini,meio,fim,&cont);
    }
}

void Merge(int *vet,int ini,int meio,int fim,int *cont){
    int *Atemp,ini2,meio2,tamanho,i,j,k;
    int fim1=0, fim2=0;
    tamanho=fim-ini+1;
    ini2=ini;
    meio2=meio+1;
    Atemp = (int *)malloc(tamanho*sizeof(int));
    if(Atemp!=NULL)
    {
        for(i=0;i<tamanho;i++)
        {
            if(!fim1 && !fim2)
            {
                if(vet[ini2]<vet[meio2])
                    Atemp[i]=vet[ini2++];
                else
                    Atemp[i]=vet[meio2++];
                if(ini2>meio)
                    fim1=1;
                if(meio2>fim)
                    fim2=1;
            }
            else
            {
                if(!fim1)
                    Atemp[i]=vet[ini2++];
                else
                    Atemp[i]=vet[meio2++];
            }
            cont++;
        }
        for(j=0;j<tamanho;j++)
            vet[j]=Atemp[j];
    }
    free(Atemp);
}
