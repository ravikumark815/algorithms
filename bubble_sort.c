/*
Author: https://github.com/ravikumark815

------- Bubble Sort -------
*/

#include <stdio.h>
#include <time.h>

#define SWAP(a, b) a = a^b; b = a^b; a = a^b;

void array_display(int *array, int arrsize)
{
    for (int i = 0; i < arrsize; i++)
        printf("|%d", array[i]);
    printf("|\n");
}

int bubble_sort(int *array, int arrsize)
{
    for (int i = 0; i < arrsize; i++)
        for (int j = 0; j < (arrsize - i - 1); j++)
            if (array[j] > array[j+1]) {
                SWAP(array[j], array[j+1]);
            }
    return 0;
}

void main ()
{
    int n = 0;
    printf("\n------- Bubble Sort ------\n");
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
    bubble_sort(array, n);
    tend = clock();
    
    printf("\nSorted Array:");
    array_display(array, n);
    printf("Time taken:%f\n", (double)(tend-tstart) / CLOCKS_PER_SEC); 
    
    return;
}