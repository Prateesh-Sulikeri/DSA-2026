#include <bits/stdc++.h>
using namespace std;

/*
    Question no 7: Trapping rain water:
    link: https://leetcode.com/problems/trapping-rain-water/

    Problem statement: Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining
*/

/*
            [4,2,0,3,2,5]
            
            total += min(leftMax, rightMax) - arr[i]

            prefixSum[n] -> max(prefix[i-1], arr[i])
            suffixSum[n] -> max(suffix[i+1], arr[i])

            TC: O(2N) + O(N) = O(3N)

            SC: O(N) + O(N) = O(N) -> since we store both prefix and suffix sums

            while (start < end) 
                if (height[start] < height[end])
                    if (leftMax > height[start])
                        total += leftMax - height[start]
                    else
                        leftMax = height[start]
                    start++

        */

int trap(vector<int>& height) {
    int leftMax = 0, rightMax = 0, total = 0;  
    int start = 0, end = height.size() - 1;

    while (start < end) {
        if (height[start] < height[end]) {
            if (leftMax > height[start]) 
                total += leftMax - height[start];
            else    
                leftMax = height[start];
            start++;
        }
        else {
            if (rightMax > height[end]) {
                total += rightMax - height[end];
            }
            else 
                rightMax = height[end];
            end--;
        }
    }
    return total;
}

int main() {
    
    vector<int> input = {3, 4, 1, 2, 2, 5, 1, 0, 2};
    cout << "Total rainwater than can be trapped for the given array of building heights is: " << trap(input) << endl;

    return 0;
}