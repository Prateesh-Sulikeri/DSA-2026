#include <bits/stdc++.h>
using namespace std;

vector<int> leadersOfArray(vector<int> &arr) {
    int n = arr.size();
    int max = arr[n-1];
    vector<int> leaders;
    leaders.push_back(max);
    int i = n-2;
    while (i>=0) {
        if (arr[i] > max) {
            max = arr[i];
            leaders.push_back(arr[i]);
        }
        i--;
    }

    reverse(leaders.begin(), leaders.end());
    return leaders;
}

int main() {
    vector<int> arr = {1, 2, 5, 3,1,2};
    cout << "Leaders in given array are: " << endl;
    vector<int> res = leadersOfArray(arr);
    for (const auto& val: res) {
        cout << val << " " ;
    }
    cout << endl;
    return 0;
}