#include <bits/stdc++.h>
using namespace std;

bool bruteForceSol(vector<int> &arr) {
    int n = arr.size();
    vector<int> checkSorted(n);

    // 2 loops: [offset to n-1] and 2nd: [0 to offset]
    for (int rotationOffset=0 ; rotationOffset<n ; rotationOffset++) {
        int curIdx = 0;
        for (int i=rotationOffset ; i<n ; i++) {
            checkSorted[curIdx++] = arr[i];
        }
        for (int i=0 ; i<rotationOffset ; i++) {
            checkSorted[curIdx++] = arr[i];
        }
        bool isSorted = true;
        for (int i=0 ; i<n-1 ; i++) {
            if (checkSorted[i] > checkSorted[i+1]) {
                isSorted = false;
                break;
            }
        }
        if (isSorted) {
            return true;
        }
    }
    return false;
}

bool optimalSol(vector<int> &arr) {
    int count=0 , n = arr.size();
    for (int i=0 ; i<n ; i++) {
        if (arr[i] > (arr[(i+1)%n])) {
            count++;
        }
    }
    return count <2;
}

int main() {
    vector<int> arr = {3, 4, 5, 1, 2};
    // vector<int> arr = {2, 1, 3, 4};
    string res =(!bruteForceSol(arr)) ? "false" : "true";
    cout << "Brute Force: " << res << endl;
    res =(!optimalSol(arr)) ? "false" : "true";
    cout << "Optimal soltution: " << res << endl; 
    return 0;
}