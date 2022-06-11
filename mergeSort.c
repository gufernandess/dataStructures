#include<stdio.h>
#include<stdlib.h>

/* A função merge junta dois sub-arrays do array original
ao mesmo tempo que os ordena, isso após o
mesmo ser dividido completamente */

void merge(int array[], int left, int mid, int right) {
    int i, j, k;
    int firstLength = mid - left + 1;
    int secondLength = right - mid;
    
    int firstSubarray[firstLength], // Criando arrays temporários
        secondSubarray[secondLength];
        
    // Copiando dados para arrays temporários
        
    for(i = 0; i < firstLength; i++) {
        firstSubarray[i] = array[left + i];
    }
    
    for(j = 0; j < secondLength; j++) {
        secondSubarray[j] = array[mid + 1 + j];
    }
    
    i = 0;
    j = 0;
    k = left;
    
    // Merge dos arrays temporários para o array original
    
    while(i < firstLength && j < secondLength) {
        if(firstSubarray[i] <= secondSubarray[j]) {
            array[k] = firstSubarray[i];
            i++;
        } else {
            array[k] = secondSubarray[j];
            j++;
        }
        
        k++;
    }
    
    // copiando elementos remanescentes do primeiro sub-array
    
    while(i < firstLength) {
        array[k] = firstSubarray[i];
        i++;
        k++;
    }
    
// copiando elementos remanescentes do segundo sub-array
    
    while(j < secondLength) {
        array[k] = secondSubarray[j];
        j++;
        k++;
    }
}

/* Algoritmo que faz as sucessivas divisões dentro do array de forma
recursiva */

void mergeSort(int array[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        
        merge(array, left, mid, right);
    }
}

int main() {
    int array[] = {12, 11, 13, 5, 6, 7};
    int arraySize = sizeof(array) / sizeof(array[0]);
    
    mergeSort(array, 0, arraySize - 1);
    
    printf("[");
    
    for(int i = 0; i < arraySize; i++) {
        printf("%d,", array[i]);
    }
    
    printf("]");
    
    return 0;
}