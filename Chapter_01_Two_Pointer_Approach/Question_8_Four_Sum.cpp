#include <bits/stdc++.h>
using namespace std;

/*
    Question 8: 4 Sum
    link: https://takeuforward.org/plus/dsa/problems/4-sum

    Problem Statement: Given an integer array nums and an integer target. Return all quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

    a, b, c, d are all distinct valid indices of nums.

    nums[a] + nums[b] + nums[c] + nums[d] == target.

    Notice that the solution set must not contain duplicate quadruplets. One element can be a part of multiple quadruplets. The output and the quadruplets can be returned in any order.
*/

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int n = nums.size();

    for (int i=0 ; i<n ; i++) {
        if (i>0 && nums[i] == nums[i-1]) continue;

        for (int j=i+1 ; j<n ; j++) {
            if (j>i+1 && nums[j] == nums[j-1]) continue;

            int k = j+1;
            int l = n-1;

            while (k<l) {
                long long sum = nums[i] + nums[j] + nums[k] + nums[l];

                if (sum == target) {
                    res.push_back({nums[i], nums[j], nums[k], nums[l]});

                    while(k<l && nums[k] == nums[k+1]) k++;
                    while(k<l && nums[l] == nums[l-1]) l--;

                    k++;
                    l--;
                }
                else if (sum > target) 
                    l--;
                else    
                    k++;
            }
        }
    }
    return res;
}

int main() {
    vector<int> input = {1, -2, 3, 5, 7, 9};
    int target = 7;

    vector<vector<int>> res = fourSum(input, target);

    for (const auto& vec: res) {
        for (const auto& i: vec) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}