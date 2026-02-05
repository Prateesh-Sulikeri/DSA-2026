#include <bits/stdc++.h>
using namespace std;

vector<int> selectionSort(vector<int> &arr) {
    int n = arr.size();
    for(int i=0 ; i<n-1 ; i++) {
        int is_even = i;
        for(int j=i+1 ; j<n ; j++) {
            if(arr[j] % 2 == 0){
                is_even = j;
            }
        }
        swap(arr[i], arr[is_even]);
    }
    return arr;
}

void printVector(vector<int> &arr) {
    for(int &val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    cout << "Original Array: " << endl;
    printVector(arr);
    cout << "After sort: " << endl;
    vector<int> res = selectionSort(arr);
    printVector(res);

    return 0;
}