/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw9/challenges/max-heap-1-2/submissions/code/1317687508
 * Title: hw9_1.cpp
 * Abstract: Performs heapsorting, and various heap functions
 * Author: Nathan Latronica
 * ID: 1234
 * Date: 11/14/2019
 */

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

bool heapify(int n, vector<int> &vec) {
    bool wasHeap = true;
    int left, right;
    for(int i = 0; i < n; i++) {
        for(int i = floor(n/2); i > 0; i--) {
            right = left = -1;
            if(i * 2 + 1 < vec.size()) {
                right = vec[i * 2 + 1];
            }
            if(i* 2 < vec.size()) {
                left = vec[i * 2];
            }
            if(right > left && right > vec[i]) {
                vec[i * 2 + 1] = vec[i];
                vec[i] = right;
                wasHeap = false;
            }
            if(left > right && left > vec[i]) {
                vec[i * 2] = vec[i];
                vec[i] = left;
                wasHeap = false;
            }
            
        }
    }
    return wasHeap;
     
 }

void del(int n, vector<int> &vec, int target) {
    int delIndex;
    bool isLast = false;
    for(int i = 1; i < n + 1; i++) {
        if(vec[i] == target) {
            delIndex = i;
            if(i == n) {
                isLast = true;
            }
            break;
        }
    }
    if(!isLast) {
       vec[delIndex] = vec[n];
       vec.pop_back();
       n--;
    }
    if(isLast) {
        vec.pop_back();
        n--;
    }

}

int main() {
    int n, temp, ops;
    vector<int> nums;
    nums.push_back(-1);
    cin >> n;

    for(int i = 0; i < n ; i++) {
        cin >> temp;
        nums.push_back(temp);
    }
    bool isHeap;
    
    //check if heap
    isHeap = heapify(n, nums);
    if(isHeap) {
        cout << "This is a heap." << endl;
    } else {
        cout << "This is NOT a heap." << endl;
    }
    
    //then proceed
    cin >> ops;
    string opType;
    int number;
    
    for(int i = 0; i < ops; i++) {
        cin >> opType;
    
        if(opType == "insert") {
            cin >> number;
            nums.push_back(number);
            n++;
            isHeap = heapify(n, nums);
        }
        if(opType == "deleteMax") {
            nums[1] = nums[n];
            nums.pop_back();
            n--;
            isHeap = heapify(n, nums);
        }
        
        if(opType == "display") {
            for(int i = 1; i < n + 1; i++) {
                cout << nums[i] << " ";
            }
            cout <<endl;
        }
        if(opType == "displayMax") {
            if (nums.size() >= 2) {
                cout << nums[1] << endl;
            }
        }
        if(opType == "delete") {
            cin >> number;
            del(n, nums, number);
            n--;
            isHeap = heapify(n, nums);
        }
        
        
    }
    
   
    
}
