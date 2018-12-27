/*
----- Tree Sort Algorithm -----

Author: https://github.com/ravikumark815
*/
#include<stdio.h>
#include<stdlib.h>

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

    printf("\nSorted Array:\n");
    BSTInorder(P);
    printf(" |\n\n");

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