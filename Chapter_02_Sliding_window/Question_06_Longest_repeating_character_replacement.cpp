#include <bits/stdc++.h>
using namespace std;

/*
    Question 6: Longest repeating character replacement
    link: https://leetcode.com/problems/longest-repeating-character-replacement/description/

    Problem Statement: You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.
*/

/*
    Intuition:

    1. AABAABB
       s
       e
     
    freqMap

    for end (0->n)
        freqMap[s[e]]++

        maxFreq

        if (windowSize - maxfreq > k)
            shorten the window
        
        maxLen 
*/

int characterReplacement(string s, int k) {
    unordered_map<int, int> charCount;
    int max_len = 0;
    int max_freq = 0;
    int start = 0;

    for (int end = 0 ; end < s.length() ; end++) {
        charCount[s[end]]++;

        max_freq = max(max_freq, charCount[s[end]]);

        if ((end - start + 1) - max_freq > k) {
            charCount[s[start]]--;

            if (charCount[s[start]] == 0)
                charCount.erase(s[start]);
            
            start++;
        }

        max_len = max(max_len, (end - start + 1));
    }
    return max_len;
}

int main() {
    std::string input = "AABABBA";
    int k = 1;
    
    cout << "Longest Repeating Character Replacement length is: " << characterReplacement(input, k) << endl;

    return 0;
}