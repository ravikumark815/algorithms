/*
Author: https://github.com/ravikumark815

------- Binary Search -------
*/

#include <stdio.h>
#include <time.h>

int binary_search_it(int *array, int low, int high, int element)
{
    while (high >= low) {
        int mid = low + ((high - low) / 2);
        
        if (array[mid] == element) return mid + 1;
        else if (array[mid] > element) high = mid - 1;
        else low = mid + 1;
    }
    return 0;
}

int binary_search_re(int *array, int low, int high, int element)
{
    if (high >= low) {
        int mid = low + ((high - low) / 2);
        
        if (array[mid] == element) return mid + 1;
        else if (array[mid] > element) return binary_search_re(array, low, mid - 1, element);
        else return binary_search_re(array, mid + 1, high, element);;
    }
    return 0;
}

int main ()
{
    int n = 0;
    printf("\n------- Queue ------\n");
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int array[n], element, res_it = -1, res_re = -1;
    clock_t tstart_it, tend_it;
    clock_t tstart_re, tend_re;

    for (int i = 0; i < n; i++) {
        printf("Enter element #%d - ", i+1);
        scanf("%d", &array[i]);
    }

    printf("\nEnter element to be searched: ");
    scanf("%d", &element);

    tstart_it = clock();
    res_it = binary_search_it(array, 0, n, element);
    tend_it = clock();
    if (res_it) {
        printf("Element found at index [Iterative]: %d\n", res_it);
        printf("Time taken [Iterative]:%f\n", (double)(tend_it-tstart_it) / CLOCKS_PER_SEC); 
    }

    tstart_re = clock();
    res_re = binary_search_re(array, 0, n, element);
    tend_re = clock();
    if (res_re) {
        printf("\nElement found at index: %d\n", res_re);   
        printf("Time taken [Recursive]:%f\n", (double)(tend_re-tstart_re) / CLOCKS_PER_SEC);
    }

    printf("Element not found in the array\n");
    return 0;
}