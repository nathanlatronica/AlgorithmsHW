/*
 * HackerRank link:  https://www.hackerrank.com/contests/cst370-f19-hw4/challenges/matching-form/submissions/code/1316550269
 * Title: hw4_2.cpp
 * Abstract: Check for balanced {([])}
 * Author: Nathan Latronica
 * ID: 1234
 * Date: 9/25/19
 */
 
//Have done this problem before.
#include <iostream>
#include <stack>
using namespace std;

int main() {
    string in;
    char l;
    stack <char> s;
    int curly = 0, para = 0, square = 0;
    
    cin >> in;
    for(int i = 0; i < in.size(); i++) {
        l = in[i];
        s.push(l);
    }
    
    while(!s.empty()) {
        l = s.top();
        if(l == '}') {
            curly++;
        } else if(l == ']') {
            square++;
        } else if(l == ')') {
            para++;
        } else if(l == '{') {
            curly--;
        } else if(l == '(') {
            para--;
        } else if(l == '[') {
            square--;
        }
        s.pop();
    }
    
    if(para == 0 && square == 0 && curly == 0 ) {
        cout << "TRUE" << endl;
    } else {
        cout << "FALSE" <<endl;
    }
    
   
}