#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int> &arr) {
    int n = arr.size();
    vector<int> res(n, 0);
    int posIndex=0, negIndex=1;

    for (int i=0 ; i<n ; i++) {
        if (arr[i] > 0) {
            res[posIndex] = arr[i];
            posIndex+=2;
        }
        else {
            res[negIndex] = arr[i];
            negIndex += 2;
        }
    }
    return res;
}

int main() {
    vector<int> arr = {2, 4, 6, -1, 2, -3, -4, -5};
    vector<int> res = rearrangeArray(arr);
    for (const auto& val: res) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}