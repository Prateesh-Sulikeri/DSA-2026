#include <bits/stdc++.h>
using namespace std;

/*
    Question no 1: Two Sum:
    link: https://takeuforward.org/plus/dsa/problems/two-sum?subject=dsa&category=arrays&subcategory=faqs-medium&approach=optimal

    Problem Statement: Given an array of integers nums and an integer target. Return the indices(0 - indexed) of two elements in nums such that they add up to target.
        Each input will have exactly one solution, and the same element cannot be used twice. Return the answer in increasing order.

    Case 1:

        Input: nums = [1, 6, 2, 10, 3], target = 7

            Output: [0, 1]

            Explanation:

            nums[0] + nums[1] = 1 + 6 = 7

    Case 2:

            Input: nums = [1, 2, 3, 4, 5, 6], target = 8

            Output: [1, 5]

            Explanation:

            nums[1] + nums[5] = 2 + 6 = 8
*/

// Case 1: Not sorted input:
vector<int> twoSumNonSorted(vector<int>& nums, int target) {
    unordered_map<int, int> seen;
    for (int i=0 ; i<nums.size() ; i++) {
        int sum = target - nums[i];

        if (seen.find(sum) != seen .end()) {
            return {seen[sum], i};
        }
        seen[nums[i]] = i;
    }
    return {-1, -1};
}

// Case 2: Sorted input:
vector<int> twoSumSorted(vector<int>& nums, int target) {
    int i = 0, j = nums.size() - 1;
    while (i < j) {
        int sum = nums[i] + nums[j];

        if (sum == target) 
            return {i, j};
        else if (sum > target) 
            j--;
        else 
            i++;
    }
    return {-1, -1};
}

void printArray(const vector<int> &arr) {
    for (const auto& i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> input_1 = {1, 6, 2, 10, 3};
    vector<int> input_2 = {1, 2, 3, 4, 5, 6};

    cout << "Two Sum Non Sorted: " << endl;
    cout << "Input Array: " << endl;
    printArray(input_1);
    cout << "Ouput Array: " << endl;
    vector<int> res = twoSumNonSorted(input_1, 7);
    printArray(res);

    cout << "Two Sum Sorted: " << endl;
    cout << "Input Array: " << endl;
    printArray(input_2);
    cout << "Ouput Array: " << endl;
    printArray(twoSumSorted(input_2, 8));

    return 0;
}