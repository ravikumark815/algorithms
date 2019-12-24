/*
----- Merge Sort Algorithm -----

Author: https://github.com/ravikumark815
*/
#include<stdio.h>

int MergeSort(int a[],int low, int high);
int Merge(int a[], int low, int mid, int high);

int main()
{
    int n=0,i=0,a[50];

    printf("\n\n~~~~~~~~~~~~~~~~~~~~ Algorithms ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\nVisit github/ravikumark815 <> linkedin.com/in/ravikumark815 for more");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    
    printf("\n------- Merge Sort -------\n");
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

    MergeSort(a, 0, n-1);
    
    printf("\nSorted Array:\n");
    for(i=0;i<n;i++)
        printf("| %d ",a[i]);
    printf("|\n");

    return 0;
}
int MergeSort(int a[],int low, int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;

        MergeSort(a, low, mid);
        MergeSort(a, mid+1, high);
        
        Merge(a,low,mid,high);
    }
}
int Merge(int a[], int low, int mid, int high)
{
    int leftsize = mid-low+1;
    int rightsize = high-mid;
    int Left[leftsize];
    int Right[rightsize];
    int i=0,j=0,k=0;

    for(i=0;i<leftsize;i++)
    {
        Left[i] = a[low+i];
    }
    for(j=0;j<rightsize;j++)
    {
        Right[j] = a[mid+1+j];
    }
    i=0,j=0;
    while(i<leftsize && j<rightsize)
    {
        if(Left[i]<=Right[j])
        {
            a[k] = Left[i];
            i++;
        }
        else
        {
            a[k] = Right[j];
            j++;
        }
        k++;
    }
    while(i<leftsize)
    {
        a[k] = Left[i];
        k++;
        i++;
    }
    while(j<rightsize)
    {
        a[k] = Right[j];
        k++;
        j++;
    }
}