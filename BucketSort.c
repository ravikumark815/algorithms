/*
----- Bucket Sort Algorithm -----

Author: https://github.com/ravikumark815
*/

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int a_size=0;
#define bucket_size 5
#define bucket_interval 10

struct Node
{
    int data;
    struct Node *next;
};

void Bucket_Sort(int arr[]);
struct Node *InsertionSort(struct Node *list);
void print(int arr[]);
void printBuckets(struct Node *list);
int getBucketIndex(int value);

void Bucket_Sort(int arr[])
{
    int i,j;
    struct Node **buckets;

    buckets = (struct Node **)malloc(sizeof(struct Node*) * bucket_size);

    for(i = 0; i < bucket_size; ++i)
    {
        buckets[i] = NULL;
    }

    for(i = 0; i < a_size; ++i)
    {
        struct Node *current;
        int pos = getBucketIndex(arr[i]);
        current = (struct Node *) malloc(sizeof(struct Node));
        current->data = arr[i];
        current->next = buckets[pos];
        buckets[pos] = current;
    }

    for(i = 0; i < bucket_size; i++)
    {
        printf("Bucket[\"%d\"] : ", i);
        printBuckets(buckets[i]);
        printf("\n");
    }

    for(i = 0; i < bucket_size; ++i)
    {
        buckets[i] = InsertionSort(buckets[i]);
    }

    printf("--------------\n");
    printf("Buckets after sorted\n");
    for(i = 0; i < bucket_size; i++)
    {
        printf("Bucket[\"%d\"] : ", i);
        printBuckets(buckets[i]);
        printf("\n");
    }

    for(j =0, i = 0; i < bucket_size; ++i)
    {
        struct Node *node;
        node = buckets[i];
        while(node)
        {

            assert(j < a_size);
            arr[j++] = node->data;
            node = node->next;
        }
    }

    for(i = 0; i < bucket_size; ++i)
    {
        struct Node *node;
        node = buckets[i];
        while(node)
        {
            struct Node *tmp;
            tmp = node;
            node = node->next;
            free(tmp);
        }
    }
    free(buckets);
    return;
}

struct Node *InsertionSort(struct Node *list)
{
    struct Node *k,*nodeList;
    if(list == NULL || list->next == NULL)
    {
        return list;
    }

    nodeList = list;
    k = list->next;
    nodeList->next = NULL;
    while(k != NULL)
    {
        struct Node *ptr;
        if(nodeList->data > k->data)
        {
            struct Node *tmp;
            tmp = k;
            k = k->next;
            tmp->next = nodeList;
            nodeList = tmp;
            continue;
        }

        for(ptr = nodeList; ptr->next != NULL; ptr = ptr->next)
        {
            if(ptr->next->data > k->data) break;
        }

        if(ptr->next != NULL)
        {
            struct Node *tmp;
            tmp = k;
            k = k->next;
            tmp->next = ptr->next;
            ptr->next = tmp;
            continue;
        }
        else
        {
            ptr->next = k;
            k = k->next;
            ptr->next->next = NULL;
            continue;
        }
    }
    return nodeList;
}

int getBucketIndex(int value)
{
    return value/bucket_interval;
}

void print(int ar[])
{
    int i;
    for(i = 0; i < a_size; ++i)
    {
        printf("%d ", ar[i]);
    }
    printf("\n");
}

void printBuckets(struct Node *list)
{
    struct Node *cur = list;
    while(cur)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
}
int main()
{
    int a[100];
    int n;
    int i;
    
    printf("\n\n~~~~~~~~~~~~~~~~~~~~ Algorithms ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\nVisit github/ravikumark815 <> linkedin.com/in/ravikumark815 for more");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    
    printf("\n------- Bucket Sort -------\n");
    
    printf("Enter the number of elements (Max:50):\t");
    scanf("%d",&n);
    a_size = n;
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

    Bucket_Sort(a);

    printf("\nSorted Array:\n");
    for(i=0;i<n;i++)
        printf("| %d ",a[i]);
    printf("|\n");

    return 0;
}