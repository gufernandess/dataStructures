#include<stdio.h>

/*
A função swap recebe dois parâmetros e troca seus valores. 
Serve para trocar os valores do array de posição caso
necessário.

Vale ressaltar o uso de ponteiros para receber os elementos
como parâmetro, somente dessa forma é possível modificar
seus valores corretamente.
*/

void swap(int* firstElement, int* secondElement) {
    int aux = *secondElement;
    *secondElement = *firstElement;
    *firstElement = aux;
}

void printArray(int array[], int size) {
    printf("[");
    for(int i = 0; i < size; i++) {
        printf("%d,", array[i]);
    }
    printf("]");
}

/*
Aqui temos a função de ordenação em bolha, que irá comparar
determinado elemento com seu sucessor e trocá-lo caso seja
necessário, assim sendo até que o vetor se encontre 
devidamente ordenado.

O algoritmo compara o primeiro elemento do array (0) com
seu sucessor (1), incrementa o indicie e compara dessa
vez o elemento 1 com 2, e assim por diante.
*/

void bubbleSort(int array[], int size) {
    int i = 0, j = 0, k = 1;
    
    while(i < size) {
        for(j = 0; j < size - k; j++) {
            if(array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
        
        i++;
        k++;
    }
    
    printArray(array, size);
}

int main() {
    int array[] = {7, 3, 9, 4, 1};
    
    int size = sizeof(array) / sizeof(array[0]);
    
    printf("Array digitado: \n");
    printArray(array, size);
    
    printf("\n\nArray ordenado: \n");
    bubbleSort(array, size);

    return 0;
}