#include <bits/stdc++.h>
using namespace std;

vector<long long> getRow(int r) {
    int n = r - 1;
    vector<long long> row;

    long long val = 1;
    row.push_back(val);

    for (int i = 1; i <= n; i++) {
        val = val * (n - i + 1) / i;
        row.push_back(val);
    }

    return row;
}

int main() {
    int r = 5;
    vector<long long> row = getRow(r);      
    cout << "Row " << r << " of Pascal's Triangle is: ";
    for (const auto& val : row) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}