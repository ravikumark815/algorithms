/*
Author: Ravi Koothati
GitHub: https://github.com/ravikumark815
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int partition(vector <int> &nums, int low, int high) {
    int pivot = nums[high];
    int i = (low - 1);
    
    for (int j = low; j < high; j++) {
        if (nums[j] <= pivot) {
            i++;
            swap(nums[i],  nums[j]);
        }
    }

    swap(nums[i + 1],  nums[high]);
    return i + 1;
}

void quick_sort (vector <int> &nums, int low, int high) {
    if (low >= high) return;

    int pivot = partition (nums, low, high);
    quick_sort(nums, low, pivot - 1);
    quick_sort(nums, pivot + 1, high);
    return;
}

int main()
{
    vector <int> nums = {9,7,5,3,1,2,8,6,4,0};
    cout << "Before Sort: ";
    for (auto it : nums) {
        cout << it << " ";
    }
    cout << endl;
    
    quick_sort(nums, 0 , nums.size() - 1);
    
    cout << "After Sort: ";
    for (auto it : nums) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}