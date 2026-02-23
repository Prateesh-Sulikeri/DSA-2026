#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &arr, int target) {
    int n = arr.size();
    sort(arr.begin(), arr.end());

    vector<vector<int>> res;

    for (int i=0 ; i<n ; i++) {
        if (i>0 && arr[i] == arr[i-1]) continue;
        for (int j=i+1 ; j<n ; j++) {
            if (j > (i+1) && arr[j] == arr[j-1]) continue;

            int k = j+1;
            int l = n-1;

            while (k < l) {
                long long sum = arr[i] + arr[j] + arr[k] + arr[l];

                if (sum < target) {
                    k++;
                }

                else if (sum > target) {
                    l--;
                }

                else {
                    res.push_back({arr[i], arr[j], arr[k], arr[l]});
                    k++;
                    l--;

                    while (l < k && arr[k] == arr[k-1]) k++;
                    while (l < k && arr[l] == arr[l+1]) l--; 
                }
            }
        }
    }
    return res;
}

void printMatrix(vector<vector<int>> &mat) {
    for (auto const &row : mat) { 
        for (auto const &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1, -2, 3, 5, 7, 9};
    int target = 7;

    cout << "All possible 4 sum combinations are: " << endl;
    vector<vector<int>> res = fourSum(arr, target);
    printMatrix(res);
    return 0;
}