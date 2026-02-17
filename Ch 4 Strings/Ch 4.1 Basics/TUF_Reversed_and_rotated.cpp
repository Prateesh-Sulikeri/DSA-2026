#include <bits/stdc++.h>
using namespace std;

bool rotateString(string &s, string &goal) {
    if (s.size() != goal.size()) return false;
    int n = s.size();
    string res(n, ' ');
    for (int ro = 0; ro < n; ro++) {
        int curIdx = 0;
        for (int i = ro; i < n; i++) {
            res[curIdx++] = s[i];
        }
        for (int i = 0; i < ro; i++) {
            res[curIdx++] = s[i];
        }
        cout << "Res: " << res << endl;
        bool isGoal = true;
        if (res != goal) {
            isGoal = false;
        }
        if (isGoal)
            return true;
    }
    return false;
}

int main() {
    string goal = "abcde", s = "cdeab";
    cout << "Goal: " << (rotateString(s, goal) ? "true" : "false") << endl;
    return 0;
}