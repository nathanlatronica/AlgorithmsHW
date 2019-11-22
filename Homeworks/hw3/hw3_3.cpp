/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw3/challenges/adjacency-list/submissions/code/1316370357
 * Title: hw3_3.cpp
 * Abstract: Makes a visual representation of a adjacency list
 * Author: Nathan Latronica
 * ID: 1234
 * Date: 9/18/19
 */
#include <iostream>
using namespace std;

int main() { 
    int verticies, edges;
    
    cin >> verticies>> edges;
    
    int matrix[verticies][verticies];
    int from, to;
    
    for(int i = 0; i < verticies; i++) {
        for(int j = 0; j < verticies; j++) {
            matrix[i][j] = 0;
        }
    }
    
    for(int i = 0; i < edges; i++) {
        cin >> from >> to;
        matrix[from][to] = 1;
    }
    
    
    for(int i = 0; i < verticies; i++) {
        cout << i;
            
        for(int j = 0; j < verticies; j++) {
            if(matrix[i][j] == 1) {
                cout << "->" << j;
            }
        }
        cout << endl;
    }
}