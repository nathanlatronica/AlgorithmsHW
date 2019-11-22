/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw8/challenges/binary-tree-4/submissions/code/1317355191
 * Title: hw8_1.cpp
 * Abstract: performs various functions on data in a tree
 * Author: Nathan Latronica
 * ID: 1234
 * Date: 10/31/19
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void isBST(vector<int>nums, int T, vector<int>&nums2) {
    if(T >= nums.size()) {
        return ;
    }
    
    isBST(nums, T*2, nums2);
    nums2.push_back(nums[T]);
    isBST(nums, T*2 + 1, nums2);

}

int height(vector<int>nums, int T) {
    if(T >= nums.size()) {
        return -1;
    } else {
        return max(height(nums, T*2), height(nums, T*2 + 1)) + 1;
    }
}

void inOrder(vector<int>nums, int T) {
    if(T >= nums.size()) {
        return;
    }
    inOrder(nums, T*2);
    cout << nums[T] << " ";
    inOrder(nums, T*2 + 1);
    
}

void preOrder(vector<int>nums, int T) {
    if(T >= nums.size()) {
        return;
    }
    cout << nums[T] << " ";
    preOrder(nums, T*2);
    preOrder(nums, T*2 + 1);
    
}

void postOrder(vector<int>nums, int T) {
    if(T >= nums.size()) {
        return;
    }
    postOrder(nums, T*2);
    postOrder(nums, T*2 + 1);
    cout << nums[T] << " ";

}


int main() {
    int n, ops,temp;
    string sOps;
    cin >> n;
    
    vector<int> nums;
    nums.push_back(-1);
    for(int i = 0; i < n; i++) {
        cin >> temp;
        nums.push_back(temp);
    }
    cin >> ops;
    
    for(int i = 0; i < ops; i++) {
        cin >> sOps;
        
        if(sOps == "inOrder") {
            inOrder(nums, 1);
            cout << endl;
        }
        if(sOps == "preOrder") {
            preOrder(nums, 1);
            cout<<endl;
        }
        if(sOps == "postOrder") {
            postOrder(nums, 1);
            cout << endl;
        }
        if(sOps == "append") {
            cin >> temp;
            nums.push_back(temp);
            n++;
        }
        if(sOps == "height") {
            cout << height(nums, 1) << endl;
        }
        if(sOps == "isBST") {
            vector<int> nums2;
            isBST(nums, 1, nums2);
            bool isBSTB = true;
            for(int j = 0; j < nums2.size() -1 ; j++) {
                if(nums2[j] > nums2[j+1]) {
                    isBSTB = false;
                }
            }
            if(isBSTB) {
                cout << "true" <<endl;
            } else {
                cout << "false" <<endl;
            }
            nums2.clear();

        }
        
    }
    
    
    
    
}