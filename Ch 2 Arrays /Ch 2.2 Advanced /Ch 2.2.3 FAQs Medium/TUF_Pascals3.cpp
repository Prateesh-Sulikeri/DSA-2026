#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int n) {
    vector<vector<int>> triangle;

    for (int i = 0; i < n; i++) {
        vector<int> row(i + 1, 1);

        for (int j = 1; j < i; j++) {
            row[j] = triangle[i-1][j-1] + triangle[i-1][j];
        }

        triangle.push_back(row);
    }

    return triangle;
}

int main() {
    int n = 5;
    vector<vector<int>> pascalTriangle = generate(n);
    cout << "Pascal's Triangle with " << n << " rows:" << endl;
    for (const auto& row : pascalTriangle) {
        for (const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }   
    return 0;
}