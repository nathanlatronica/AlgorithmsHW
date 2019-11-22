/*
 * HackerRank 
 * Title: hw4_3.cpp
 * Abstract: TSP couldn't get it to work fully. 
 * Author: Nathan Latronica
 * ID: 1234
 * Date: 9/26/19
 */
 
#include <iostream>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;


int main() {
    int n, n2;
    int result = INT_MAX, tempRes;
    string place;
    unordered_map<string, int> placeIndex;
    unordered_map<int, string> indexPlace;

    string from ="", dest = "";
    int cost;
    
    cin >> n;
    int matrix[n][n];
    int forperms[n];

    for(int i = 0; i < n; i++){
        cin >> place;
        placeIndex[place] = i;
        indexPlace[i] = place;
        forperms[i] = i;
    }
    
    
    cin >> n2;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            matrix[i][j] = -1;
            if(i == j){
                matrix[i][j] = -2;
            }
        }
    }

    for(int i = 0; i < n2; i++) {
        cin >> from >> dest >> cost;
        matrix[placeIndex[from]][placeIndex[dest]] = cost;
    }
    //cout matrix, Some reason i get rid of this and it errors.
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }    
        cout <<endl;
    }

    
    // permutations
    int a[n-1];
    string path = "0";
    for(int i = 1; i < n; i++) {
        a[i] = i;
    }
    bool add = true;

    
	sort(a, a + (n- 1)); 
	do 
	{ 
	    for(int i = 0; i < n-1; i++) {
	        cout << a[i] ;
	    }
	    cout <<endl;
	    
	    add = true;

	    if(matrix[0][a[0]] >= 0) {
	        tempRes = matrix[0][a[0]];
	    } else {
	        add = false;
	    }

	    for(int i = 0; i < n-2; i++) {
	        if(matrix[a[i]][a[i+1]] >= 0) {
	            tempRes += matrix[a[i]][a[i+1]];
	        } 
	        if (matrix[a[i]][a[i+1]] < 0) {
	            add = false;
	        }
	    }
	    if(matrix[a[n-1]][0] >= 0) {
	        tempRes += matrix[a[n-1]][0];
	    } else {
	        add = false;
	    }
	    
	    
	    if(tempRes < result && add) {
	        result = tempRes;
	        path = "0";
	        for(int j = 0; j < n- 1; j++) {
	            path += to_string(a[j]);
	        }
	    }


	} while (next_permutation(a, a + n-1)); 

    cout << "Path:";
    for(int i = 0; i < path.size(); i++) {
        cout << indexPlace[int(path[i])-48] << "->";
    }
    cout << indexPlace[int(path[0])-48] <<endl;
    
    cout << "Cost: " << result;
}