/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw11/challenges/coin-collection-1-1/submissions/code/1318195912
 * Title: hw11_2.cpp 
 * Abstract: Finds max coins can pick up only going down or left avoiding certain spaces
 * Author: Nathan Latronica
 * ID: 1234
 * Date: 12/5/2019
 
    fails 2 test cases.
 
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    int x, y, temp;
    
    cin >> y >> x;
    
    int matrix[x][y];
    int final[x+1][y+1];
    
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            cin >> temp;
            if(temp == 2) {
                temp = -100;
            }
            matrix[i][j] = temp;
        }
    }
    //sets final
    for(int i = 0; i < x + 1 ; i++) {
        for(int j = 0; j < y + 1 ; j++) {
            final[i][j] = 0;
        }
    }    

    for(int k = 0; k < x+1; k++){
        final[k][0] = -1;
    }
    // for(int i = 1; i < y+1; i++){
    //     final[0][i] = -1;
    // }
    //final

    for(int i = 1; i < x+1; i++) {
        for(int j = 1; j < y+1; j++) {
            final[i][j] = max(final[i-1][j], final[i][j-1]) + matrix[i-1][j-1];
        }
    }    

    // //couting matrix
    cout <<endl;
    for(int i = 0; i < x + 1; i++) {
        for(int j = 0; j < y + 1; j++) {
            cout << final[i][j] << " ";
        }
        cout <<endl;
    }    
    // //matrix
    

    //backtrace
    int left, up;
    vector<string> results;
    int a = x, b = y;
    while(a != -1 && b != -1) {
       left = final[a][b-1];
       up = final[a-1][b];
       //push back
       if(a > 0 && b > 0)
       results.push_back("(" + to_string(b) + "," + to_string(a) + ")");

      if(left == -1) {
        if(up == -1) {
            break;
        }
         
      }
      
       if(left > up) {
           b--;
       } else {
           a--;
       }
       
       

    }

    cout<< "Max coins:" << final[x][y] <<endl;
    cout<<"Path:";
    cout << results[results.size()-1];
    for(int k = results.size()-2; k >= 0; k--) {
        cout<< "->" << results[k];
    }
    //backtrace
    
}