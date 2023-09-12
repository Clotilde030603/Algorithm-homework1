#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Sort.h"       

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i*200]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int array_size = 50000;

    int* array_bubble = (int*)malloc(array_size * sizeof(int));
    int* array_quick = (int*)malloc(array_size * sizeof(int));

    if (array_bubble == NULL || array_quick == NULL) {
        printf("메모리 할당에 실패했습니다.\n");
        return 1;
    }

    for (int i = 0; i < array_size; i++) {
        int random_number = rand() % 30001;
        array_bubble[i] = random_number;
        array_quick[i] = random_number;
    }

    int random_indices[10];

    for (int i = 0; i < 10; i++) {
        random_indices[i] = rand() % array_size;
    }

    int* copy_array_bubble = (int*)malloc(array_size * sizeof(int));
    int* copy_array_quick = (int*)malloc(array_size * sizeof(int));

    if (copy_array_bubble == NULL || copy_array_quick == NULL) {
        printf("메모리 할당에 실패했습니다.\n");
        return 1;
    }


    for (int i = 0; i < array_size; i++) {
        copy_array_bubble[i] = array_bubble[i];
        copy_array_quick[i] = array_quick[i];
    }

    clock_t start_bubble = clock();
    BubbleSort(copy_array_bubble, array_size);
    clock_t end_bubble = clock();
    double elapsed_time_bubble = ((double)(end_bubble - start_bubble) / CLOCKS_PER_SEC) * 1000;

    clock_t start_quick = clock();
    qsort(copy_array_quick, array_size, sizeof(int), compare);
    clock_t end_quick = clock();
    double elapsed_time_quick = ((double)(end_quick - start_quick) / CLOCKS_PER_SEC) * 1000;

    printf("-------------------------------------------\n");
    printf("-------------------------------------------\n");

    printf("Before BubbleSort\n");
    printArray(array_bubble, 10);

    printf("After BubbleSort\n");
    printArray(copy_array_bubble, 10);

    printf("Time elapsed for BubbleSort: %.3lf msec\n", elapsed_time_bubble);

    printf("-------------------------------------------\n");
    printf("-------------------------------------------\n");

    printf("Before QuickSort\n");
    printArray(array_quick, 10);

    printf("After QuickSort\n");
    printArray(copy_array_quick, 10);

    printf("Time elapsed for QuickSort: %.3lf msec\n", elapsed_time_quick);

    free(array_bubble);
    free(array_quick);
    free(copy_array_bubble);
    free(copy_array_quick);

    return 0;
}