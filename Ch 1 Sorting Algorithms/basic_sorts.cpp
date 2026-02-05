#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr) {
    int n = arr.size();
    for(int i=1 ; i<n ; i++) {
        int key = arr[i];
        int j = i - 1;

        while(j>=0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

void bubbleSort(vector<int> &arr) {
    int n = arr.size();
    for (int i=0 ; i < n-1 ; i++) {
        for(int j=0 ; j<n-i-1 ; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void selectionSort(vector<int> &arr) {
    int n = arr.size();

    for (int i=0 ; i<n-1 ; i++) {
        int min_idx = i;
        for (int j=i+1 ; j<n ; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

void printArray(vector<int> &arr) {
    for (int &val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    
    vector<int> arr_1 = {64, 12, 22, 8, 38, 1};
    vector<int> arr_2 = {64, 12, 22, 8, 38, 1};
    vector<int> arr_3 = {64, 12, 22, 8, 38, 1};

    cout << "Original arr_1: " << endl;
    printArray(arr_1);
    cout << "Original arr_2: " << endl;
    printArray(arr_2);
    cout << "Original arr_3: " << endl;
    printArray(arr_3);

    cout << "arr_1 after selection sort: " << endl;
    selectionSort(arr_1);
    printArray(arr_1);

    cout << "arr_2 after bubble sort: " << endl;
    bubbleSort(arr_2);
    printArray(arr_2);

    cout << "arr_3 after insertion sort: " << endl;
    insertionSort(arr_3);
    printArray(arr_3);
    return 0;
}