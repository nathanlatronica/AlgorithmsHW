/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw6/challenges/connect-components/submissions/code/1317042108
 * Title: hw6_2.cpp
 * Abstract: Finds out if graph isn't connected and shows how to connect it.
 * Author: Nathan Latronica
 * ID: 1234
 * Date: 10/17/2019
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <queue> 
using namespace std;

int main() {
    set<int> seen;
    queue<int> que;
    vector<int> vec;
    
    int numVertex, numEdge;
    int from, to;
    
    cin >> numVertex;
    
    bool matrix[numVertex][numVertex];
    int markArray[numVertex];
    
    //set all links to false
    for(int i = 0; i < numVertex; i++) {
        markArray[i] = -1;
        for(int j=0; j<numVertex; j++) {
            matrix[i][j] = false;
        }
    }
    
    cin >> numEdge;
    //set edges
    for(int i= 0; i < numEdge; i++) {
        cin >> from >> to;
        matrix[from][to] = true;
    }
     
    int tracker;
    bool End;
    int counter = 0, count2 = -1;
    int min;

    while(true) {
        End = true;
        for(int i = 0; i < numVertex; i++) {
            if(markArray[i] == -1) {
                que.push(i);
                seen.insert(i);
                markArray[i] = counter;
                min = i;
                counter++;
                count2++;
                End = false;
                break;
            }
        }
        
        if(End) {
            break;
        }
        
        while(!que.empty()) {
            tracker = que.size();
            for(int i = 0; i < tracker; i++) {
                for(int j = 0; j <numVertex; j++) {
                    if(matrix[que.front()][j] == true) {
                        if(seen.count(j)) {
                            continue;
                        } else {
                            que.push(j);
                            seen.insert(j);
                            markArray[j] = counter;
                            if (j < min) {
                                min = j;
                            }
                            counter++;
                        }
                    }
                }
                que.pop();
                
            }
        }
        vec.push_back(min);
    }
    
    if(count2 == 0 ) {
        cout << "No new edge:" <<endl;
        return 0;
    }

    for(int i = 0; i < vec.size() -1; i++) {
        cout << "Edge: " << vec[i] << "-" << vec[i+1] << endl;
    }

    return 0;
}
