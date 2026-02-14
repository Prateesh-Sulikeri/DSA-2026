#include <bits/stdc++.h>
using namespace std;

int maxFreqElem(vector<int> &arr) {
    int maxFreq = 0;
    int result = INT_MIN;
    unordered_map<int, int> freqMap;

    for (int i : arr) {
        freqMap[i]++;

        if (freqMap[i] > maxFreq) {
            maxFreq = freqMap[i];
            result = i;
        }

        else if (freqMap[i] == maxFreq && i < result) {
            result = i;
        }
    }
    return result;
}

int main() {
    vector<int> arr = {10, 12, 64, 32, 32, 12, 18, 10, -32, 12, 64, 32, 0, -12, -128};

    cout << "Element with the highest freq is: " << maxFreqElem(arr);
    return 0;
}