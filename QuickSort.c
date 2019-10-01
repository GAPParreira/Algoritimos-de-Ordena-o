#include <stdio.h>
#include <stdlib.h>
#include <time.h>
long cont=0;
double time1, timedif;
void quick_sort( int arr[1000000],int tam )
  {

    time1 = (double) clock();
    time1 = time1 / CLOCKS_PER_SEC;
		int i, j, aux;
		for (i = 1; i < tam; i++) {
			aux = arr[i];
			j = i - 1;
			while ((j >= 0) && (aux < arr[j])) {
				arr[j + 1] = arr[j];
				j--;
				cont++;
			}
			arr[j + 1] = aux;
		}
timedif = ( ((double) clock()) / CLOCKS_PER_SEC) - time1;
  }


void main(){
    int a,tDados,i;
    printf("Entre com a quantidade de dados:");
    scanf("%d",&tDados);
    int numeros[100000];
    for(a=0;a<tDados;a++){
        numeros[a] = rand();
    }
    quick_sort (numeros,tDados);//função

printf("--------------------------\nTempo da Ordenação: %.3fs\n--------------------------\nNumero de trocas: %lu\n--------------------------\n", timedif,cont);

}
