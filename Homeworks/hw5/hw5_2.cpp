/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw5/challenges/bfs-hops/leaderboard
 * Title: hw5_2.cpp
 * Abstract: BFS using a queue
 * Author: Nathan Latronica
 * ID: 1234
 * Date: 10/8/2019
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <queue> 
using namespace std;

int main() {
    vector<string> output;
    
    set<string> results;
    queue<string> que;
    unordered_map<string, int> placeIndex;
    unordered_map<int, string> indexPlace;
    
    int numVertex, numEdge, maxJumps;
    string place, from, to, start;
    
    cin >> numVertex;
    
    bool matrix[numVertex][numVertex];
    
    //sets matrix to all false;
    for(int i = 0; i < numVertex; i++) {
        for(int j=0; j<numVertex; j++) {
            matrix[i][j] = false;
        }
    }
    //
    
    //sets maps with values
    for(int i=0; i < numVertex; i++) {
        cin >> place;
        placeIndex[place] = i;
        indexPlace[i] = place;
    }
    //
    
    cin >> numEdge;
    for(int i = 0; i < numEdge; i++) {
        cin >> from >> to;
        matrix[placeIndex[from]][placeIndex[to]] = true;
    }
    
    // //couts matrix
    // for(int i = 0; i < numVertex; i++) {
    //     for(int j=0; j<numVertex; j++) {
    //         cout << matrix[i][j] << " " ;
    //     }
    //     cout <<endl;
    // }
    // cout << endl;
    // //
    cin >> start >> maxJumps;
    //all inputs taken care of.

    que.push(start);
    results.insert(start);
    int tracker;
    
    while(!que.empty()) {
        if(maxJumps == 0) {
            break;
        }
        
        tracker = que.size();
        for(int j = 0; j < tracker; j++) {
            for(int i = 0; i < numVertex; i++) {
        
                if(matrix[placeIndex.at(que.front())][i] == true) {
                    if(results.count(indexPlace.at(i))) {
                        continue;
                    } else {
                        que.push(indexPlace.at(i));
                        results.insert(indexPlace.at(i));
                    }
                }
            }
            que.pop();
        }
        
        maxJumps--;

    }
    
    set <string>::iterator itr; 

    for (itr = results.begin(); itr != results.end(); itr++) 
    { 
        output.push_back(*itr);
    } 
    
    sort(output.begin(), output.end()); 

    for(int i = 0; i < output.size(); i++) {
        cout << output[i] << endl;
    }
    

}