#include <bits/stdc++.h>
using namespace std;

int consecutiveOnes(vector<int> &arr) {
    int maxCount = 0, count = 0;

    for (int i=0 ; i<arr.size() ; i++) {
        if (arr[i] == 1) {
            count++;
        }
        else {
            maxCount = max(maxCount, count);
            count = 0;
        }
    }
    return max(maxCount, count);
}

int main() {
    vector<int> arr = {1, 0, 0, 1, 1, 1, 0, 1, 1};
    cout << "Max consective occurance of 1s in given array is: " << consecutiveOnes(arr);
    return 0;
}