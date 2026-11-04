#include <bits/stdc++.h>
using namespace std;

/*
    Question no 2: Container with most water:
    link: https://leetcode.com/problems/container-with-most-water/

    Problem Statement: You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
        Find two lines that together with the x-axis form a container, such that the container contains the most water. Return the maximum amount of water a container can store. Notice that you may not slant the container.
*/

int maxArea(vector<int>& height) {
    int maxArea = INT_MIN;
    int n = height.size();
    int start = 0, end = n-1;

    while (start < end) {
        int length = end - start;
        int breadth = min(height[start], height[end]);
        
        int area = length * breadth;

        maxArea = max(maxArea, area);
        if (height[start] < height[end]) {
            start++;
        }
        else {
            end--;
        }
    }
    return (maxArea == INT_MIN) ? 0 : maxArea;
}

int main() {
    vector<int> input = {};
    cout << "Max possible water in a container in the given array is: " << maxArea(input);
    return 0;
}