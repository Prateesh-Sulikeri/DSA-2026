#include <bits/stdc++.h>
using namespace std;

bool isValidAnagram(string s, string t) {
    if (s.length() != t.length()) return false;

    vector<int> arr(26, 0);
    for (int i=0 ; i<s.length() ; i++) {
        arr[s[i] - 'a'] += 1;
        arr[t[i] - 'a'] -= 1;
    }

    for (const int& i : arr) {
        if (i != 0) return false;
    }
    return true;

    /*
    alternate solution:
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
    */
}

int main() {
    string s = "rat", t = "tar";
    cout << (isValidAnagram(s, t) ? "true" : "false");
    return 0;
}