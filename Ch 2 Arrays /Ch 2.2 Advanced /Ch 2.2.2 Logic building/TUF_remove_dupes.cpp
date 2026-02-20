#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &arr) {
    for (auto const &val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

int removeDupes(vector<int> &arr) {
    int slow = 0;
    for (int fast=1 ; fast<arr.size() ; fast++) {
        if (arr[slow] != arr[fast]) {
            slow++;
            arr[slow] = arr[fast];
        }
        cout << "Iteration: " << slow+1 << endl;
        printVector(arr);
    }

    return slow + 1;
}


int main() {
    vector<int> arr = {0, 0, 3, 3, 3, 5, 6};
    cout << "Orig: " << endl;
    printVector(arr);

    cout << endl;


    cout << "Afer remove dupes: " << endl;
    int res = removeDupes(arr);
    cout << res << endl << endl;
    printVector(arr);
    return 0;
}