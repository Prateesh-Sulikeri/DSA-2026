#include <bits/stdc++.h>
using namespace std;

/*
    Question 03: Non overlapping intervals
    link: https://leetcode.com/problems/non-overlapping-intervals/description/

    Problem Statement: Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
*/

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(),
        [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        }
    );

    int counter = 0;
    int prevEnd = intervals[0][1];

    for (int i=1 ; i<intervals.size() ; i++) {
        if (intervals[i][0] < prevEnd) {
            counter++;
        }
        else {
            prevEnd = intervals[i][1];
        }
    }
    return counter;
}

int main() {
    
    vector<vector<int>> input = {{1,2},{1,2},{1,2}};
    // vector<vector<int>> input = {{1,2},{1,2},{1,2}};
    cout << "Count of intervals to be erased to have no overlaps: " << eraseOverlapIntervals(input);

    return 0;
}