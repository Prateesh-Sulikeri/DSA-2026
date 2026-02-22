// With comments solve the rotate matrix by 90 degree problem and add main function to test the code
#include <bits/stdc++.h>
using namespace std;    

void rotateMatrixBy90Deg(vector<vector<int>> &mat) {
    int n = mat.size();

    // Step 1: Transpose the matrix
    for (int i=0 ; i<n ; i++) {
        for (int j=i+1 ; j<n ; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }

    // Step 2: Reverse each row to get the rotated matrix
    for (int i=0 ; i<n ; i++) {
        reverse(mat[i].begin(), mat[i].end());
    }
}

void printMatrix(const vector<vector<int>> &mat) {
    for (const auto& row : mat) {
        for (const auto& col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> mat = {{1, 2, 3}, {4 ,5 ,6}, {7, 8, 9}};
    
    cout << "Original Matrix:" << endl;
    printMatrix(mat);
    
    rotateMatrixBy90Deg(mat);
    
    cout << "Matrix after rotating by 90 degrees:" << endl;
    printMatrix(mat);
    
    return 0;
}