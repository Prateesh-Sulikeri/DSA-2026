#include <bits/stdc++.h>
using namespace std;

int charFreq(vector<char> &arr, char key) {
    int n = arr.size();
    unordered_map<char, int> freqMap; 
    for(int i=0 ; i<n ; i++) {
        freqMap[arr[i]]++;
    }
    if (freqMap.find(key) != freqMap.end()) 
        return freqMap[key];
    return 0;
}

int main() {
    vector<char> arr2 = {
        'a', 'B', 'c', 'D', 'e', 'F', 'g', 'H', 'i', 'J',
        'k', 'L', 'm', 'N', 'o', 'P', 'q', 'R', 's', 'T',
        'u', 'V', 'w', 'X', 'y', 'Z',

        'A', 'b', 'C', 'd', 'E', 'f', 'G', 'h', 'I', 'j',
        'K', 'l', 'M', 'n', 'O', 'p', 'Q', 'r', 'S', 't',
        'U', 'v', 'W', 'x', 'Y', 'z',

        'a', 'a', 'a', 'A', 'A', 'b', 'B', 'c', 'C', 'd',
        'D', 'e', 'E', 'f', 'F', 'g', 'G', 'h', 'H', 'i',
        'I', 'j', 'J', 'k', 'K', 'l', 'L', 'm', 'M', 'n',
        'N', 'o', 'O', 'p', 'P', 'q', 'Q', 'r', 'R', 's',
        'S', 't', 'T', 'u', 'U', 'v', 'V', 'w', 'W', 'x',
        'X', 'y', 'Y', 'z', 'Z'};
    
    char key = 'B';
    cout << "No of times the key: " << key << " appears in the vector is: " << charFreq(arr2, key);
    return 0;
}