#include <bits/stdc++.h>
using namespace std;

int idx = 0;
int sum = 0;
int arraySum(vector<int> &arr) {
    if (idx == arr.size()) return 0;

    sum = sum + arr[idx++];
    arraySum(arr);
    return sum;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int res = arraySum(arr);
    cout << res;
    return 0;
}