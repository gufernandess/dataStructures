#include<stdio.h>

void swap(int* firstNumber, int* secondNumber) {
    *secondNumber = (*firstNumber + *secondNumber) - (*firstNumber = *secondNumber);
}

int invert_array(int array[], int aux, int index) {
    if(aux >= index) return 1;

    swap(&array[aux], &array[index - 1]);
    
    invert_array(array, aux + 1, index - 1);
}

void print_array(int array[], int index) {
    printf("\n[");
    for(int i = 0; i < index; i++) {
        i == index - 1 ? printf("%d", array[i]) : printf("%d,", array[i]);
    }
    printf("]\n");
}

int main() {
    int index = 0;

    printf("Insira o tamanho do array: \n");
    scanf("%d", &index);

    int array[index];

    printf("Escolha os elementos do array: \n");
    for(int i = 0; i < index; i++) scanf("%d", &array[i]);

    printf("\nArray inserido:");
    print_array(array, index);

    invert_array(array, 0, index);

    printf("\nArray invertido:");
    print_array(array, index);

    return 0;
}