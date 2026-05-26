#include <bits/stdc++.h>
using namespace std;

/*
    Question: Employee free time
    link: https://www.hellointerview.com/learn/code/intervals/employee-free-time
    Problem Statement:Write a function to find the common free time for all employees from a list called schedule. Each employee's schedule is represented by a list of non-overlapping intervals sorted by start times. The function should return a list of finite, non-zero length intervals where all employees are free, also sorted in order.
*/

vector<vector<int>> empFreeTime(vector<vector<vector<int>>> schedule) {
    vector<vector<int>> intervals; 

    for (const auto& emp : schedule) {
        for (const auto& interval : emp) {
            intervals.push_back(interval);
        }
    }

    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;

    for (const auto& interval : intervals) {
        if (merged.empty() || interval[0] > merged.back()[1]) {
            merged.push_back(interval);
        }
        else {
            merged.back()[1] = max(merged.back()[1], interval[1]);
        }
    }

    vector<vector<int>> freeTime;

    for (int i=0 ; i<merged.size() - 1 ; i++) {
        int start = merged[i][1];
        int end = merged[i+1][0];

        if (start < end) {
            freeTime.push_back({start, end});
        }
    }
    return freeTime;
}

int main() {
    vector<vector<vector<int>>> input =  {
        {{1,3}, {6,7}, {9,12}},
        {{2,4}},
        {{2,5}, {13,16}},
        {{8,10}},
        {{11,13}},
        {{17,20}},
        {{0,1}, {21,24}}
    };

    cout << "Free Time left between emps is: " << endl;
    vector<vector<int>> res = empFreeTime(input);

    cout << "[";
    for (int i=0 ; i<res.size() ; i++) {
        cout << "[" << res[i][0] << ", " << res[i][1] << "]";
        if (i != res.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    
    return 0;
}