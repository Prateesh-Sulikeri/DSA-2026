#include <bits/stdc++.h>
using namespace std;

vector<int> intersectionArrays(vector<int> &arr1, vector<int> &arr2) {
    vector<int> res;
    int i=0, j=0;
    int n1=arr1.size(), n2=arr2.size();

    while (i<n1 && j<n2) {
        if (arr1[i] < arr2[j]) 
            i++;
        else if (arr1[i] > arr2[j])
            j++;
        else {
            res.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return res;
}

void printVector(vector<int> &arr) {
    for (auto const &val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr1 = {1, 2, 2, 3, 4, 5};
    vector<int> arr2 = {2, 4, 7, 11};

    cout << "Original Arr1: " << endl;
    printVector(arr1);

    cout << "Original Arr2: " << endl;
    printVector(arr2);

    cout << endl;

    cout << "After Union: " << endl;
    vector<int> res = intersectionArrays(arr1, arr2);
    printVector(res);

    return 0;
}