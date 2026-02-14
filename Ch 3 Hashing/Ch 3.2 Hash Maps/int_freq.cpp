#include <bits/stdc++.h>
using namespace std;

int charFreq(vector<int> &arr, int key) {
    int n = arr.size();
    unordered_map<int, int> freqMap;
    for(int i=0 ; i<n ; i++) {
        freqMap[arr[i]]++;
    }
    if (freqMap.find(key) != freqMap.end()) 
        return freqMap[key];
    return 0;
}

int main() {
    vector<int> arr = {10, 12, 64, 32, 32, 12, 18, 10, -32, 12, 64, 32, 0, -12, -128};
    int key = 11231231;
    cout << "No of times the key: " << key << " occures in the arr is: " << charFreq(arr, key);
    
    return 0;
}