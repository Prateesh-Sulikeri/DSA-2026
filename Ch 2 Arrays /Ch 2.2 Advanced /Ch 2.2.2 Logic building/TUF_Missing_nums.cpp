#include <bits/stdc++.h>
using namespace std;

int missingNums(vector<int> &arr) {
    int n = arr.size();
    if (arr[0] != 0) return 0;
    if (arr[n-1] != n) return n;

    int first=arr[0];
    for (int i=0 ; i<n ; i++) {
        if (arr[i] == first) 
            first++;
        else 
            return first;
    }
    return first;
}

int main() {
    vector<int> arr = {0, 1, 2, 4};
    cout << "Missing Res: " << missingNums(arr); 
    return 0;
}