// TUF 01: Largest Element in an Unsorted Array: 
#include <bits/stdc++.h>
using namespace std;
// Brute Force : Time Complexity: O(nlogn) | Space Complexity: O(n)
int bruteForceSol(vector<int> &arr) {
    int n = arr.size();
    vector<int> temp = arr;
    sort(temp.begin(), temp.end());
    return temp[n-1];
}

// Optmial Solution : Time Complexity O(n) | Space Complexity: O(1)
int OptimalSol(vector<int> &arr) {
    int n = arr.size();
    int max_elem = INT_MIN;
    for(int i=0 ; i<n ; i++) {
        if(arr[i] > max_elem) {
            max_elem = arr[i];
        }
    }
    return max_elem;
}

void printArray(vector<int> &arr) {
    for(const auto &val: arr) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {2, 5, 5, 1, 0, -12 };
    cout << "Original Array: " << endl;
    printArray(arr);
    
    cout << "Largest Element in the Given Array using BruteForce is: " << bruteForceSol(arr) << endl;
    cout << "Largest element in the given array using Optimal Solution is: " << OptimalSol(arr) << endl;

    return 0;
}