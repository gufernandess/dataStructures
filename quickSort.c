#include<stdio.h>

// Função para trocar o valor de duas variáveis

void swap(int* firstValue, int* secondValue) {
    int aux = *firstValue;
    *firstValue = *secondValue;
    *secondValue = aux;
}

// Função para imprimir o array

void printArray(int array[], int size) {
    printf("[");
    for(int i = 0; i < size; i++) {
        printf("%d,", array[i]);
    }
    printf("]");
}

/* A função 'partition' organiza o array de forma que os elementos menores
que o pivô fiquem a sua esquerda, e os maiores a sua direita, retornando o
índice final do pivô para realizar o processo com as sublistas */

int partition(int array[], int left, int right) {
    int pivot = array[right]; // Aqui é definido que o pivô será sempre o ultimo elemento da lista
    int aux = (left - 1);
    
    for(int i = left; i <= right - 1; i++) {
        if(array[i] < pivot) {
            aux++;
            swap(&array[aux], &array[i]);
        }
    }
    
    swap(&array[aux + 1], &array[right]); // Pivô é trocado pela posição onde o contador parou
    
    return (aux + 1); // é retornado o índice do pivô para fazer a divisão do array
}

/* A função 'quicksort' trata de chamar a função 'partition' para ordenar
os elementos de acordo com o pivô e retornar seu índice, para logo em
seguida chamar a si próprio para ordenar as sublistas criadas dentro
de si */

// Todo esse processo ocorre até a ordenação completa do array

void quicksort(int array[], int left, int right) {
    if(left < right) {
        int p = partition(array, left, right);
        
        quicksort(array, left, p - 1);
        quicksort(array, p + 1, right);
    }
}

int main() {
    int array[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(array) / sizeof(array[0]);
    
    quicksort(array, 0, size - 1);
    printArray(array, size);
    
    return 0;
}