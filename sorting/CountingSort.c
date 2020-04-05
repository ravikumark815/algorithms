/*
----- Counting Sort Algorithm -----

Author: https://github.com/ravikumark815
*/
#include<stdio.h>
#include<time.h>
#include<string.h>

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

int smallest(int a[], int n)
{
    int small = a[0], i;
    for(i = 1; i < n; i++)
    {
        if(small > a[i])
            small = a[i];
    }
    return small;
}

void CountingSort(int a[], int n) 
{ 
    int max = largest(a, n);
    int min = smallest(a, n);
    int i = 0;
    
    int b[max+1];
    memset(b, 0, (max+1)*sizeof(b[0]));

    for(i=0; i<n; i++)
    {
        b[a[i]]++;
    }

    printf("\nSorted Array:\n");
    for(i=0; i<(max+1); i++)
    {
        if(b[i] > 0)
        {
            while(b[i] != 0)
            {
                printf("| %d ",i);
                b[i]--;
            }
        }
    }
    printf("|\n");
}

int main()
{
    int n=0,i=0,a[50];
    clock_t tstart, tend;
    double tdiff;

    printf("\n\n~~~~~~~~~~~~~~~~~~~~ Algorithms ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\nVisit github/ravikumark815 <> linkedin.com/in/ravikumark815 for more");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    
    printf("\n------- Counting Sort -------\n");
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
    CountingSort(a, n);
    tend = clock();
    tdiff = (double)(tend-tstart) / CLOCKS_PER_SEC;

    printf("Time Taken: %f\n\n", tdiff);

    return 0;
}