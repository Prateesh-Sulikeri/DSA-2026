#include <bits/stdc++.h>
using namespace std;

/*
    Question 11: Boats to save people
    link: https://leetcode.com/problems/boats-to-save-people/description/

    Problem Statement: You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.
    Return the minimum number of boats to carry every given person.

*/

int boatsToSavePeople(vector<int>& people, int limit) {
    sort(people.begin(), people.end());

    int left = 0, right = people.size() - 1;
    int noOfBoats = 0;

    while (left <= right) {
        if (people[left] + people[right] <= limit) {
            noOfBoats++;
            left++;
            right--;
        }
        else {
            noOfBoats++;
            right--;
        }
    }
    return noOfBoats;
}

int main() {
    
    vector<int> input = {3,5,3,4};
    int limit = 5;

    cout << "No of boats required to save people of given weights is: " << boatsToSavePeople(input, limit) << endl;

    return 0;
}