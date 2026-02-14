#include <bits/stdc++.h>
using namespace std;

int sumHighestAndLowestFrequency(vector<int>& nums) {
    int maxFreq = INT_MIN, minFreq = INT_MAX;
    unordered_map<int, int> freqMap;
    for (int i: nums) freqMap[i]++;

    for (auto& [n, f]: freqMap) {
        maxFreq = max(maxFreq, f);
        minFreq = min(minFreq, f);
    }
    return maxFreq + minFreq;
}

int main() {
    vector<int> arr = {10, 12, 64, 32, 32, 12, 18, 10, -32, 12, 64, 32, 0, -12, -128};
    cout << "Sum of highest and lowest freq in given array: " << sumHighestAndLowestFrequency(arr);
    return 0;
}