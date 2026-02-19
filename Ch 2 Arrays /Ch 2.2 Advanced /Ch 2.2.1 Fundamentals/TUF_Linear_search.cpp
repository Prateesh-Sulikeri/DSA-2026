#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int> &arr, int target) {
    for (int i=0 ; i<arr.size() ; i++) {
        if (arr[i] == target) 
            return i;
    }
    return -1;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << "Element: 2 was found on index: " <<   linearSearch(arr, 2);
    return 0;
}