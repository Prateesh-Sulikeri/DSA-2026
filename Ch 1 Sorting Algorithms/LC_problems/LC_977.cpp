#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {6, 1, 18, 22, -12, 0};
    for(int i=0 ; i<arr.size() ; i++) {
        arr[i] = arr[i] * arr[i];
    }
    sort(arr.begin(), arr.end());

    for(const auto &val : arr) {
        cout << val << " ";
    }
    return 0;
}