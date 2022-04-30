#include <stdlib.h>
#include <stdio.h>

int *array, size;
int qtdeOpForca = 0;
int qtdeOpMelhor = 0;

void printArray(int *array, int size);
void triplasForcaBruta(int *array, int size);
void triplasMelhorado();
void mergeSort(int A[], int n, int p, int r);
int buscaBinariaRecursiva(int A[], int inicio, int fim, int x);

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

    printf("\n---3SUM - Melhorado:---\n\n");

    triplasMelhorado(array, size);

    printf("Quantidade de Operacoes - 3SUM - Forca Bruta: %d\n", qtdeOpForca);
    printf("Quantidade de Operacoes - 3SUM - Melhorado: %d", qtdeOpMelhor);

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
                qtdeOpForca++;
            }
        }
    }

    printf("Total Triplas Encontradas pela Forca Bruta: %d\n\n", totalTriplas);

}

void triplasMelhorado(int *array, int size){
    mergeSort(array, size, 0, size - 1);

    printf("Array Ord.   [] = ");
    printArray(array, size);

    int soma;
    int terceiroIndice;
    int totalTriplas = 0;
    
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            soma = array[i] + array[j];
            terceiroIndice = buscaBinariaRecursiva(array, (j+1), size - 1, -soma);
            if (terceiroIndice != -1 && terceiroIndice != i && terceiroIndice != j) {
                totalTriplas += 1;
                printf("%d Tripla Encontrada: [%d, %d, %d]\n", totalTriplas, array[i], array[j], array[terceiroIndice]);
            } 
            qtdeOpMelhor++;
        }
    }

}

int buscaBinariaRecursiva(int *array, int inicio, int fim, int x) {
    int meio = (inicio + fim) / 2;

    //qtdeOpMelhor++;   ----->  Essa comparação não deveria aumentar o número de operações?
    if (array[meio] == x)
        return meio;
    //qtdeOpMelhor++;   ----->  E essa comparação tambémm, não?
    if (inicio >= fim) {
        return -1;
    } else {
        qtdeOpMelhor++; 
        if (array[meio] < x) {
            return buscaBinariaRecursiva(array, meio + 1, fim, x);
        } else {
            return buscaBinariaRecursiva(array, inicio, meio - 1, x);
        }
    }
}

void mergeSort(int *array, int n, int p, int r) {
    if (p < r) {
        int q = (p + r)/2;
        mergeSort(array, n, p, q );
        mergeSort(array, n, q+1, r);
        intercala(array, n, p, q, r);
    }
}

void intercala(int *A, int n, int p, int q, int r) {
    int i, j;
    int *B;
    B = (int*) malloc(n * sizeof(int));
    for (i = p; i <= q; i++) {
        B[i] = A[i];
    }
    for (j = q + 1; j <= r; j++) {
        B[r + q + 1 - j] = A[j];
    }

    i = p;
    j = r;

    for (int k = p; k <= r; k++) {
        if (B[i] <= B[j]) {
            A[k] = B[i];
            i++;
        } else {
            A[k] = B[j];
            j--;
        }
    }
}