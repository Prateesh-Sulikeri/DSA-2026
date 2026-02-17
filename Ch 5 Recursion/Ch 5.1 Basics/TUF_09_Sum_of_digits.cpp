#include <bits/stdc++.h>
using namespace std;

int sumDigits(int num) {
    if (num == 0) return 0;
    return sumDigits(num/10) + (num % 10);
}

int addNum(int num) {
    // single digit
    if (num < 10) return num;
    int sum = sumDigits(num);
    return addNum(sum);
}

int main() {
    int num = 165177;
    cout << "Sum of digits of num: " << num << " is: " << addNum(num) << endl;
    return 0;
}