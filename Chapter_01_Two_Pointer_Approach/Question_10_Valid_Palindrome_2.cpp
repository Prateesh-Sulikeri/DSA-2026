#include <bits/stdc++.h>
using namespace std;

/*
    Question 10: Valid Palindrome II
    link: https://leetcode.com/problems/valid-palindrome-ii/description/

    Problem Statement: Given a string s, return true if the s can be palindrome after deleting at most one character from it.
*/

bool isPalindrome(std::string& s, int left, int right) {
    while(left<right) {
        if (s[left++] != s[right--]) return false;
    }
    return true;
}


bool validPalindrome(string s) {
    string temp = s;
    reverse(s.begin(), s.end());
    if (s == temp) 
        return true;

    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        if (s[left] == s[right]) {
            left++;
            right--;
        }
        else {
            return isPalindrome(s, left+1, right) || isPalindrome(s, left, right-1);
        }
    }

    return true;
}


int main() {
    cout << validPalindrome("abc");

    return 0;
}