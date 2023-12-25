/*
Author: https://github.com/ravikumark815

------- Quick Sort -------
*/

#include <stdio.h>
#include <time.h>

#define SWAP(a, b) int tmp = a; a = b; b = tmp;

void array_display(int *array, int arrsize)
{
    for (int i = 0; i < arrsize; i++)
        printf("|%d", array[i]);
    printf("|\n");
}

int Partition(int *array, int low, int high)
{
    int pivot_elem = array[high];
    int i = low - 1;

    for (int j = low; j <= high-1; j++) {
        if (array[j] <= pivot_elem) {
            i++;
            SWAP(array[i], array[j]);
        }
    }
    SWAP(array[i+1], array[high]);
    return i+1;
}

void quick_sort(int *array, int low, int high)
{
    if (low < high) {
        int pivot_index = Partition(array, low, high);
        quick_sort(array, low, pivot_index - 1);
        quick_sort(array, pivot_index + 1, high);
    }
}

void main ()
{
    int n = 0;
    printf("\n------- Quick Sort ------\n");
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int array[n];
    clock_t tstart, tend;

    for (int i = 0; i < n; i++) {
        printf("Enter element #%d - ", i+1);
        scanf("%d", &array[i]);
    }

    printf("\nUnsorted Array:");
    array_display(array, n);

    tstart = clock();
    quick_sort(array, 0, n-1);
    tend = clock();
    
    printf("\nSorted Array:");
    array_display(array, n);
    printf("Time taken:%f\n", (double)(tend-tstart) / CLOCKS_PER_SEC); 
    
    return;
}