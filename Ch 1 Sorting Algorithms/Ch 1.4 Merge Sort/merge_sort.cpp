#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right) {
    // extract 2 sizes: 
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    vector<int> L(n1), R(n2);
    for (int i=0 ; i<n1 ; i++)
        L[i] = arr[left + i];
    for (int j=0 ; j<n2 ; j++)
        R[j] = arr[mid + 1 + j];

    int i=0, j=0;
    int k = left;

    while(i<n1 && j<n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int left, int right) {
    if(left >= right) return;

    int mid = left + (right - left ) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
}

void printArray(vector<int> &arr) {
    for(const auto &val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {64, -12, 18, 22, 1, 9, 38, 0};
    cout << "Original Array: ";
    printArray(arr);

    // calling mergesort:
    mergeSort(arr, 0, arr.size()-1);
    cout << "After Sort: ";
    printArray(arr);
    return 0;
}