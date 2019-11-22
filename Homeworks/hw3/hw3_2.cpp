/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw3/challenges/equal-groups/submissions/code/1316398778
 * Title: hw3_2.cpp
 * Abstract: finds two sets that sum to the same
 * Author: Nathan Latronica
 * ID: 1234
 * Date: 9/19/19
 */
#include <iostream>
#include <string>
#include <climits>
#include <vector>
#include <math.h>  
using namespace std;

int main() {
    int n, x;
    bool answer = false;
    vector<int> nums;

    cin >> n;
    
    int tempN = n;
    int digits = 1;
    string dig = "0";
    while(tempN > 1) {
        digits++;
        tempN /= 2;
    }
    for(int i = n; i > 1; i--) {
        dig += '0';
    }
    

    for(int i = 0; i < n; i++) {
        cin >> x;
        nums.push_back(x);
    }


    int sum1 = 0, sum2 = 0;

    for(int i = 0; i < pow(n, 2); i++) {
        
        for(int j = 0; j < dig.size(); j++) {
            if(dig[j] == '0') {
                sum1 += nums[j] ;
                
            } else {
                sum2 += nums[j] ;
            }
            

        }
        if(sum1 == sum2 ) {
            answer = true;
            break;
        }
        sum1 = 0;
        sum2 = 0;        
        //turn string into int
        //add one to the int
        //convert binary to int
        int NumDig = 0, tempdig = n - 1;

        for(int j = 0; j < dig.size(); j++) {
            NumDig += (int(dig[j]) - 48) * (pow(2, tempdig));
            tempdig--;
        }
        NumDig++;

        //turn it back into a string
        //update the string
        
        vector<int> convert;
        
        while(NumDig > 0) {
            convert.push_back(NumDig % 2);
            NumDig /= 2;
        }
        
        dig = "";
        for(int j = convert.size()- 1; j >= 0; j--) {
            dig += to_string(convert[j]);
        }
        convert.clear();
        
        while(dig.size() < n) {
            dig.insert(0, "0");
        }

    }
    
    if(answer) {
        char l = 'z';
        int min = INT_MAX, delIndex;
        string set = "Equal Set: ";
        for (int i = 0; i < dig.size(); i++) {
            if(nums[i] < min) {
                min = nums[i];
                l = dig[i];
            }
        }
        
        int loop = 0;
        for(int i = 0; i < dig.size(); i++) {
            if(dig[i] == l) {
                loop++;
            }
        }
        
        for(int i = 0; i < loop; i++) {
            min = INT_MAX;
            
            for(int j = 0; j < nums.size(); j++) {
                if(dig[j] == l) {
                    if(nums[j] < min) {
                        min = nums[j];
                        delIndex = j;
                    }
                    
                }
                
            }
            nums[delIndex] = INT_MAX;
            set += to_string(min) + " ";
        }
        
        
        
        
        cout << set <<endl;
        
    } else {
        cout << "Equal Set: 0" <<endl;
        
    }
    return 0;
    
}