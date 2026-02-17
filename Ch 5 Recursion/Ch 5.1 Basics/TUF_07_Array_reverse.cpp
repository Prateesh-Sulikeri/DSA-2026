#include <bits/stdc++.h>
using namespace std;

int iteration_counter = 0;
void revHelper(vector<int> &arr, int left, int right) {
    if (left >= right) return;
    swap(arr[left], arr[right]);
    cout << "ITERATION: " << ++iteration_counter << endl;
    for (const auto& i: arr) {
        cout << i << " ";
    }
    cout << endl;
    revHelper(arr, left+1, right-1);
}

vector<int> revArray(vector<int> &arr) {
    int left = 0;
    int right = arr.size() - 1;

    revHelper(arr, left, right) ;
    return arr;
}   

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    cout << "After reversal:: " << endl;
    vector<int> res = revArray(arr);
    for (const auto& i: res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}