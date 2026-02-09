//Find Second Smallest and Second Largest Element in an array
// Example: 
/*
Input:
 [1, 2, 4, 7, 7, 5]  
Output:
  
Second Smallest : 2  
Second Largest : 5  
*/

#include <bits/stdc++.h>
using namespace std;

// BruteForce: Time Complexity: O(n log n) | Space Complexity: O(n)
void bruteForceSol(vector<int> &arr) {
    vector<int> temp = arr;
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    int n = temp.size();
    if(n < 2) {
        return;
    }
    cout << "Second Smallest Element in the Array is: " << temp[1] << endl;
    cout << "Second Largest Element in the Array is: " << temp[n-2] << endl;
}

// BetterSolution: Time Complexity: O(n) | Space Complexity: O(1)
void betterSol(vector<int> &arr) {
    int n = arr.size();
    int min_elem = INT_MAX, second_min = INT_MAX;
    int max_elem = INT_MIN, second_max = INT_MIN;
    for (int i=0 ; i<n ; i++) {
        min_elem=min(min_elem, arr[i]);
        max_elem=max(max_elem, arr[i]);
    }
    for (int i=0 ; i<n ; i++) {
        if (arr[i] < second_min && arr[i] != min_elem) {
            second_min = arr[i];
        }
        if (arr[i] > second_max && arr[i] != max_elem) {
            second_max = arr[i];
        }
    }
    cout << "Second Smallest elemt is: " << second_min << endl;
    cout << "Second Largest elemt is: " << second_max << endl;
}

int secondSmallest(vector<int> &arr, int n) {
    int min_elem = INT_MAX;
    int second_min = INT_MAX;

    for (int i=0 ; i<n ; i++) {
        if(arr[i] < min_elem) {
            second_min = min_elem;
            min_elem = arr[i];
        }
        else if(arr[i] < second_min && arr[i] != min_elem) {
            second_min = arr[i];
        }
    }
    return second_min;
}

int secondLargest(vector<int> &arr, int n) {
    int max_elem = INT_MIN;
    int second_max = INT_MIN;

    for (int i=0 ; i<n ; i++) {
        if (arr[i] > max_elem) {
            second_max = max_elem;
            max_elem = arr[i];
        }
        else if (arr[i] > second_max && arr[i] != max_elem) {
            second_max = arr[i];
        }
    }
    return second_max;
}
// OptimalSolution: Time Complexity: O(n) | Space Complexity: O(1)
void optimalSol(vector<int> &arr) {
    int n = arr.size();
    cout << "The Second Smallest elemt in the Array is: " << secondSmallest(arr, n) << endl;
    cout << "The Second Largest element in the Array is: " << secondLargest(arr, n) << endl;
}

int main() {
    vector<int> arr = {1, 2, 4, 7, 7, 5};
    if (arr.size() < 2) {
        return -1;
    }
    cout << "Brute Force Soltuion: " << endl;
    bruteForceSol(arr);

    cout << endl;
    
    cout << "Better Solution: " << endl;
    betterSol(arr);
    
    cout << endl;

    cout << "Optimal Solution: " << endl;
    optimalSol(arr);

    cout << endl;

    return 0;
}