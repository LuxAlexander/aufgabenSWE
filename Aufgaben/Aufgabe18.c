#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

/* ============================================================================
 * Name : myMinInsertionSort.c
 * Author : Alexander Lux
 * Version : 1.0
 * Description : InsertionSort
 * ============================================================================ */


void fill(int*);
void insertion_sort(int*);
void print(int *arr);

int main(void) {
    srand(time(NULL));
    int array[SIZE];
    int temp=0;

    fill(array);

    printf("\nSort\n");
    insertion_sort(array);

    printf("Ergebnis\n\n");
    print(array);
    return 0;
}

void fill(int *array) {
    for (int i = 0; i < 10; i++) {
        array[i] = rand() % 100;
        printf("%d ",array[i]);
    }
}

void insertion_sort(int *array) {
    for (int i = 1; i <SIZE; ++i) {
        int pivot = array[i];
        int j=i-1;

        while (j>=0 && array[j]>pivot) {
            array[j+1] = array[j];
            j-=1;
        }
        array[j+1] = pivot;

    }
}

void print(int *array) {

    for (int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
}