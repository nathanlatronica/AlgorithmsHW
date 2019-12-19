/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw11/challenges/coin-row/submissions/code/1318175669
 * Title: hw11_1.cpp
 * Abstract: Coin Row Problem
 * Author: Nathan Latronica
 * ID: 1234
 * Date: 12/4/19
 */

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, temp;
    
    cin >> n;
    
    int coins[n + 1];
    int final[n + 1];
    int back[n + 1];
    
    coins[0] = 0;
    final[0] = 0;

    for(int i = 0; i < n; i++) {
        cin >> temp;
        coins[i + 1] = temp;
    }
    final[1] = coins[1];
    
    
    // for(int i = 0; i < n + 1; i++) {
    //   cout << coins[i] << " "; 
    // }
    // cout << endl;
    
    for(int i = 2; i <n + 1; i++) {
        final[i] = max(coins[i] + final[i-2], final[i-1]);
    }

    int count = 0, tracker = n ;
    
    while(tracker > 0) {
        if(final[tracker] != final[tracker - 1]) {
            back[count] = tracker;
            tracker -= 2;
            count++;
        } else if(final[tracker] == final[tracker - 1]) {
            tracker -= 1;
        }
    }
    
    
    
    cout << "Best set:";
    for(int i = --count; i >= 0; i--) { 
        cout << back[i] << " ";
    }
    cout <<endl;
    
    cout << "Max value:" << final[n];
}