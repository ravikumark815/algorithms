/*
----- Heap Sort Algorithm -----

Author: https://github.com/ravikumark815
*/

#include<stdio.h>
#include<time.h>

void ConvertToHeaps(int *a, int index, int heap_size);
void HeapSort(int *a, int n);

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
	HeapSort(a, n);
	tend = clock();
    tdiff = (double)(tend-tstart) / CLOCKS_PER_SEC;

    printf("\nSorted Array:\n");
    for(i=0;i<n;i++)
        printf("| %d ",a[i]);
    printf("|\n");
	printf("Time Taken: %f\n\n", tdiff);

    return 0;
}

void ConvertToHeaps(int *a, int index, int heap_size) {
	int temp;
	int largest = index;
	int left_index = 2 * index;
	int right_index = 2 * index + 1;
	if (left_index < heap_size && *(a + left_index) > *(a + largest)) {
		largest = left_index;
	}
	if (right_index < heap_size && *(a + right_index) > *(a + largest)) {
		largest = right_index;
	}

	if (largest != index) {
		temp = *(a + largest);
		*(a + largest) = *(a + index);
		*(a + index) = temp;
		ConvertToHeaps(a, largest, heap_size);
	}
}

void HeapSort(int *a, int n) {
	int temp;
	for (int i = n / 2 - 1; i > -1; i--) {
		ConvertToHeaps(a, i, n);
	}
	for (int i = n - 1; i > 0; i--) {
		temp = *(a);
		*(a) = *(a + i);
		*(a + i) = temp;
		ConvertToHeaps(a, 0, i);
	}
}