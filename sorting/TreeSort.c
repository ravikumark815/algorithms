/*
----- Tree Sort Algorithm -----

Author: https://github.com/ravikumark815
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct BST
{
    int Data;
    struct BST* Left;
    struct BST* Right;
};

void BSTInsert(struct BST**, int );
void BSTInorder(struct BST*);

int main()
{
    struct BST* P;
    int n=0,i=0,a[50];
    clock_t tstart, tend;
    double tdiff;
    
    printf("\n\n~~~~~~~~~~~~~~~~~~~~ Algorithms ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\nVisit github/ravikumark815 <> linkedin.com/in/ravikumark815 for more");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    
    printf("\n------- Tree Sort -------\n");
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
    {
        printf("| %d ",a[i]);
        BSTInsert(&P, a[i]);
    }
    printf("|\n");
    
    tstart = clock();
    BSTInorder(P);
    tend = clock();
    tdiff = (double)(tend-tstart) / CLOCKS_PER_SEC;

    printf("\nSorted Array:\n");
    printf(" |\n\n");
    printf("Time Taken: %f\n\n", tdiff);

    return 0;
}
void BSTInsert(struct BST** P, int num)
{
    if(*P == NULL)
    {
        *P = malloc(sizeof(struct BST));
        (*P)->Data = num;
        (*P)->Left = NULL;
        (*P)->Right = NULL;
    }
    else
    {
        if(num<(*P)->Data)
            BSTInsert(&((*P)->Left),num);
        else
            BSTInsert(&((*P)->Right),num);
    }
}

void BSTInorder(struct BST* P)
{
    if(P!=NULL)
    {
        BSTInorder(P->Left);
        printf("| %d ",P->Data);
        BSTInorder(P->Right);
    }
}