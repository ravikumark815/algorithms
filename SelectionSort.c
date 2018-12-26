/*
----- Bubble Sort Algorithm -----

Author: https://github.com/ravikumark815
*/
#include<stdio.h>

int SelectionSort(int a[],int n);

int main()
{
    int n=0,i=0,a[50];

    printf("\n------- Selection Sort -------\n");
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

    SelectionSort(a, n);

    printf("\nSorted Array:\n");
    for(i=0;i<n;i++)
        printf("| %d ",a[i]);
    printf("|\n");

    return 0;
}
int SelectionSort(int a[], int n)
{
    int i=0,j=0;

    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if(a[i]>a[j])
            {
                a[i] = a[i]^a[j];
                a[j] = a[i]^a[j];
                a[i] = a[i]^a[j];
            }
}