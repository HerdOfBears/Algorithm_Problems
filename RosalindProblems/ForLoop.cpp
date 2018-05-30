#include <iostream>
using namespace std;

// Simple loop with cycle within.
int main(){
    // for loop execution
    for (int i = 0; i<16; i=i + 1){
        if ( (i % 2) == 0 ) {
            cout << "This number, i = " << i << " is even." << endl;
        }
        if ( (i % 2) == 1 ) {
            cout << "This number, i = " << i << " is odd." << endl;
        }
    }

    return 0;
}
