#include <bits/stdc++.h>
using namespace std;

/*
    Question no 5: Move Zeros:
    link: https://leetcode.com/problems/move-zeroes/

    Problem Statement: Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
    Note that you must do this in-place without making a copy of the array.
*/

void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int i=0;
    
    for (int j=0 ; j<n ; j++) {
        if (nums[j] != 0) {
            swap(nums[i], nums[j]);
            i++;
        }
    } 
}

int main() {
    vector<int> input = {2,0,4,0,9};
    moveZeroes(input);

    for (const auto& n : input) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}