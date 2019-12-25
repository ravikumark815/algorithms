/*
----- Fibonacci Search Algorithm -----

Author: https://github.com/ravikumark815
*/
#include<stdio.h>
#include<time.h>

int FibonacciSearch(int a[], int n, int key)
{
    int p = 0;
    int q = 1;
    int fibIndex = p + q;
    int offset = -1;
    int i=0;

    while (fibIndex < n)
    {
        p = q;
        q = fibIndex;
        fibIndex  = p + q;
    }

    while (fibIndex > 1)
    {
        i = ((offset+p) < (n-1)) ? (offset+p) : (n-1);

        if (a[i] < key)
        {
            fibIndex  = q;
            q = p;
            p = fibIndex - q;
            offset = i;
        }

        else if (a[i] > key)
        {
            fibIndex  = p;
            q = q - p;
            p = fibIndex - q;
        }

        else
        {
            return i+1;
        }
    }
    if(q && a[offset+1]==key)
    {
        return offset+2;
    }
    
    return -1;
}

int main()
{
    int n=0,i=0,res=0, key=0;
    clock_t tstart, tend;
    double tdiff;

    printf("\n\n~~~~~~~~~~~~~~~~~~~~ Algorithms ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\nVisit github/ravikumark815 <> linkedin.com/in/ravikumark815 for more");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

    printf("\n------- Fibonacci Search -------\n");
    printf("Enter the number of elements:\t");
    scanf("%d",&n);
    int a[n];
    printf("\n");
    
    for(i=0;i<n;i++)
    {
        printf("Enter Element#%d:\t",i+1);
        scanf("%d",&a[i]);
    }
    
    printf("\nArray:\n");
    for(i=0;i<n;i++)
        printf("| %d ",a[i]);
    
    printf("|\n\nEnter the element to be searched:\t");
    scanf("%d",&key);
    
    tstart = clock();
    res = FibonacciSearch(a, n, key);
    tend = clock();
    if(res>0)
        printf("\nElement Found at:\t%d\n", res);
    else
        printf("\nElement Not Found\n");
    tdiff = (double)(tend-tstart) / CLOCKS_PER_SEC;
    printf("Time Taken: %f\n\n", tdiff);

    return 0;
}