/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw12/challenges/floyd-all-pairs-shortest-paths/submissions/code/1318378652
 * Title: hw12_2.cpp
 * Abstract: Floyd Warshalls algorithm
 * Author: Nathan Latronica
 * ID: 1234
 * Date: 12/12/2019
 */

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, temp;

    cin >> n;
    
    int matrix[n][n];
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> temp;
            if(temp == -1) {
                temp = 10000;
            }
            matrix[i][j] = temp;
        }
    }
    
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            if(i == k) {
                continue;
            }
            for(int j = 0; j < n; j++) {
                if(j == k) {
                    continue;
                }
                // matrix[i][j] = min(matrix[i][j], matrix[j][k] + matrix[k][j]);
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                // cout << matrix[j][k] + matrix[k][j] << " ";
                    
                
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == 10000) {
                matrix[i][j] = -1;
            } 
        }
    } 
    
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout <<endl;
    }
    
    
}