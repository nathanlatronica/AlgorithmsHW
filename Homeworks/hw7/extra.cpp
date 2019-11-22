
#include <iostream>
#include<algorithm> 
using namespace std;

int algo(int n) {
    if (n == 1) {
        return 1;
    } else {
        return algo(n-1) + 2 * n - 1;
    }
    
}

int main () {
    
    for(int i = 1; i < 10; i++) {
        cout << i <<": " << algo(i) << endl;
    }
    
}