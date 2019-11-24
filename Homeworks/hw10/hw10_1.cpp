/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw10/challenges/radix-sort-4-1/submissions/code/1317853921
 * Title: hw10_1.cpp    
 * Abstract: Radix Sort
 * Author: Nathan Latronica
 * ID: 1234
 * Date: 11/22/2019
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, temp, maxDig = 0;
    int min = 10, minIndex;
    
    cin >> n;
    int indexArray[n];
    int numbers[n];
    
    
    for(int i = 0; i < n; i++) {
        cin >> temp;
        numbers[i] = temp;
        if(to_string(temp).size() > maxDig) {
            maxDig = to_string(temp).size(); 
        }
    }
    int results[maxDig + 1][n];
    for(int i = 0; i < n; i++) {
        results[0][i] = numbers[i];
    }

    int whatDig = 1;
    for(int i = 0; i < maxDig; i++) {
        
        for(int j = 0; j < n; j++) {
            if(int(to_string(results[i][j]).size()) - whatDig <= -1) {
                indexArray[j] = 0;
            } else {
                indexArray[j] = int(to_string(results[i][j])[to_string(results[i][j]).size() - whatDig] - 48); 
            }    
        }
        whatDig++;
        for(int j = 0; j < n; j++) {
            min = 10;
            minIndex = 10;
            for(int x = 0; x < n; x++) {
                if(indexArray[x] < min) {
                    min = indexArray[x];
                    minIndex = x;
                }
            }
            results[i + 1][j] = results[i][minIndex];
            indexArray[minIndex] = 10;
        
        }
    } 
     
    for(int i = 1; i < maxDig + 1; i++){
        for(int j = 0; j < n; j++) {
            cout << results[i][j] << " ";
        }
        cout << endl;
    }

    
    
}