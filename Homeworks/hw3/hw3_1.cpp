/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw3/challenges/palindrome-check-10/submissions/code/1316342783
 * Title: hw3_1.cpp
 * Abstract: checks if palindrome
 * Author: Nathan Latronica
 * ID: 1234
 * Date: 9/17/19
 */
#include <iostream>
#include <string>
using namespace std;

int main() { 
    string word;
    int start, end;
    
    getline(cin,word);
    
    start = 0;
    end = word.length() - 1;
    

    
    while(start < end) {
        while(!isalpha(word[start]) && !isdigit(word[start])) {
            start++;
                
        }
        
        while(!isalpha(word[end]) && !isdigit(word[end])) {
            end--;
                
        }
        if(tolower(word[start]) != tolower(word[end])) {
            cout <<"FALSE" <<endl;
            return 0;
        }
        start++;
        end--;
    }
    
    cout << "TRUE" <<endl;
    return 0;
    
    
    
}