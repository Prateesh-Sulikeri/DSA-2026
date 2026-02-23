#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> bruteForce(vector<int> &arr) {
    set<vector<int>> st;
    int n = arr.size();
    for (int i=0 ; i<n ; i++) {
        for (int j=i+1 ; j<n ; j++) {
            for (int k=j+1 ; k<n ; k++) {
                if (arr[i] + arr[j] + arr[k] == 0) {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> betterApproach(vector<int> &arr) {
    set<vector<int>> st;

    int n = arr.size();
    for (int i=0 ; i<n ; i++) {
        set<int> hashset;
        for (int j=i+1 ; j<n ; j++) {
            int third = - (arr[i] + arr[j]);
            if (hashset.find(third) != hashset.end()) {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            } 
            hashset.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> threeSum(vector<int> &arr) {
    sort(arr.begin(), arr.end());

    int n = arr.size();

    vector<vector<int>> res; 
    for (int i=0 ; i<n-2 ; i++) {
        if (i > 0 && arr[i] == arr[i-1])
            continue;
        int j = i+1;
        int k = n-1;
        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];

            if (sum < 0) {
                j++;
            }

            else if (sum > 0) {
                k--;
            }

            else {
                res.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;

                while (j<k && arr[j] == arr[j-1]) j++;
                while (j<k && arr[k] == arr[k+1]) k--;
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
    vector<int> arr = {2, -2, 0, 3, -3, 5};

    vector<vector<int>> res = bruteForce(arr);
    cout << "Brute Force Solution result: " << endl;
    printMatrix(res);

    res = betterApproach(arr);
    cout << "Better Approach Solution result: " << endl;
    printMatrix(res);

    res = threeSum(arr);
    cout << "Optimal Solution result: " << endl;
    printMatrix(res);
    return 0;
}