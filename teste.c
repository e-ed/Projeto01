#include <stdlib.h>
#include <stdio.h>

int *array, size;

void printArray(int *array, int size);
void triplasForcaBruta(int *array, int size);
void triplasMelhorado();

int main() {

    printf("---Projeto 01 - 3SUM---\n\n");

    //Objetivo: Encontrar quantas triplas únicas do array A que se obtém a soma igual a Zero!

    printf("Definir o tamanho do array: ");
    scanf(" %d", &size);

    array = (int*)malloc(size * (sizeof(int)));

    for(int i = 0; i < size; i++){
        printf("Entre com o %d elemento do array: ", i+1);
        scanf("%d", &array[i]);
    }

    printf("Array informado[] = ");
    printArray(array, size);

    printf("\n---3SUM - Forca bruta:---\n\n");

    triplasForcaBruta(array, size);

    return 0;
}

void printArray(int *array, int size){
    
    for(int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");

}

void triplasForcaBruta(int *array, int size){

    int tripla[3];
    int totalTriplas = 0;
    int i;
    int j;
    int k;

    for(i = 0; i < size; i++){

        for(k = (i + 2); k < size; k++){
            for(j = (i + 1); j < k; j++){
                if(array[i] + (array[j] + array[k]) == 0){
                    totalTriplas += 1;
                    printf("%d Tripla Encontrada: [%d, %d, %d]\n", totalTriplas, array[i], array[j], array[k]);
                }
            }
        }
    /*
        do{
            if(array[i] + (array[j] + array[k]) == 0){
                totalTriplas += 1;
                printf("%d Tripla Encontrada: [%d, %d, %d]\n", totalTriplas, array[i], array[j], array[k]);
            }
            j++;
            k++;
        }while(k < size-1);
    */
    }

}

void triplasMelhorado(){



}