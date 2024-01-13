/*
Author: https://github.com/ravikumark815

------- Fibonacci Search -------
*/

#include <stdio.h>
#include <time.h>

int fibonacci_search(int *array, int element, int arrsize)
{
    int fibN2 = 0, fibN1 = 1, fibN = fibN1 + fibN2;
    int lower = 0, offset = -1; // lowers marks the start of offset in which elem will be searched

    // Find a Fibonacci no that is greater than or equal to arrsize
    while (arrsize > fibN) {
        fibN2 = fibN1;
        fibN1 = fibN;
        fibN = fibN1 + fibN2;
    }

    while (fibN > 1) { // Until we dont run out of fib nos, we decreasing the offset. PS: if fibN=1 then fibN2=0
        lower = ((offset + fibN2) < (arrsize - 1)) ? (offset + fibN2) : (arrsize - 1);

        if (array[lower] < element) { // Shift offset right and move offset
            fibN = fibN1;
            fibN1 = fibN2;
            fibN2 = fibN - fibN1;
            offset = lower;
        }
        else if (array[lower] > element) { //Shift offset left
            fibN = fibN2;
            fibN1 = fibN1 - fibN2;
            fibN2 = fibN - fibN1;
        }
        else
            return lower + 1;
        
        if (fibN1 && array[offset + 1] == element) // Check for last element
            return (offset + 2);
    }
    return 0;
}

void main ()
{
    int n = 0;
    printf("\n------- Fibonacci Search ------\n");
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int array[n], element, res = 0;
    clock_t tstart, tend;

    for (int i = 0; i < n; i++) {
        printf("Enter element #%d - ", i+1);
        scanf("%d", &array[i]);
    }

    printf("\nEnter element to be searched: ");
    scanf("%d", &element);

    tstart = clock();
    res = fibonacci_search(array, element, n);
    tend = clock();
    
    if (res) printf("Element found at index: %d\n", res);
    else printf("Element not found in the array\n");
    printf("Time taken:%f\n", (double)(tend-tstart) / CLOCKS_PER_SEC); 
    
    return;
}