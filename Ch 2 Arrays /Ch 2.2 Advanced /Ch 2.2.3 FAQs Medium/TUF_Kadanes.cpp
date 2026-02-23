#include <bits/stdc++.h>
using namespace std;

int kadanes(vector<int> &arr) {
    int curSum = arr[0];
    int maxSum = arr[0];

    for (int i=1 ; i<arr.size() ; i++) {
        curSum = max(arr[i], curSum + arr[i]);
        maxSum = max(maxSum, curSum);
    }
    return maxSum;
}

int main() {
    vector<int> arr1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> arr2 = {1, 2, 3, 4, 5};
    vector<int> arr3 = {-1, -2, -3, -4, -5};

    cout << "Maximum subarray sum for arr1 is: " << kadanes(arr1) << endl;
    cout << "Maximum subarray sum for arr2 is: " << kadanes(arr2) << endl;
    cout << "Maximum subarray sum for arr3 is: " << kadanes(arr3) << endl;
    
    return 0;
}