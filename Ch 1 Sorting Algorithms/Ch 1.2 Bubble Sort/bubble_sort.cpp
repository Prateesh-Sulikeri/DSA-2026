#include <bits/stdc++.h>
using namespace std;

/*

{64, 12, 11, 28, 11, 6};
{12, 64, 11, 28, 11, 6}
{12, 11, 64, 28, 11, 6}
{12, 11, 28, 64, 11, 6}
{12, 11, 28, 11, 64 ,6}
{12, 11, 28, 11, 6, 64}

observation: outer loop as a counter 
inner loop for actual comparison and swap: 
inner loop is going to shrink each iterator as n-i-1

*/

void bubbleSort(vector<int> &arr) {
    int n = arr.size();

    for(int i=0 ; i<n-1 ; i++) {
        for (int j=0 ; j<n-i-1 ; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void printVecrtor(vector<int> &arr ){ 
    for(int &val: arr) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {64, 12, 11, -28, 11, 6,};
    cout << "Original Array: " << endl;
    printVecrtor(arr);

    cout << "After sort: " << endl;
    bubbleSort(arr);
    printVecrtor(arr);

    return 0;
}