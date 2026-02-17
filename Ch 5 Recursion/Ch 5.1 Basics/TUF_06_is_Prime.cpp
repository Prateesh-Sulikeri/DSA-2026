#include <bits/stdc++.h>
using namespace std;
// Brute force 
// bool isPrime(int num, int x) {
//     if (x == num) return false;
//     if (num % x == 0) return false;
//     else return true;
//     return isPrime(num, x+1);
// }

bool isPrime(int num, int x) {
    if (x > sqrt(num)) return true;
    if (num % x == 0) return false;
    return isPrime(num, x+1);
}

bool checkPrime(int num) {
    if (num <= 1) return false;

    return isPrime(num, 2);
}


int main() {
    bool res = checkPrime(31);
    cout << (res ? "true" : "false") << endl;
    return 0;
}