#include <bits/stdc++.h>
using namespace std;

/*
    Question no 4: Triangle Numbers:
    link: https://leetcode.com/problems/valid-triangle-number/

    Problem Statement: Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
*/

int validTriangleNums(vector<int>& arr) {
    int n = arr.size();
    int count = 0;  
    sort(arr.begin(), arr.end());

    for (int i=n-1 ; i>=2 ; i--) {
        int j = 0;
        int k = i-1;

        while (j<k) {
            if (arr[j] + arr[k] > arr[i]) {
                count += k - j;
                k--;
            }
            else 
                j++;
        }
    } 
    return count;
}

vector<vector<int>> validTriangleNums(vector<int>& arr, int n) {
    vector<vector<int>> res;
    sort(arr.begin(), arr.end());
    
    for (int i=n-1 ; i>=2 ; i--) {
        int j = 0;
        int k = i-1;
        
        while(j<k) {
            if (arr[j] + arr[k] > arr[i]) {
                for (int x=j ; x<k ; x++) 
                    res.push_back({arr[x], arr[k], arr[i]});
                k--;
            }
            else   
                j++;
        }
    }
    return res;
}

int main() {
    vector<int> input = {11,4,9,6,15,18};
    cout << "Count of number of valid pairs that would form a triangle are: " << validTriangleNums(input) << endl; 

    cout << "All possible pairs for the given input would be: " << endl;
    vector<vector<int>> res = validTriangleNums(input, input.size());

    cout << "[" << "\n";
    for (const auto& vec: res) {
        cout << "<";
        for (const auto& n : vec) {
            cout << n;
            if (n != vec.back()) cout << ", ";
        }
        cout << ">" << "\n";
    }
    cout << "]" << endl;

    return 0;
}