#include <bits/stdc++.h>
using namespace std;

vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
    /*
        Part 1: list of indices of occurance of x : 
        indices 
        for -> if cur == x -> push i into indices 

        Part 2: the res prep from queries: 
        res
        for queries 
            -> if q > indcies.size -> push -1 into res 
            -> push indices[q - 1] into res 
    */

    vector<int> indices;
    for (int i=0 ; i<nums.size() ; i++) {
        if (nums[i] == x) {
            indices.push_back(i);
        }
    }

    vector<int> res;
    for (int q: queries) {
        if (q > indices.size()) {
            res.push_back(-1);
        }
        else {
            res.push_back(indices[q-1]);
        }
    }
    return res;
}

void printVector(vector<int> &arr) {
    for(const auto &val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums = {1,3,1,7};
    vector<int> queries = {1,3,2,4};
    int x = 1;
    
    cout << "Result: " << endl;
    vector<int> res = occurrencesOfElement(nums, queries, x);
    printVector(res);
    return 0;
}