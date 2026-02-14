#include <bits/stdc++.h>
using namespace std;

int secondHighestFreqElem(vector<int> &arr) {
    unordered_map<int, int> freqMap;
    for (int i: arr) freqMap[i]++;

    int mostFreqVal = 0, secMostFreqVal = 0;
    int mostFreqNum = INT_MIN, secMostFreqNum = INT_MIN;

    for (auto& [n, f] : freqMap) {
        if (f > mostFreqVal) {
            secMostFreqVal = mostFreqVal;
            secMostFreqNum = mostFreqNum;
            mostFreqNum = n;
            mostFreqVal = f;
        }
        else if (f == mostFreqVal) {
            mostFreqNum = min(mostFreqNum, n);
        }
        else if (f > secMostFreqVal) { 
            secMostFreqNum = n;
            secMostFreqVal = f;
        }
        else if (f == secMostFreqVal) {
            secMostFreqNum = min(secMostFreqNum, n);
        }
    }
    return secMostFreqVal ? secMostFreqNum : -1;
}

int main() {
    vector<int> arr = {10, 12, 64, 32, 32, 12, 18, 10, -32, 12, 64, 32, 0, -12, -128};

    cout << "Element with the highest freq is: " << secondHighestFreqElem(arr);
    return 0;
}