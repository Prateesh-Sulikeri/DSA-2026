#include <bits/stdc++.h>
using namespace std;

/*
    Question No 1: Maximum Sum of Subarrays of Size K
    link: https://www.hellointerview.com/learn/code/sliding-window/maximum-sum-of-subarrays-of-size-k

    Problem Statement: Given an array of integers nums and an integer k, find the maximum sum of any contiguous subarray of size k.
*/

int maxSum(vector<int>& arr, int k) {
    int maxSum = INT_MIN;
    int windowSum = 0;
    int start = 0;
    
    for (int end = 0 ; end < arr.size() ; end++) {
        windowSum += arr[end];

        if (end - start + 1 == k) {
            maxSum = max(maxSum, windowSum);
            windowSum -= arr[start];
            start++;
        }
    }
    return maxSum;
}

int main() {
    
    vector<int> input = {2, 1, 5, 1, 3, 2};
    int k = 3;

    cout << "Max subarray sum for given array with window size: " << k << " is: " << maxSum(input, k) << endl;
    return 0;
}