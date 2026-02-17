#include <bits/stdc++.h>
using namespace std;

// void reverse(string &t, int left, int right) {
//     if (left >= right) return;

//     swap(t[left], t[right]);
//     cout << t << endl;
//     reverse(t, left+1, right-1);
// }

// bool checkPalindrome(string &s) {
//     string t = s;
//     int left = 0;
//     int right = s.length() - 1; 
//     reverse(t, left, right);
//     return s==t;
// }

bool isPalindrome(string &s, int left, int right) {
    if (left >= right) return true;

    if (s[left] != s[right]) return false;
    return isPalindrome(s, left+1, right-1);
}

bool checkPalindrome(string &s) {
    int left = 0;
    int right = s.size() - 1;
    return isPalindrome(s, left, right);
}

int main() {
    string s = "hannah";
    bool res = checkPalindrome(s);
    cout << (res ? "true" : "false") << endl;   
    return 0;
}