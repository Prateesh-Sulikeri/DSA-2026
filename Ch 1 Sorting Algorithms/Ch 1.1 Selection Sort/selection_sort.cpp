#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr) {
    int n = arr.size();

    for(int i=0 ; i<n-1 ; i++) {
        int min_idx = i;
        for(int j=i+1 ; j<n ; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

void printVector(vector<int> &arr) {
    for(int &val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {64, 12, 22, 11, 28};
    cout << "ORIGINAL ARRAY: " << endl;
    printVector(arr);
    cout << "AFTER SORT: " << endl;
    selectionSort(arr);
    printVector(arr);
    
    return 0;
}