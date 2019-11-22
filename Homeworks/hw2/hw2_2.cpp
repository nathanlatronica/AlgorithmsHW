/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw2/challenges/time-difference-2/submissions/code/1316183424
 * Title: hw2_2.cpp
 * Abstract: Compares two timestamps
 * Author: Nathan Latronica
 * ID: 1234
 * Date: 9/11/2019
 */

#include <iostream>
#include <string>
using namespace std;


int main() {
    string one, two, result = "", temp1 = "", temp2 = "";
    int secOne = 0, secTwo = 0, secAnswer;
    
    
    cin >> one >> two;
    
    for(int i=0; i <8; i+=3) {
        temp1 += one[i];
        temp1 += one[i+1];
        temp2 += two[i];
        temp2 += two[i+1];
        if(i == 0) {
            secOne += (60 * 60) * stoi(temp1);
            secTwo += (60 * 60) * stoi(temp2);
        }
        if(i == 3) {
            secOne += 60 * stoi(temp1);
            secTwo += 60 * stoi(temp2);            
        }
        if(i == 6) {
            secOne += stoi(temp1);
            secTwo += stoi(temp2);             
        }
        temp1 = "";
        temp2 = "";
   
    }
    
    if(secOne < secTwo) {
        secAnswer = secTwo - secOne;
        
    } else if(secOne > secTwo){
        secOne = 86400 - secOne;
        secAnswer = secOne + secTwo;
    } else {
        secAnswer = 0;
    }
    
    // secs to hour
    int hour = secAnswer / 3600;
    secAnswer = secAnswer % 3600;
    int min = secAnswer / 60;
    int sec = secAnswer % 60;
    
    result += to_string(hour) + ":";
    if(result.size() < 3) result.insert(0, "0");
    result += to_string(min) + ":";
    if(result.size() < 6) result.insert(3, "0");
    result += to_string(sec) ;
    if(result.size() < 8) result.insert(6, "0");
    
    cout << result <<endl;
   
    return 0;

}