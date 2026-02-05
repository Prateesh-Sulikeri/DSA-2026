#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> &arr) {
    for (int &val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

int LC_1051(vector<int> &heights) {
    int n = heights.size();
    vector<int> expected = heights;

    for (int i=0 ; i<n-1 ; i++) {
        for(int j=0 ; j<n-i-1 ; j++) {
            if (expected[j] > expected[j+1]) {
                swap(expected[j], expected[j+1]);
            }
        }
    }

    int res = 0;
    for(int i= 0 ; i<n ; i++) {
        if (heights[i] == expected[i]) {
            continue;
        }
        res++;
    }
    return res;
}

int main() {
    vector<int> heights = {1, 1, 4, 1, 3, 2, 7};    
    int res = LC_1051(heights);
    cout << res;
    return 0;
}