/*
Author: https://github.com/ravikumark815

------- Merge Sort -------
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

void merge(int *array, int low, int mid, int high)
{
    int left_size = mid - low + 1;
    int right_size = high - mid;
    int left[left_size], right[right_size];
    int i = 0, j = 0, k = 0;

    // Copy low-mid part into Left and the rest into Right
    for (i = 0; i < left_size; i++)
        left[i] = array[low + i];
    for (j = 0; j < right_size; j++)
        right[j] = array[mid + 1 + j];
    // Reset indices for next comparison
    i = 0, j = 0;

    // Rewrite array in ascending order by comparing each element of Left and Right
    while ((i < left_size) && (j < right_size)) {
        if (left[i] <= right[j]) {
            array[k] = left[i];
            i++;
        }
        else {
            array[k] = right[j];
            j++;
        }
        k++;
    }
    // Copy leftover elements in left array, if any
    while (i < left_size) { 
        array[k] = left[i];
        i++; k++;
    }
    // Copy leftover elements in right array, if any
    while (j < right_size) { 
        array[k] = right[j];
        j++; k++;
    }

    return;
}

void merge_sort(int *array, int low, int high)
{
    if (low < high) {
        int mid = (high + low)/2;
        
        merge_sort(array, low, mid);
        merge_sort(array, mid + 1, high);
        merge(array, low, mid, high);
    }
}

void main ()
{
    int n = 0;
    printf("\n------- Merge Sort ------\n");
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
    merge_sort(array, 0, n-1);
    tend = clock();
    
    printf("\nSorted Array:");
    array_display(array, n);
    printf("Time taken:%f\n", (double)(tend-tstart) / CLOCKS_PER_SEC); 
    
    return;
}