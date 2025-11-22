/*
Author: Ravi Koothati
GitHub: https://github.com/ravikumark815
*/

#include <iostream>
#include <vector>

using namespace std;

void linear_search(vector <int> &nums, int key) {
    for (auto it : nums) {
        if (it == key) {
            cout << key << " found\n";
            return;
        }
    }
    cout << key << " not found\n";
}

int main()
{
    vector <int> nums = {0,1,2,3,4,5,6,7,8,9};
    linear_search(nums, 0);
    linear_search(nums, 9);
    linear_search(nums, 99);
    return 0;
}