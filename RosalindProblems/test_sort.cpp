#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Sorts a vector.
// Example of how to implement.
int main(){

    vector<int>vec;

    vec.push_back(4);
    vec.push_back(2);
    vec.push_back(55);
    vec.push_back(1);

    for (int idx=0; idx<vec.size();idx = idx + 1){
        cout << "value at " << idx << " is " << vec[idx] << endl;
    }

    sort( vec.begin(), vec.end() );

    for (int idx=0; idx<vec.size();idx = idx + 1){
        cout << "value at " << idx << " is " << vec[idx] << endl;
    }


    return 0;
}
