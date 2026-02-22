/*
vector<int> twoSum(vector<int>& nums, int target) {
        // nums = [1, 6, 2, 10, 3], target = 7
        // 7 -> 1 + 6 
        // target = arr[i] + x -> x = target - arr[i]
        // visitedMap (seenMap) -> if an element is seen its here
        // if not present already add the element with its index 
        

        int  n = nums.size();
        unordered_map<int, int> seen;

        for (int i=0 ; i<n ; i++) {
            int x = target - nums[i];

            if (seen.count(x))
                return {seen[x], i};
            
            if (!seen.count(nums[i]))
                seen[nums[i]] = i;
        }
        return {-1, -1};
    }

    complete with comments and main the above 2 sum problem 
*/
#include <bits/stdc++.h>
using namespace std;

// fix indentation and add comments to the below code snippet for 2 sum problem:
vector<int> twoSum(vector<int>& nums, int target) { 

    int  n = nums.size();
    unordered_map<int, int> seen;

    for (int i=0 ; i<n ; i++) {
        int x = target - nums[i];

        if (seen.count(x))
            return {seen[x], i};
            
        if (!seen.count(nums[i]))
            seen[nums[i]] = i;
    }
    return {-1, -1};
}
int main() {    
    vector<int> nums = {1, 6, 2, 10, 3};
    int target = 7;

    vector<int> res = twoSum(nums, target);
    cout << "Indices of the two numbers that add up to " << target << " are: " << res[0] << " and " << res[1] << endl;
    return 0;
}