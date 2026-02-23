#include <bits/stdc++.h>
using namespace std;

long long pascalValue(int r, int c) {
    int n = r - 1;
    int k = c - 1;

    if (k > n) return 0;

    k = min(k, n - k);  // symmetry optimization

    long long res = 1;
    for (int i = 0; i < k; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }

    return res;
}

int main() {
    int r = 5, c = 3;
    cout << "Value at row " << r << " and column " << c << " in Pascal's Triangle is: " << pascalValue(r, c) << endl;
    return 0;
}