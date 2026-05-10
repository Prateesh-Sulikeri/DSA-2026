#include <bits/stdc++.h>
using namespace std;

/*
    Question no 6: Sort Colors:
    link: https://www.hellointerview.com/learn/code/two-pointers/sort-colors

    Write a function to sort a given integer array nums in-place (and without the built-in sort function), where the array contains n integers that are either 0, 1, and 2 and represent the colors red, white, and blue. Arrange the objects so that same-colored ones are adjacent, in the order of red, white, and blue (0, 1, 2).
*/

void sortColors(vector<int>& nums) {
    int i = 0, j = 0, k = nums.size() - 1;

    while (j<=k) {
        if (nums[j] < 1) {
            swap(nums[j], nums[i]);
            i++;
            j++;
        }
        else if (nums[j] > 1) {
            swap(nums[k], nums[j]);
            k--;
        }
        else 
            j++;
    }
}

int main() {
    vector<int> input = {2,0,2,1,1,0};
    sortColors(input);

    for (const auto& n : input) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}