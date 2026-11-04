#include <bits/stdc++.h>
using namespace std;

/*
    Question 12: Assing Cookies
    link: https://takeuforward.org/plus/dsa/problems/assign-cookies

    Problem Statement: Consider a scenario where a teacher wants to distribute cookies to students, with each student receiving at most one cookie.
    Given two arrays, student and cookie, the ith value in the Student array describes the minimum size of cookie that the ith student can be assigned. The jth value in the Cookie array represents the size of the jth cookie. If Cookie[j] >= Student[i], the jth cookie can be assigned to the ith student.

    Maximize the number of students assigned with cookies and output the maximum number.
*/

int findMaximumCookieStudents(vector<int>& Student, vector<int>& Cookie) {
    int l = 0, r = 0;
    int n = Student.size();
    int m = Cookie.size();

    sort(Student.begin(), Student.end());
    sort(Cookie.begin(), Cookie.end());

    while (l < n && r < m) {
        if (Cookie[r] >= Student[l]) {
            l++;
        }
        r++;
    }
    return l;
}

int main() {
    
    vector<int> input1 = {1, 2, 3};
    vector<int> input2 = {1, 2};

    cout << "No of Students that can be assigned a cookie are: " << findMaximumCookieStudents(input1, input2) << endl;

    return 0;
}