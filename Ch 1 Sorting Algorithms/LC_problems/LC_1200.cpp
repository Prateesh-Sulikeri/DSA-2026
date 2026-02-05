#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> LC_1200(vector<int> &arr) {
    int n = arr.size();
    for (int i=0 ; i<n-1 ; i++) {
        for (int j=0 ; j<n-i-1 ; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
    int min_diff = INT_MAX;
    for(int i=0 ; i<n-1 ; i++) {
        min_diff = min(min_diff, arr[i+1] - arr[i]);
    }
    vector<vector<int>> res;
    for (int i=0 ; i<n-1 ; i++) {
        if(arr[i+1] - arr[i] == min_diff) {
            res.push_back({arr[i], arr[i+1]});
        }
    }
    return res;
}


void print(const std::vector<std::vector<int>>& arr) {
    std::cout << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << "[";
        for (size_t j = 0; j < arr[i].size(); ++j) {
            std::cout << arr[i][j];
            if (j + 1 < arr[i].size()) std::cout << ",";
        }
        std::cout << "]";
        if (i + 1 < arr.size()) std::cout << ",";
    }
    std::cout << "]";
}

int main() {
    vector<int> arr = {4,2,1,3};
    cout << "Result: " << endl;
    vector<vector<int>> res = LC_1200(arr);
    print(res);
    return 0;
}