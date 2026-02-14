#include <bits/stdc++.h>
using namespace std;

// This method cannot be used for -ve nums

void printArray(vector<int> &arr) {
    for (const auto &val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

// solving via hash array
int countOfKey(vector<int> &arr, int key) {
    int n = arr.size();
    int maxElem = INT_MIN;
    for(int i=0 ; i<n ; i++) {
        maxElem = max(maxElem, arr[i]);
    }
    vector<int> hashArr(maxElem+1, 0);
    for(int i=0 ; i<n ; i++) {
        hashArr[arr[i]] += 1;
    }
    printArray(hashArr);
    return hashArr[key];
}

int main() {
    vector<int> arr = {6, 5, 4, 6, 6, 2, 1};
    int key = 6;
    int res = countOfKey(arr, key);
    cout << res << endl;
    return 0;
}