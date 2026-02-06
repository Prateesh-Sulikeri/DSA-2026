#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);
    for(int i=0 ; i<n1 ; i++) L[i] = arr[left + i];
    for(int j=0 ; j<n2 ; j++) R[j] = arr[mid + 1 + j];

    int i=0 , j=0;
    int k=left; 

    while(i < n1 && j <n2) {
        if(L[i] < R[j]) {
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
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
}

int partition(vector<int> &arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;

    for(int j=left ; j<right ; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[right]);
    return i+1;
}

void quickSort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int pi = partition(arr, left, right);
        quickSort(arr, left, pi-1);
        quickSort(arr, pi+1, right);
    }
}

void printArray(vector<int> &arr) {
    for(const auto &val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {64, 12, -8, 0, 22, 12, 88}; 
    vector<int> arr1 = {64, 12, -8, 0, 22, 12, 88}; 
    cout << "Original Array: ";
    printArray(arr);

    cout << "Merge Sort: "; 
    mergeSort(arr, 0, arr.size()-1);
    printArray(arr);

    cout << "Original Array: ";
    printArray(arr1);

    cout << "Quick Sort: ";
    quickSort(arr1, 0, arr1.size()-1);
    printArray(arr1);

    return 0;
}