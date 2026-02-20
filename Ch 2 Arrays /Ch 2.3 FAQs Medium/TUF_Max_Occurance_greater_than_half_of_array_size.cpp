#include <bits/stdc++.h>
using namespace std;

int maxOccuranceGreaterThanHalf(vector<int> &arr) {
    int n = arr.size();
    int maxElem;
    int count = 0;

    for (int i=0 ; i<n ; i++) {
        if (count == 0) {
            count = 1;
            maxElem = arr[i];
        }
        else if (maxElem == arr[i]) 
            count++;
        else 
            count--;
    }

    int count1 = 0;
    for (int i=0 ; i<n ; i++) {
        if (arr[i] == maxElem) count1++;
    }

    if (count1 > (n/2)) return maxElem;
    return -1;
}

int main() {
    vector<int> arr = {1, 21, 1, 1, 1, 1, 0, 8};
    cout << "Max Elem > n/2: " << maxOccuranceGreaterThanHalf(arr);
    return 0;
}