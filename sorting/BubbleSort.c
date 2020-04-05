/*
----- Bubble Sort Algorithm -----

Author: https://github.com/ravikumark815
*/
#include<stdio.h>
#include<time.h>

int BubbleSort(int a[],int n);

int main()
{
    int n=0,i=0,a[50];
    clock_t tstart, tend;
    double tdiff;

    printf("\n\n~~~~~~~~~~~~~~~~~~~~ Algorithms ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\nVisit github/ravikumark815 <> linkedin.com/in/ravikumark815 for more");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    
    printf("\n------- Bubble Sort -------\n");
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
    BubbleSort(a, n);
    tend = clock();
    tdiff = (double)(tend-tstart) / CLOCKS_PER_SEC;

    printf("\nSorted Array:\n");
    for(i=0;i<n;i++)
        printf("| %d ",a[i]);
    printf("|\n");
    printf("Time Taken: %f\n\n", tdiff);

    return 0;
}
int BubbleSort(int a[],int n)
{
    int i=0,j=0;

    for(i=0;i<n;i++)
        for(j=0;j<n-i-1;j++)
            if(a[j]>a[j+1])
            {
                a[j] = a[j]+a[j+1];
                a[j+1] = a[j]-a[j+1];
                a[j] = a[j]-a[j+1];
            }
}