/*
Author: https://github.com/ravikumark815

------- Interpolation Search -------
General equation of line : y = m*x + c.
y is the value in the array and x is its index.

Now putting value of low,high and x in the equation
array[high] = m*high+c ----(1)
array[low] = m*low+c ----(2)
x = m*pos + c     ----(3)

m = (array[high] - array[low] )/ (high - low)

subtracting eqxn (2) from (3)
x - array[low] = m * (pos - low)
low + (x - array[low])/m = pos
pos = low + (x - array[low]) *(high - low)/(array[high] - array[low])
*/

#include <stdio.h>
#include <time.h>

int interpolation_search(int *array, int element, int arrsize)
{
    int low = 0, high = arrsize - 1;
    while (low <= high && element >= array[low] && element <= array[high]) 
    {
        int pos = low + ((element - array[low]) * (high - low)) / (array[high] - array[low]);
        if (element > array[pos])
            low = pos + 1;
        else if (element < array[pos])
            high = pos - 1;
        else
            return pos + 1;
    }

    return 0;
}

void main ()
{
    int arrsize = 0;
    printf("\n------- Interpolation Search ------\n");
    printf("Enter the number of elements: ");
    scanf("%d", &arrsize);
    
    int array[arrsize], element, res = 0;
    clock_t tstart, tend;

    for (int i = 0; i < arrsize; i++) {
        printf("Enter element #%d - ", i+1);
        scanf("%d", &array[i]);
    }

    printf("\nEnter element to be searched: ");
    scanf("%d", &element);

    tstart = clock();
    res = interpolation_search(array, element, arrsize);
    tend = clock();
    
    if (res) printf("Element found at index: %d\n", res);
    else printf("Element not found in the array\n");
    printf("Time taken:%f\n", (double)(tend-tstart) / CLOCKS_PER_SEC); 
    
    return;
}