/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw6/challenges/apple-collection/submissions/code/1317039464
 * Title: hw6_1.cpp
 * Abstract: Figures out the max apples in n boxes with given requirments
 * Author: Nathan Latronica
 * ID: 1234
 * Date: 10/17/2019
 */

#include <iostream>
#include <string>
#include <math.h> 
#include <vector>
using namespace std;

int main() {
    string binary, whenToStop;
    int max = 0, counter;
    int numBoxes;
    int apples;
    bool check = true;
    
    cin >> numBoxes;
    
    int arBoxes[numBoxes];
    
    for(int i = 0; i < numBoxes; i++) {
        cin >> apples;
        arBoxes[i] = apples;
        binary += '0';
        whenToStop += '1';
    }
    
    while(binary != whenToStop) {
        //checks 2 1's next to each other
        check = true;
        for(int i = 0; i < binary.length() -1; i++) {
            if(binary[i] == '1' && binary[i+1] == '1') {
                check = false;
                break;
            }
        }
        //end of check
        // add the apples up
        if(check) {
            counter = 0;
            for(int i= 0; i < binary.length(); i++) {
                if(binary[i] == '1') {
                    counter += arBoxes[i];
                }
            }
            if(counter > max) {
                max = counter;
            }
        }
        //end of add
        //increase the binary number/string
        int binaryNum = 0, numBoxes2 = numBoxes-1;
        vector<int> convert;
        
        for(int j = 0; j < binary.size(); j++) {
            binaryNum += (int(binary[j]) - 48) * (pow(2, numBoxes2));
            numBoxes2--;
        }
        binaryNum++; 
        
        while(binaryNum > 0) {
            convert.push_back(binaryNum % 2);
            binaryNum /= 2;
        } 
        
        binary = "";
        for(int j = convert.size()- 1; j >= 0; j--) {
            binary += to_string(convert[j]);
        }
        convert.clear();
        
        while(binary.size() < numBoxes) {
            binary.insert(0, "0");
        }
        //end of increase binary num/string
    }
    
    
    
    cout << "Max Apples: " << max << endl;
}