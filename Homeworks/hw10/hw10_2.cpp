/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw10/challenges/alien-alphabet/submissions/code/1317869898
 * Title: hw10_2.cpp
 * Abstract: Says what letters come first in an alien language
 * Author: Nathan Latronica
 * ID: 1234
 * Date: 11/22/2019
 */

#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<char, int> leIndex;
    unordered_map<int, char> inLetter;

    int n, letters = 0;
    set<char> set1;
    cin >> n;
    string alpha[n];
    string word;
    
    for(int i = 0; i < n; i++) {
        cin >> word;
        alpha[i] = word;
        for(int j = 0; j < word.size(); j++) {
            if(!set1.count(word[j])) {
                set1.insert(word[j]);
                leIndex[word[j]] = letters;
                inLetter[letters] = word[j];
                letters++;
            }
        }
    }
    
    bool matrix[letters][letters];
    //sets defaults
    for(int i = 0; i < letters; i++) {
        for(int j = 0; j < letters; j++) {
            matrix[i][j] = 0;
        }
    }    
    //
    
    string word1, word2;
    int smallestWord;
    for(int i = 0; i < n; i++) {
        word1 = alpha[i];
        
        for(int j = i + 1; j< n; j++) {
            word2 = alpha[j];
            smallestWord = max(word1.size(), word2.size() );
            
            for(int k = 0; k < smallestWord; k++) {
                if(word1[k] == word2[k]) {
                    continue;
                } else {
                    matrix[leIndex[word2[k]]][leIndex[word1[k]]] = true;
                    break;
                }
                
            }
        }
        
    }
    vector<char> order;
    int inDegree[letters];
    set<char> set2;
    queue<char> que;
    int tracker;
    
    //set inDegree
    for(int i = 0; i < letters; i++) {
        inDegree[i] = 0;
    }
    for(int i = 0; i < letters; i++) {
        for(int j = 0; j < letters; j++) {
            if(matrix[j][i] == 1) {
                inDegree[i]++;
            }
        }
    }
    //
    
    bool noloop = false;
    while(!noloop) {
        noloop = true;
        for(int i = 0; i < letters; i++) {
            if(inDegree[i] > 0) {
                noloop = false;
            } else if (inDegree[i] == 0 && !set2.count(inLetter[i])) {
                que.push(inLetter[i]);
            }
        }
        tracker = que.size();
        if(tracker == 0 || tracker > 1) {
            cout << "Invalid input." <<endl;
            return 0;
        }
        for(int i = 0; i < tracker; i++) {
            for(int j = 0; j < letters; j++) {
                if(matrix[leIndex[que.front()]][j]) {
                    inDegree[j]--;
                }
            }
            set2.insert(que.front());
            order.push_back(que.front());
            que.pop();
            
        }
        
    }
    
    
    if(order.size() == 0) {
        cout << "Invalid input." <<endl;
        return 0;
    }
    
    for(int i = letters - 1; i > -1; i--) {
        if(i != 0) {
            cout <<order[i] << "->";
        } else {
            cout << order[i];
        }
    }
        
}

    