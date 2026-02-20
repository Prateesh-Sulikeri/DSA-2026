#include <bits/stdc++.h>
using namespace std;

void move0sToEnd(vector<int> &arr) {
    int n = arr.size();
    int i = 0;
    for (int j=0 ; j<n ; j++) {
        if (arr[j] != 0) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
}

void printVector(vector<int> &arr) {
    for (auto const &val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {0, 1, 4, 0, 5, 2};
    // vector<int> arr = {0, 0, 0, 1, 3, -2};
    // vector<int> arr = {1, 0, 2, 0};

    cout << "Original vector: " << endl;
    printVector(arr);

    cout << "moved vector: " << endl;
    move0sToEnd(arr);
    printVector(arr);
    return 0;
}