/*
Author: Ravi Koothati
GitHub: https://github.com/ravikumark815
*/

#include <iostream>
#include <vector>

using namespace std;

void binary_search(vector <int> &nums, int key) {
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high) {
        int mid = low + ((high - low)/2);
        cout << "low: " << low << " mid: " << mid << " high: " << high << endl;
        if (nums[mid] == key) {
            cout << key << " found at " << mid << endl;
            return;
        }
        if (nums[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    cout << key << " not found\n";
    return;
}

int main() 
{
    vector <int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "--- Binary Search --- \n";
    binary_search(nums, 9);
    binary_search(nums, 0);
    binary_search(nums, 4);
    binary_search(nums, 5);
    binary_search(nums, 1);
    binary_search(nums, 8);
    cout << endl;
    return 0;
}