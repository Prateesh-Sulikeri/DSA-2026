#include <bits/stdc++.h>
using namespace std;

/*
    Question 02: Insert Interval
    link: https://leetcode.com/problems/insert-interval/description/

    Problem Statement: You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
    Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
    Return intervals after the insertion.
*/

vector<vector<int>> insert(vector<vector<int>> intervals, vector<int> newInterval) {
    int i = 0;
    int n = intervals.size();
    vector<vector<int>> merged;

    while (i<n && intervals[i][1] < newInterval[0]) {
        merged.push_back(intervals[i]);
        i++;
    }

    while (i<n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(intervals[i][0], newInterval[0]);
        newInterval[1] = min(intervals[i][1], newInterval[1]);
        i++;
    }

    merged.push_back(newInterval);

    for (int j=i ; j<n ; j++) {
        merged.push_back(intervals[j]);
    }

    return merged;
}

int main() {
    
    vector<vector<int>> input = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> newInterval = {4, 8};
    vector<vector<int>> res = insert(input, newInterval);

    cout << "Merged Intervals are:" << endl;
    cout << "[";
    for (int i = 0; i < res.size(); i++) {
        cout << "[" << res[i][0] << ", " << res[i][1] << "]";

        if (i != res.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    return 0;
}