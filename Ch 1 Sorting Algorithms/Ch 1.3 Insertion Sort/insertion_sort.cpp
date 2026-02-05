#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i=1; i<n ; i++) {
        int key = arr[i];
        int j = i-1;

        while(j>=0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

void printVector(vector<int> &arr) {
    for(int &val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {64, 11, 28, 12, 6, 33};
    cout << "Original Array: " << endl;
    printVector(arr);

    cout << "After Insertion Sort: " << endl;
    insertionSort(arr);
    printVector(arr);
    return 0;
}