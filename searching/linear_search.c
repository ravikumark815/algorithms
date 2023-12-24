/*
Author: https://github.com/ravikumark815

------- Linear Search -------
*/

#include <stdio.h>
#include <time.h>

int linear_search(int *array, int element, int n)
{
    for (int i = 0; i < n; i++)
        if (array[i] == element) return i+1;
}

int main ()
{
    int n = 0;
    printf("\n------- Linear Search ------\n");
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int array[n], element, res = -1, res_re = -1;
    clock_t tstart, tend;

    for (int i = 0; i < n; i++) {
        printf("Enter element #%d - ", i+1);
        scanf("%d", &array[i]);
    }

    printf("\nEnter element to be searched: ");
    scanf("%d", &element);

    tstart = clock();
    res = linear_search(array, element, n);
    tend = clock();
    if (res) {
        printf("Element found at index: %d\n", res);
        printf("Time taken:%f\n", (double)(tend-tstart) / CLOCKS_PER_SEC); 
        return 0;
    }

    printf("Element not found in the array\n");
    return 0;
}