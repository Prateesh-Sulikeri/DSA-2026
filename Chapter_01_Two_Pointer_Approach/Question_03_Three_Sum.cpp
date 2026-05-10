#include <bits/stdc++.h>
using namespace std;

/*
    Question no 3: Three Sum:
    link: https://www.hellointerview.com/learn/code/two-pointers/3-sum

    Problem Statement: Given an input integer array nums, write a function to find all unique triplets [nums[i], nums[j], nums[k]] such that i, j, and k are distinct indices, and the sum of nums[i], nums[j], and nums[k] equals zero. Ensure that the resulting list does not contain any duplicate triplets.
*/

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;

    for (int i=0 ; i<n-2 ; i++) {
        if (i>0 && nums[i] == nums[i-1]) continue;
        int j = i+1;
        int k = n-1;

        while (j<k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0) {
                res.push_back({nums[i], nums[j], nums[k]});

                while (j<k && nums[j] == nums[j+1]) j++;
                while (k<k && nums[k] == nums[k-1]) k--;

                j++;
                k--;
            }
            else if (sum > 0) {
                k--;
            }
            else {
                j++;
            }
        }
    }
    return res;
}

int main() {
    vector<int> input = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = threeSum(input);      
    cout << "Unique triplets that sum up to zero are: " << endl;
    for (const auto& triplet : res) {
        cout << "[";
        for (size_t i = 0; i < triplet.size(); i++) {
            cout << triplet[i];
            if (i < triplet.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    return 0;
}