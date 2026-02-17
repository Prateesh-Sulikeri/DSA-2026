#include <bits/stdc++.h>
using namespace std;

static int iteration = 0;

int NnumberSum(int n) {
    if (n == 1 || n == 0) return n;
    int sum = n + NnumberSum(n - 1);
    cout << "Iteration: " << iteration++ << "\nSUM: " << sum << endl << endl;
    return sum;
}

int main() {
    int res =  NnumberSum(4);
    cout << "Final Res: " << res << endl;
    return 0;
}