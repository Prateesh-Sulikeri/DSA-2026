#include <bits/stdc++.h>
using namespace std;

vector<int> bruteForce(vector<int> &arr) {
    vector<int> res;
    int n = arr.size();
    int min = n/3;
    for (int i=0 ; i<n ; i++) {
        if (res.size() == 0 || res[0] != arr[i]) {
            int count = 0;
            for (int j=0 ; j<n ; j++) {
                if (arr[j] == arr[i]) 
                    count++;
            }
            if (count > min)
                res.push_back(arr[i]);
        }
        if (res.size() == 2) break;
    }
    return res;
}

vector<int> better(vector<int> &arr) {
    vector<int> res;
    unordered_map<int, int> freqMap;
    int n = arr.size();
    int min = n/3;
    for (int i=0 ; i<n ; i++) {
        freqMap[arr[i]]++;
        if (freqMap[arr[i]] == min) {
            res.push_back(arr[i]);
        }
    }
    return res;
}

// Optimal 
vector<int> majorityElementTwo(vector<int> &arr) {
    vector<int> res;
    int n = arr.size();
    int cnt1 = 0, cnt2 = 0;
    int el1=0, el2=0;

    for (int i=0 ; i<n ; i++) {
        if (cnt1 == 0 || arr[i] == el2) {
            cnt1++;
            el1 = arr[i];
        }
        else if (cnt2 == 0 || arr[i] == el1) {
            cnt2++;
            el2 = arr[i];
        }
        else if (el1 == arr[i]) cnt1++;
        else if (el2 == arr[i]) cnt2++;
        else {
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0, cnt2 = 0;
    for (int i=0 ; i<n ; i++) {
        if (arr[i] == el1) cnt1++;
        if (arr[i] == el2) cnt2++;
    }
    int min = n/3 + 1;
    if (cnt1 >= min) res.push_back(el1);
    if (cnt2 >= min) res.push_back(el2);
    sort(res.begin(), res.end());

    return res;
}

void printArray(vector<int> &arr) {
    for (const auto& val : arr) {
        cout << val << " ";
    }
    cout << endl;
}
int main() {
    vector<int> arr = {1, 2, 1, 1, 3, 2, 2};
    // Brute Force
    vector<int> res = bruteForce(arr);
    cout << "Majority Elements in arr appearing more than n/3 times are using Brute Force : " << endl;
    printArray(res);

    // better appraoch:
    res = better(arr);
    cout << "Majority Elements in arr appearing more than n/3 times are using Better Appraoch: " << endl;
    printArray(res);

    // Optimal approach: 
    res = majorityElementTwo(arr);
    cout << "Majority Elements in arr appearing more than n/3 times are using Optimal Appraoch: " << endl;
    printArray(res);

    return 0;
}