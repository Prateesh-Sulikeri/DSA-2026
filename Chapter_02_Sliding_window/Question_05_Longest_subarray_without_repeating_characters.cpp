#include <bits/stdc++.h>
using namespace std;

/*
    Question 5: Longest Substring Without Repeating Characters
    link: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

    Problem Statement: Given a string s, find the length of the longest substring without duplicate characters.
*/

int lengthOfLongestSubstring(string s) {
    unordered_map<int, int> freqMap;
    int max_len = INT_MIN;
    int start = 0;

    for (int end = 0  ; end < s.length() ; end++) {
        freqMap[s[end]]++;
        int cur_len = end - start + 1;
        
        if (freqMap.size() != cur_len) {
            freqMap[s[start]]--;

            if (freqMap[s[start]] == 0) 
                freqMap.erase(s[start]);

            start++;
        }
        else {
            max_len = max(max_len, cur_len);
        }
    }
    return max_len == INT_MIN ? 0 : max_len;
}

int main() {
    std::string s = "abcabcbb";
    cout << "Longest substring without repeating chars is: " << lengthOfLongestSubstring(s) << endl;

    return 0;
}