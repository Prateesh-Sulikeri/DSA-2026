#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &arr) {
    for (const auto &val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

// Approach for lower case alphabet vector:
int lowerCharFreq(vector<char> &arr, char ch) {
    int n = arr.size();
    vector<int> freqArr(26, 0);

    for (int i = 0; i < n; i++) {
        freqArr[arr[i] - 'a'] += 1;
    }
    printVector(freqArr);
    return freqArr[ch - 'a'];
}

// Approach for upper or lowercase alphabe vector:
int charFreq(vector<char> &arr, char ch) {
    int n = arr.size();
    vector<int> freqArr(52, 0);

    for (int i=0 ; i<n ; i++) {
        if (arr[i] >= 'a' && arr[i] <= 'z') {
            freqArr[arr[i] - 'a'] += 1;
        }
        else if (arr[i] >= 'A' && arr[i] <= 'Z') {
            freqArr[arr[i] - 'A' + 26] += 1;
        }
    }
    printVector(freqArr);
    if (ch >= 'a' && ch <= 'z') {
        return freqArr[ch - 'a'];
    }
    else if (ch >= 'A' && ch <= 'Z') {
        return freqArr[ch - 'A' + 26];
    }
    return 0;
}

int main() {
    vector<char> arr = {'a', 'b', 'b', 'a', 'c', 'd', 'e', 'z', 'd', 'h', 'a', 'l'};
    char key = 'a';
    int res = lowerCharFreq(arr, key);
    cout << "The Freq of " << key << " is " << res;

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
    
        char key2 = 'B';
        int res2 = charFreq(arr2, key2);
    cout << "Mixed Vector Freq of " << key2 << " is " << res2;

    return 0;
}