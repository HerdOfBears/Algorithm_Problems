#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Node{
    int a;
    int b;

    bool operator<(const Node &x)const{
        return a<x.a;
    }

    bool operator<(const &y)const{
        return a<y;
    }

    //bool operator>(const Node &x)const{
    //    return a>x.a;
    //}
};

int main(){

    Node X[4];
    X[0].a = 3;
    X[0].b = 1;
    X[1].a = 33;
    X[1].b = 2;
    X[2].a = 1;
    X[2].b = 3;
    X[3].a = 6;
    X[3].b = 4;

    for ( int idx=0; idx < 4; idx = idx + 1 ){
        cout << "idx = " << idx << "component a = " << X[idx].a;
        cout << "comp b = " << X[idx].b << "\n";
    }

    sort( begin(X), end(X) );

    cout << "After sorting." << "\n";
    for ( int idx=0; idx < 4; idx = idx + 1 ){
        cout << "idx = " << idx << " component a = " << X[idx].a;
        cout << " comp b = " << X[idx].b << "\n";
    }

    cout << "\n";
    vector<int>::iterator pos;
    cout << (lower_bound(X, X+4,5)-X);
    cout << (lower_bound(X, X+4,55)-X);
    //cout << (upper_bound(X, X+4,55)-X);

//    pos = upper_bound(X, X+4,6)
    //cout << (pos - 0);
    return 0;
}
