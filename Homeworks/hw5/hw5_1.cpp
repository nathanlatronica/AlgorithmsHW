/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw5/challenges/recursive-exponents/submissions/code/1316810644
 * Title: hw5_1.cpp
 * Abstract: finds 2^n using recursion
 * Author: Nathan Latronica
 * ID: 1234
 * Date: 10/7/2019
 */

#include <iostream>
using namespace std;

int recurse(int n) {
    if (n == 0) {
        return 1;
    }
    
    if(n == 1) {
        return 2;
    } else {
        return 2 * recurse(n-1);
    }
}


int main() {
    int n;
    cin >> n;
    
    cout << recurse(n) <<endl;
    
}