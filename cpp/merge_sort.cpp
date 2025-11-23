/*
Author: Ravi Koothati
GitHub: https://github.com/ravikumark815
*/

#include <iostream>
#include <vector>

using namespace std;

void merge(vector <int> &nums, int low, int mid, int high) {
    int size1 = mid - low + 1;
    int size2 = high - mid;

    vector<int> Left(size1), Right(size2);
    for (int i = 0; i < size1; i++) {
        Left[i] = nums[low + i];
    }
    for (int j = 0; j < size2; j++) {
        Right[j] = nums[mid + 1 + j];
    }

    int i = 0, j = 0, k = low;;
    while ((i < size1) && (j < size2)) {
        if (Left[i] <= Right[j]) {
            nums[k] = Left[i];
            i++;
        } else {
            nums[k] = Right[j];
            j++;
        }
        k++;
    }
    while (i < size1) {
        nums[k] = Left[i];
        i++;
        k++;
    }
    while (j < size2) {
        nums[k] = Right[j];
        j++;
        k++;
    }
}

void merge_sort(vector <int> &nums, int low, int high) {
    if (low >= high) return;

    int mid = low + ((high - low)/2);

    merge_sort(nums, low, mid);
    merge_sort(nums, mid + 1, high);
    merge(nums, low, mid, high);

    return;
}

int main()
{
    vector <int> nums = {9,7,5,3,1,2,6,4,8,0};
    
    cout << "Before Sort: ";
    for (auto it: nums) {
        cout << it << " ";
    }
    cout << endl;

    merge_sort(nums, 0, nums.size()-1);

    cout << "After Sort: ";
    for (auto it: nums) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}