/*
 * Title: hw7_1.cpp
 * Abstract: Max Index of a max number, recursion
 * Author: Nathan Latronica
 * ID: 1234
 * Date: 10/24/2019
 */

#include <iostream>
#include<algorithm> 
using namespace std;

 //finds the max number

// int MaxIndex (int A[ ], int start, int end) {
//     if (start == end) {
//         return A[start];
//     }
//     else {
//         int sum1 = MaxIndex (A, start, (start+end)/2);
//         int sum2 = MaxIndex (A, (start+end)/2+1, end);
//         return max(sum1, sum2);
        
//     }
// }

// finds max index
int Max_num(int nums[],int index, int maxIndex, int size){
 
    if (index==size) {
        return maxIndex;
    }
    else
        if (nums[index]>nums[maxIndex]) {
            maxIndex=index;
        }
 
     
    Max_num(nums,index+1,maxIndex,size);
}




int main() {
    int n, temp;
    
    cin >> n;
    int nums[n];
    
    for(int i = 0; i < n; i++) {
        cin >> temp;
        nums[i] = temp;
    }


    // int answer = MaxIndex(nums, 0, n-1 );
    int answer = Max_num(nums, 0, 0, n);
    cout << "Max Index: " << answer;

    return 0;
}


