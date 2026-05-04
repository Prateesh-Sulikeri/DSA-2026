#include <bits/stdc++.h>
using namespace std;

/*
    Question 3: Maximum Sum of Distinct Subarrays With Length K
    link: https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/

    Problem Statement: You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

The length of the subarray is k, and
All the elements of the subarray are distinct.
Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.

A subarray is a contiguous non-empty sequence of elements within an array.
*/

long long maximumSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> freqMap;

    long long maxSum = LLONG_MIN;
    long long windowSum = 0;
    int start = 0;

    for (int end = 0 ; end < nums.size() ; end++) {
        windowSum += nums[end];
        freqMap[nums[end]]++;

        if (end - start + 1 == k) {
            if (freqMap.size() == k) 
                maxSum = max(maxSum, windowSum);
            
            windowSum -= nums[start];
            freqMap[nums[start]]--;

            if (freqMap[nums[start]] == 0) 
                freqMap.erase(nums[start]);
        
            start++;
        }
    }
    return maxSum == LLONG_MIN ? 0 : maxSum;
}

int main() {
    vector<int> input = {1,5,4,2,9,9,9};
    int k = 3;

    cout << "Max Points possible for Subarray with distint elements is: " << k << " is: " << maximumSubarraySum(input, k) << endl;
    return 0;
}