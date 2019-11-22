/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw5/challenges/dfs-4/submissions/code/1316811133
 * Title: hw5_3.cpp
 * Abstract: Does DFS using a matrix, stack, markArray
 * Author: Nathan Latronica
 * ID: 1234
 * Date: 10/7/2019
 */

#include <iostream>
#include <stack>
using namespace std;

int main() {
    int numVertex, numEdge, from, to;
    stack<int> DFStack;
    
    cin >> numVertex;
    
    bool matrix[numVertex][numVertex];
    int markArray[numVertex];
    
    //sets markArray and matrix to all -1's
    for(int i = 0; i < numVertex; i++) {
        markArray[i] = -1;
        for(int j=0; j<numVertex; j++) {
            matrix[i][j] = false;
        }
    }
    
    cin >> numEdge;
    
    for(int i = 0; i < numEdge; i++) {
        cin >> from >> to;
        matrix[from][to] = true;
    }
    
    int count = 2;
    DFStack.push(0);
    markArray[0] = 1;
    bool erase;
    
    while(!DFStack.empty()) {
        //loop through row at stack.top
        erase = true;
        for(int i = 0; i < numVertex; i++) {
            if(matrix[DFStack.top()][i] && markArray[i] == -1) {
                markArray[i] = count;
                count++;
                DFStack.push(i);
                erase = false;
                break;
            }
        }
        if(erase) {
            DFStack.pop();
        }
    }
    //couts markArray
    for(int i = 0; i < numVertex; i++) {
        cout << "Mark[" << i << "]:" << markArray[i] << endl;
    }
}