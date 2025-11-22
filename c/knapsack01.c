/*
0/1 Knapsack Problem:
Given N items where each item has some weight and profit associated with it and
 also given a bag with capacity W, [i.e., the bag can hold at most W weight in it]. 
The task is to put the items into the bag such that the sum of profits 
associated with them is the maximum possible. 

Note: The constraint here is we can either put an item completely 
into the bag or cannot put it at all 
[It is not possible to put a part of an item into the bag].

K[][]:
    0   1   2   3   4   5
0   0   0   0   0   0   0
1   0   20  20  20  20  20
2   0   20  20  30  50  50
3   0   20  20  30  50  50

*/
#include <stdio.h> 

int max(int a, int b) { return (a > b) ? a : b; } 

int knapSack(int Capacity, int weight[], int profit[], int no_obj) 
{ 
	int i, w; 
	int K[no_obj + 1][Capacity + 1]; 

	// Build table K[][]
	for (i = 0; i <= no_obj; i++) { 
		for (w = 0; w <= Capacity; w++) { 
			if (i == 0 || w == 0) // Fill in 0s in 1st row and column
				K[i][w] = 0; 
			else if (weight[i-1] <= w)  // 
				K[i][w] = max(profit[i-1] + K[i-1][w - weight[i-1]], K[i-1][w]); 
			else
				K[i][w] = K[i-1][w];
            // printf("i=%d, w=%d, K:%d\n", i, w, K[i][w]);
		}
        // printf("---\n");
	}

	return K[no_obj][Capacity]; 
} 

int main() 
{ 
	int profit[] = { 20, 30, 10 }; 
	int weight[] = { 1, 3, 4, 6 }; 
	int Capacity = 5; 
	int no_obj = sizeof(profit) / sizeof(profit[0]); 
	printf("Result: %d\n", knapSack(Capacity, weight, profit, no_obj)); 
	return 0; 
}
