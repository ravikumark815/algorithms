/*
----- Tim Sort Algorithm -----

Author: https://github.com/ravikumark815
*/
#include <stdio.h>
#include <time.h>
const int N = 32;

void insertionSort(int a[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int temp = a[i];
        int j = i - 1;
        while (a[j] > temp && j >= left)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

void merge(int a[], int l, int m, int r)
{
    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];
    for (int i = 0; i < len1; i++)
        left[i] = a[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = a[m + 1 + i];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < len1 && j < len2)
    {
        if (left[i] <= right[j])
        {
            a[k] = left[i];
            i++;
        }
        else
        {
            a[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < len1)
    {
        a[k] = left[i];
        k++;
        i++;
    }

    while (j < len2)
    {
        a[k] = right[j];
        k++;
        j++;
    }
}

int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void TimSort(int a[], int n)
{
    for (int i = 0; i < n; i += N)
        insertionSort(a, i, min((i + 31), (n - 1)));

    for (int size = N; size < n; size = 2 * size)
    {
        for (int left = 0; left < n; left += 2 * size)
        {
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1), (n - 1));

            merge(a, left, mid, right);
        }
    }
}

int main()
{
    int n = 0, i = 0, a[50];
    clock_t tstart, tend;
    double tdiff;

    printf("\n\n~~~~~~~~~~~~~~~~~~~~ Algorithms ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\nVisit github/ravikumark815 <> linkedin.com/in/ravikumark815 for more");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

    printf("\n------- Tim Sort -------\n");
    printf("Enter the number of elements (Max:50):\t");
    scanf("%d", &n);
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("Enter Element#%d:\t", i + 1);
        scanf("%d", &a[i]);
    }
    printf("\nUnsorted Array:\n");
    for (i = 0; i < n; i++)
        printf("| %d ", a[i]);
    printf("|\n");

    tstart = clock();
    TimSort(a, n);
    tend = clock();
    tdiff = (double)(tend - tstart) / CLOCKS_PER_SEC;

    printf("\nSorted Array:\n");
    for (i = 0; i < n; i++)
        printf("| %d ", a[i]);
    printf("|\n");
    printf("Time Taken: %f\n\n", tdiff);

    return 0;
}