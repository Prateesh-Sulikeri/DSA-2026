#include <bits/stdc++.h>
using namespace std;

/*
    Question 3: Fruit Into Baskets
    link: https://leetcode.com/problems/fruit-into-baskets/

    Problem Statement: You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.
*/  

int totalFruit(vector<int>& fruits) {
    unordered_map<int, int> basket;
    int max_fruits = 0;
    int start = 0;

    for (int end = 0 ; end < fruits.size() ; end++) {
        basket[fruits[end]]++;

        while (basket.size() > 2) {
            basket[fruits[start]]--;

            if (basket[fruits[start]] == 0) 
                basket.erase(fruits[start]);


            start++;
        }
        max_fruits = max(max_fruits, end - start + 1);
    }
    return max_fruits;
}

int main() {
    
    vector<int> input = {1,2,3,2,2};

    cout << "Maximum number of fruits we can pick is: " << totalFruit(input) << endl; 

    return 0;
}