/*
----- Insertion Sort Algorithm -----

Author: https://github.com/ravikumark815
*/
#include<stdio.h>

int InsertionSort(int a[],int n);

int main()
{
    int n=0,i=0,a[50];

    printf("\n------- Insertion Sort -------\n");
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

    InsertionSort(a, n);
    
    printf("\nSorted Array:\n");
    for(i=0;i<n;i++)
        printf("| %d ",a[i]);
    printf("|\n");

    return 0;
}
int InsertionSort(int a[],int n)
{
    int i=0,j=0,key=0;

    for(i=1;i<n;i++)
    {
        key = a[i];
        j=i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = key;
    }
}