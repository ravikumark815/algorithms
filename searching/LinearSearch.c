/*
----- Linear Search Algorithm -----

Author: https://github.com/ravikumark815
*/
#include<stdio.h>
#include<time.h>

int LinearSearch(int a[], int n, int key)
{
    for (int i=0; i<n; i++)
    {
        if(a[i] == key)
        {
            return i;
        }
    }
    return 0;
}

int main()
{
    int n=0,i=0,res=0, key=0;
    clock_t tstart, tend;
    double tdiff;

    printf("\n\n~~~~~~~~~~~~~~~~~~~~ Algorithms ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\nVisit github/ravikumark815 <> linkedin.com/in/ravikumark815 for more");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

    printf("\n------- Linear Search -------\n");
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
    res = LinearSearch(a, n, key);
    tend = clock();
    if(res)
        printf("\nElement Found at:\t%d\n", res);
    else
        printf("\nElement Not Found\n");
    tdiff = (double)(tend-tstart) / CLOCKS_PER_SEC;
    printf("Time Taken: %f\n\n", tdiff);

    return 0;
}