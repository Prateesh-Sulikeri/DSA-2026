#include <bits/stdc++.h>
using namespace std;

void leftRotateBy1(vector<int> &arr) {
    int n = arr.size() ;
    int first = arr[0];

    for (int i=0 ; i<n-1 ; i++) {
        arr[i] = arr[i+1];
    }
    arr[n-1] = first;
}

void leftRotateByK(vector<int> &arr, int k) {
    int n = arr.size();
    k %= n;

    // Less optimal: 
    /*
    vector<int> temp;
    for (int i=0 ; i<k ; i++) {
        temp.push_back(arr[i]);
    }

    // push other stuff to left: 
    for (int i=k ; i<n ; i++) {
        arr[i-k] = arr[i];
    }

    for (int i=(n-k) ; i<n ; i++) {
        temp.push_back(arr[i]);
    }
    */
    // optimal soltuion:
    reverse(arr.begin(), arr.begin()+k);
    reverse(arr.begin()+k, arr.end());
    reverse(arr.begin(), arr.end());
}

void printVector(vector<int> &arr) {
    for (auto const& val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> arr2 = {1, 2, 3, 4, 5};

    cout << "Before rotate 1: " << endl;
    printVector(arr);

    cout << "After rotate 1: " << endl;
    leftRotateBy1(arr);
    printVector(arr);

    cout << endl; 
    cout << endl; 

    int k = 3;
    cout << "Before rotate by: " << k << endl;
    printVector(arr2);

    cout << "After rotate by: " << k << endl;
    leftRotateByK(arr2, k);
    printVector(arr2);

    
    return 0;
}