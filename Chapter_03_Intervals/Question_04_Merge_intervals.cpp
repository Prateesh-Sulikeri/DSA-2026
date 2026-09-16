#include <bits/stdc++.h>
using namespace std;

/*

    Question 04: Merge Intervals
    link: https://leetcode.com/problems/merge-intervals/
    Problem Statement: Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
*/

vector<vector<int>> mergeIntervals(vector<vector<int>> intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    for (const auto& interval : intervals) {
        if (merged.empty() || interval[0] > merged.back()[1]) {
            merged.push_back(interval);
        }
        else {
            merged.back()[1] = max(interval[1], merged.back()[1]);
        }
    }
    return merged;
} 

int main() {
    vector<vector<int>> input =  {{1,3},{2,6},{8,10},{15,18}};   

    cout << "Merged intervals are: " << endl;
    vector<vector<int>> res = mergeIntervals(input);
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