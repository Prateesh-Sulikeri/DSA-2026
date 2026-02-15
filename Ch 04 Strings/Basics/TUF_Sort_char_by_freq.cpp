#include <bits/stdc++.h>
using namespace std;

static bool comparitor(pair<int, char> p1, pair<int, char> p2) {
    if (p1.first > p2.first) return true;
    if (p1.first < p2.first) return false;
    return p1.second < p2.second;
}

vector<char> freqSort(string &s) {
    pair<int, char> freq[26];
    for (int i=0 ; i<26 ; i++) {
        freq[i] = {0, i + 'a'};
    }

    for (auto &ch : s) {
        freq[ch - 'a'].first++;
    }
    // Sorts the frequency array in descending order of frequency, and ascending order of character if frequencies are equal
    // explain it in detail why freq, what does freq+26 mean how the comparitor works in a comment
    // freq is a pointer to the first element of the array freq[26]
    // freq+26 is a pointer to the element just past the last element of the array freq[26]
    // The sort function will sort the elements in the range [freq, freq+26)
    // its first pointer, last pointer and a comparitor function that defines the sorting criteria
    // so if it was a vector instead of a pair would freq point to first vector element ? Yes, if it was a vector instead of a pair, freq would point to the first element of the vector. The sort function would then sort the elements in the range [freq, freq + vector_size) where vector_size is the number of elements in the vector. The comparitor function would still define the sorting criteria based on the values of the elements in the vector.
    sort(freq, freq+26, comparitor);
    
    vector<char> ans;
    for (int i=0 ; i <26 ; i++) {
        if (freq[i].first > 0) {
            ans.push_back(freq[i].second);
        }
    }
    return ans;
}

int main() {
    // write a main for above example 
    string s = "tree";
    vector<char> ans = freqSort(s);
    cout << "Characters sorted by frequency: ";
    for (char ch : ans) {
        cout << ch << " ";
    }
    cout << endl;
    return 0;
}