#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> nums) {
    int n = nums.size();
    vector<int> freq(n+1, 0);
    vector<int> res(2);
    for (int i=0 ; i<n ; i++) {
        freq[nums[i]]++;
    }
    for (int i=1 ; i<=n ; i++) {
        if (freq[i] == 2) res[0] = i;
        if (freq[i] == 0) res[1] = i;
    }
    return res;
}

int main() {
    vector<int> arr = {3, 5, 4, 1, 1};
    vector<int> res = findMissingRepeatingNumbers(arr);
    cout << "Repeating number: " << res[0] << " Missing number: " << res[1] << endl;
    return 0;
}