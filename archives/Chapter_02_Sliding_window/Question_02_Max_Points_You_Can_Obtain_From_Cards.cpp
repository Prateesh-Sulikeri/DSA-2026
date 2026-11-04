#include <bits/stdc++.h>
using namespace std;

/*
    Question 2: Max Points You Can Obtain From Cards
    link: https://www.hellointerview.com/learn/code/sliding-window/maximum-points-you-can-obtain-from-cards

    Problem Statement: Given an array of integers representing card values, write a function to calculate the maximum score you can achieve by picking exactly k cards.

    You must pick cards in order from either end. You can take some cards from the beginning, then switch to taking cards from the end, but you cannot skip cards or pick from the middle.
*/

/*

    Intuition:
    1. We need to find pair of cards from start or end or few from start and few from end but not from middle directly 

    we know that sum(selected cards) + sum(leftover cards) = total sum of cards
    so if we want sum(selected cards) then 
    sum(selected cards) = total - sum(leftover cards)
    
    what left over actually means:
    if there are n cards and we need to select k cards from these set of n cards then we always have n-k cards leftover

    hence if we find the sum of this window and subtract it from the total we can obtain the sum(selected cards)
    
    so instead of directly finding sum(selected cards) which is O(k) from start O(k) from end and all possible combinations together make it O(k^2), we find it for n-k window and have a better time complexity
*/

int maxScore(vector<int>& cards, int k) {
    int total = 0;
    int n = cards.size();

    for (int card: cards) {
        total += card;
    }

    if (k == n) return total;

    int start = 0;
    int windowSum = 0;
    int maxPoints = INT_MIN;

    for (int end = 0 ; end < n ; end++) {
        windowSum += cards[end];

        if (end - start + 1 == n - k) {
            maxPoints = max(maxPoints, total - windowSum);
            windowSum -= cards[start];
            start++;
        }
    }
    return maxPoints;
}

int main() {
    vector<int> input = {2,11,4,5,3,9,2};
    int k = 3;

    cout << "Max Points possible for no of cards to pick: " << k << " is: " << maxScore(input, k) << endl;
    return 0;
}