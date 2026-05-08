#include <bits/stdc++.h>
using namespace std;

/*
    Question 9: Remove Duplicates from Sorted Array II
    link: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/

    Problem Statement:
    Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
*/

/*
    Intuition:
    since the array is sorted, we can handle the first elem duplication as k<2 
    all other elements duplication can be handled as num != nums[k-2]    
    as if num == nums[k-2] then that would create the 3rd consecutive number as the array is sorted
*/

int removeDuplicates(vector<int>& nums) {

    int k = 0;

    for (const int& num : nums) {
        if (k<2 || num != nums[k-2]) {
            nums[k] = num;
            k++;
        }
    }
    return k;
}

int main() {
    
    vector<int> input = {0,0,1,1,1,1,2,3,3};

    cout << "Sorting such that number occur at most 2 times consequetively " << removeDuplicates(input) << endl;

    cout << "After duplicate removal input array becomes:" << endl;
    for (const auto& i : input) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}