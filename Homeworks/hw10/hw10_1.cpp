#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, temp, maxDig = 0;
    
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
    int matrix[n][maxDig + 1];
    for(int i = 0; i < n; i++) {
        matrix[0][i] = numbers[i];
    }
    
    int whatDig;
    for(int i = 0; i < maxDig; i++) {
        whatDig = maxDig - 1 - i;
        for(int j = 0; j < n; j++) {
            indexArray[j] = int(to_string(matrix[i][j])[whatDig] - 48); //problems with size 777 to 7 or 103 to 86
        }
        //cout Index Array
        cout << "index Array " <<endl;
        for(int u = 0; u < n; u++) {
            cout << indexArray[u] << " ";
        }
        cout << endl;
        //
        
        
        for(int j = 0; j < n; j++) {
            int min = 10, minIndex;
            for(int x = 0; x < n; x++) {
                if(indexArray[x] < min) {
                    min = indexArray[x];
                    minIndex = x;
                }
            }
            matrix[i + 1][j] = matrix[i][minIndex];
            cout << matrix[i + 1][j] << " ";
            indexArray[minIndex] = 10;
        }
        cout <<endl;
    }
    
    cout <<endl << "matrix:"<<endl;
    for(int i = 0; i < maxDig; i++){
        for(int j = 0; j < n; j++) {
            cout << matrix[maxDig][j] << " ";
        }
        cout << endl;
    }

    
    
}