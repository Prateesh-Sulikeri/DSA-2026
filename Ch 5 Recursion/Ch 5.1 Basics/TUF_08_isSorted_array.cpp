#include <bits/stdc++.h>
using namespace std;

bool helper(vector<int> &arr, int idx) {
    if (idx >= arr.size() - 1) return true;

    if (arr[idx] > arr[idx+1]) return false;
    return helper(arr, idx+1);
}   

bool isSorted(vector<int> &arr) {
    return helper(arr, 0);
}

int main() {
    // vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> arr = {2, 5, 1, 2, 3};
    cout << (isSorted ? "True" : "False") << endl;
    return 0;
}