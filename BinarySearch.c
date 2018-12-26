/*
----- Binary Search Algorithm -----

Author: https://github.com/ravikumark815
*/
#include<stdio.h>

int a[50];
int BinarySearch(int low, int high, int key);

int main()
{
    int n=0,i=0,low=0,mid=0,high=0,key=0;

    printf("\n------- Binary Search -------\n");
    printf("Enter the number of elements:\t");
    scanf("%d",&n);
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
    low =0;
    high = n-1;
    mid = (low+high)/2;
    if(BinarySearch(low,high,key))
        printf("\nElement Found at:\t%d\n",BinarySearch(low,high,key));
    else
        printf("\nElement Not Found\n");
    return 0;
}

int BinarySearch(int low, int high, int key)
{
    int mid = (low+high)/2;
    if(a[mid]==key)
        return mid+1;
    else if(key<a[mid])
        BinarySearch(low,mid-1,key);
    else if(key>a[mid])
        BinarySearch(mid+1,high,key);
    else
        return 0;
}