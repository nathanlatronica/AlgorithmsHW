/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw2/challenges/binary-numbs/submissions/code/1316181576
 * Title: hw2_1.cpp
 * Abstract: outputs binary number up to n
 * Author: Nathan Latronica
 * ID: 1234
 * Date: 9/11/2019
 */

#include <iostream>
#include <vector> 
#include <math.h>       /* pow */
#include <string>
using namespace std;

int main() {
    int number, count;
    string result = "";
    vector<int> rems;
    
    cin >> count;
    
    int digits;
    if(count == 0) digits = 1;

    for(int i = 0; i < count; i++) {
        if(count==0 || count == 1) {
            digits = 1;
            break;
        }
        if(count == 2) {
            digits = 2;
        }
        if(pow(2,i) >= count) {
            digits = i;
            if (count % 4 == 0) digits++;
            break;
        }
    }
    
    
    
    for(int i = 0; i <= count; i++ ) {
         result = "";
         number = i;
        

        while(true) {
            
            if(i == 0) {
                rems.push_back(0);
            }
        
            if(number == 0) {
                break;
            }
            
            rems.push_back(number % 2);
            number = number / 2; 
        }

        for(int j = rems.size()- 1; j >= 0; j--) {
            result += to_string(rems[j]);
        }
        rems.clear();
        
        while(result.size() < digits) {
            result.insert(0, "0");
        }

        cout << result <<endl;
    }
    return 0;

}