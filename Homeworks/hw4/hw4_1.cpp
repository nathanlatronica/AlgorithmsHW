/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw4/challenges/buy-two-one-free/submissions/code/1316549978
 * Title: hw4_1.cpp
 * Abstract: Buy 2 get one free problem
 * Author: Nathan Latronica
 * ID: 1234
 * Date: 9/25/19
 */

#include <iostream>
#include <algorithm> 
using namespace std;

int main() {
    int n, temp, result = 0, bought = 0;
    
    cin >> n;
    
    int nums[n];
    
    for(int i = 0; i < n; i++) {
        cin >> temp;
        nums[i] = temp;
    }
    sort(nums, nums+n);
    
    for(int i = 0; i < n; i++) {
        result += nums[i];
        bought++;
        
        if(bought == 2) {
            n--;
            bought = 0;
        }
    }
    cout << result << endl;
    
}