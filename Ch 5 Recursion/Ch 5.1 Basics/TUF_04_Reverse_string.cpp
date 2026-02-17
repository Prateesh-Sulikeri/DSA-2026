#include <bits/stdc++.h>
using namespace std;

void reverse(vector<char> &s, int left, int right) {
    if (left >= right) return;

    char temp = s[left];
    s[left] = s[right];
    s[right] = temp;

    reverse(s, left+1, right-1);
}

vector<char> revStr(vector<char> &s) {
    int left = 0;
    int right = s.size() - 1;
    reverse(s, left, right);
    return s; 
}

int main() {
    vector<char> s = {'a', 'b', 'c'};
    vector<char> res = revStr(s);
    for (const auto &val : res) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}