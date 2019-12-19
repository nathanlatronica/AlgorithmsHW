/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw12/challenges/knapsack-7-1/submissions/code/1318380648
 * Title: hw12_1.cpp
 * Abstract: Knap sack dynamically 
 * Author: Nathan Latronica
 * ID: 1234
 * Date: 12/12/2019
 */

#include <iostream>
#include <algorithm>
#include <vector> 

using namespace std;

int main() {
    int n, weight, capacity, value;
    
    cin >> n >> capacity;
    vector<int> weights;
    vector<int>chosen;

    int matrix[n+1][capacity+1];
    
    
    for(int i = 0; i < n+1; i++) {
        for(int j = 0; j < capacity+1; j++) {
            matrix[i][j] = 0;
        }
    }
    
    for(int i = 1; i < n+1; i++) {
        cin >>weight >> value;
        weights.push_back(weight);
        
        for(int j = 1; j < capacity+1; j++) {
            if(weight > j) {
                matrix[i][j] = matrix[i-1][j];
            } else if (weight <= j){
                matrix[i][j] = max(value + matrix[i-1][j-weight], matrix[i-1][j]);
            }
            
        }
    }
    
    // for(int i = 0; i < n+1; i++) {
    //     for(int j = 0; j < capacity+1; j++) {
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout <<endl;
    // }   
    
    int x = n, y = capacity;
    while(true) {
        if(matrix[x][y] != matrix[x-1][y]) {
            chosen.push_back(x);
            x -= 1;
            y -= weights[x];
        } else {
            x -= 1;
        }
        if (x == 0) {
            break;
        }
    }

    cout << "Final step:";
    for(int j = 0; j < capacity+1; j++) {
        cout << matrix[n][j]  << " ";
    }

    cout<<endl << "Max value:" << matrix[n][capacity] <<endl;
    cout <<"Items:";
    for(int i = chosen.size()-1; i > -1; i--) {
        cout << chosen[i] << " ";
    }
    
    
    
}
