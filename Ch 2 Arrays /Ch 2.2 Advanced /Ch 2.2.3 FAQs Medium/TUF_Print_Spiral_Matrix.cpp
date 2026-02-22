#include <bits/stdc++.h>
using namespace std;

vector<int> printSpiralMatrix(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();

    vector<int> res;

    int top = 0, bottom = n-1;
    int left = 0, right = m-1;

    while (left <= right && top <= bottom) {
        // going from top row, left towards right:
        for (int i=left ; i<=right ; i++)
            res.push_back(mat[top][i]);
        top++;

        // going from right column, top towards bottom:
        for (int i=top ; i<=bottom ; i++) {
            res.push_back(mat[i][right]);
        }
        right--;
        

        // Since top might have changed from above excursion we need to recheck:
        if (top <= bottom) {
            // going from bottom row, right towards left: 
            for (int i=right ; i>=left ; i--)
                res.push_back(mat[bottom][i]);
            bottom--;
        }

        // Since left might have changed from above excursions we need to recheck:
        if (left <= right) {
            // going from left column, from bottom to top:
            for (int i=bottom ; i>=top ; i--) 
                res.push_back(mat[i][left]);
            left++; 
        }   
    }
    return res;
}

void printArray(vector<int> &arr) {
    for (auto const &val : arr ) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<vector<int>> mat = {{1, 2, 3}, {4 ,5 ,6}, {7, 8, 9}};
    for (auto const& row : mat) {
        for (auto const & col: row) {
            cout << col << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Resuting Spiral print vector is: " << endl;
    vector<int> res = printSpiralMatrix(mat);
    printArray(res);
    return 0;
}