/*
----- Binary Search Algorithm -----

Author: https://github.com/ravikumark815
*/
#include<stdio.h>
#include<time.h>

int BinarySearch(int a[], int low, int high, int key)
{
    while (high>=low)
    {
        int mid = low + (high-low)/2;
        
        if(a[mid] == key)
        {
            return mid+1;
        }
        if(key < a[mid])
        {
            high = mid-1;
        }
        if(key > a[mid])
        {
            low = mid+1;
        }
    }
    return -1;
}

int main()
{
    int n=0,i=0,res=0, key=0;
    clock_t tstart, tend;
    double tdiff;

    printf("\n\n~~~~~~~~~~~~~~~~~~~~ Algorithms ~~~~~~~~~~~~~~~~~~~~");
    printf("\n          Visit github/ravikumark815 for more");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

    printf("\n------- Binary Search -------\n");
    printf("Time Complexity: O(log n)\n");
    printf("Space Complexity: O(1)\n");

    printf("\nEnter the number of elements:\t");
    scanf("%d",&n);
    int a[n];
    printf("\n");
    
    for(i=0;i<n;i++)
    {
        printf("Enter Element #%d:\t",i+1);
        scanf("%d",&a[i]);
    }
    
    printf("\nArray:\t");
    for(i=0;i<n;i++)
        printf("| %d ",a[i]);
    
    printf("|\n\nEnter the element to be searched:\t");
    scanf("%d",&key);
    
    tstart = clock();
    res = BinarySearch(a, 0, n-1, key);
    tend = clock();
    
    if(res>0)
        printf("\nElement Found at:\t%d\n", res);
    else
        printf("\nElement Not Found\n");
    
    tdiff = (double)(tend-tstart) / CLOCKS_PER_SEC;
    printf("\n-------Time Taken: %f-------\n\n", tdiff);

    return 0;
}