/*
----- Radix Sort Algorithm -----

Author: https://github.com/ravikumark815
*/
#include<stdio.h>
#include<time.h>

int largest(int a[], int n)
{
    int large = a[0], i;
    for(i = 1; i < n; i++)
    {
        if(large < a[i])
            large = a[i];
    }
    return large;
}
 

void RadixSort(int a[], int n)
{
    int bucket[10][10], bucket_count[10];
    int i, j, k, remainder, NOP=0, divisor=1, large, pass;
 
    large = largest(a, n);
    while(large > 0)
    {
        NOP++;
        large/=10;
    }
 
    for(pass = 0; pass < NOP; pass++)
    {
        for(i = 0; i < 10; i++)
        {
            bucket_count[i] = 0;
        }
        for(i = 0; i < n; i++)
        {
            remainder = (a[i] / divisor) % 10;
            bucket[remainder][bucket_count[remainder]] = a[i];
            bucket_count[remainder] += 1;
        }
 
        i = 0;
        for(k = 0; k < 10; k++)
        {
            for(j = 0; j < bucket_count[k]; j++)
            {
                a[i] = bucket[k][j];
                i++;
            }
        }
        divisor *= 10;
    }
}

int main()
{
    int n=0,i=0,a[50];
    clock_t tstart, tend;
    double tdiff;

    printf("\n\n~~~~~~~~~~~~~~~~~~~~ Algorithms ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\nVisit github/ravikumark815 <> linkedin.com/in/ravikumark815 for more");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    
    printf("\n------- Radix Sort -------\n");
    printf("Enter the number of elements (Max:50):\t");
    scanf("%d",&n);
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("Enter Element#%d:\t",i+1);
        scanf("%d",&a[i]);
    }
    printf("\nUnsorted Array:\n");
    for(i=0;i<n;i++)
        printf("| %d ",a[i]);
    printf("|\n");

    tstart = clock();
    RadixSort(a, n);
    tend = clock();
    tdiff = (double)(tend-tstart) / CLOCKS_PER_SEC;

    printf("\nSorted Array:\n");
    for(i=0;i<n;i++)
        printf("| %d ",a[i]);
    printf("|\n");
    printf("Time Taken: %f\n\n", tdiff);

    return 0;
}