/*
 * HackerRank link:
 * Title:  hw1_2.cpp
 * Abstract: finds intersecting range times
 * Author: Nathan Latronica
 * ID: 1234
 * Date: 9/4/2019
 */
#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    /* Have to find largest of starting ranges and smallest of ending ranges and check that they are all in  */
    int largeStart, smallEnd;
    int start, end;
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        
        cin>>start>>end;
        
        if(i == 0) {
            smallEnd = end;
            largeStart = start;
            continue;
        }
        if(start > largeStart) {
            largeStart = start;
        }
        if(end < smallEnd) {
            smallEnd = end;
        }
        
    }
    
    if(largeStart > smallEnd) {
        cout << "-1" <<endl;
    } else {
        cout << largeStart << " " << smallEnd <<endl;
    }
    return 0;
}