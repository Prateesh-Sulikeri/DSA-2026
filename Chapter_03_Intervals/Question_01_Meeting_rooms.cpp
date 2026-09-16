#include <bits/stdc++.h>
using namespace std;

/*
    Question 01: Meeting Rooms
    Link: https://takeuforward.org/plus/dsa/problems/meeting-rooms

    Problem statement: Given an array of meeting time intervals where intervals[i] = [starti, endi].
    Determine if a person could attend all meetings.
*/

bool canAttendMeetings(vector<vector<int>>& intervals) {
    if (intervals.empty())
        return true;

    sort(intervals.begin(), intervals.end());

    for (int i=1 ; i<intervals.size() ; i++) {
        if (intervals[i][0] < intervals[i-1][1])
            return false;
    }
    return true;
}

int main() {
    
    vector<vector<int>> input = {{2, 7}, {7, 9}, {10, 14}, {15, 18}};
    cout << "Can All meetings be atteneded? " << (canAttendMeetings(input) ? "True" : "False") << endl;

    return 0;
}