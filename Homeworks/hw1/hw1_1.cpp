/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw1/challenges/370-hw1-1/submissions/code/1316038492
 * Title: hw1_1
 * Abstract: finds the lowest difference between many numbers
 * Author: Nathan Latronica
 * ID:  1234
 * Date: 9/4/2019
 */
#include <iostream>
#include <vector> 
#include <climits>

using namespace std;

int main(){
    int n, small, large, x;
    int dis = INT_MAX;
    vector<int> nums; 
    
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> x;
        nums.push_back(x);
    }
    
    for(int i = 0; i < n; i++) {
        
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            
            if(abs(nums[i] - nums[j]) < dis) {
                dis = abs(nums[i] - nums[j]);
                small = min(nums[i], nums[j]);
                large = max(nums[i], nums[j]);
            }
            
        }
    }
    
    cout << "Min distance: " << dis << endl;
    cout << "Two numbers for min distance: " << small << " and " << large <<endl;
    return 0;
    
    
}