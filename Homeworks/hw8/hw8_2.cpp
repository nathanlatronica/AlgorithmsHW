/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw8/challenges/kahns-topological-sort/submissions/code/1317333194
 * Title: hw8_2.cpp
 * Abstract: topological search
 * Author: Nathan Latronica
 * ID: 1234
 * Date: 10/30/19
 */


#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int main() {
    int numVertex, numEdge;
    
    cin >> numVertex >> numEdge;

    queue<int> que;
    set<int> set;
    bool matrix[numVertex][numVertex];
    int inDegree[numVertex];
    vector<int> order;
    
    for(int i = 0; i < numVertex; i++) {
        inDegree[i] = 0;
        for(int j = 0; j < numVertex; j++) {
            matrix[i][j] = false;
        }
    }
    
    int from, to;
    for(int i = 0; i < numEdge; i++) {
        cin >> from >> to;
        matrix[from][to] = true;
    }
    
    for(int i = 0; i < numVertex; i++) {
        for(int j = 0; j < numVertex; j++) {
            if(matrix[j][i]) {
                inDegree[i]++;
            }
        }
        
    }
    
    for(int i = 0; i < numVertex; i++) {
        cout << "In-degree[" << i << "]:" << inDegree[i] <<endl;
    }

    
    bool noLoop; 
    int tracker;
    while(true) {
        noLoop =true;
        for(int i = 0; i < numVertex; i++) {
            if(inDegree[i] > 0) {
                noLoop = false;
            } else if(inDegree[i] == 0 && set.count(i) == 0) {
                que.push(i);
            }
        }   
    
        
        tracker = que.size();
        if(tracker == 0) {
            cout << "No Order:" <<endl;
            return 0;   
        }
        for(int i = 0; i < tracker; i++) {
            for(int j = 0; j < numVertex; j++) {
                if(matrix[que.front()][j]) {
                    inDegree[j]--;
                }
            }
            set.insert(que.front());
            order.push_back(que.front());
            que.pop();
        }

        if(noLoop) {
            break;
        }

        
        
    }
    
    if(order.size() == 0) {
        cout << "No Order:" <<endl;
        return 0;
    }
    
    cout << "Order:";
    for(int i = 0; i < numVertex; i++) {
        if(i != numVertex -1) {
            cout <<order[i] << "->";
        } else {
            cout << order[i];
        }
    }
    
}