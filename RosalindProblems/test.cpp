#include<cstdio>
#include<iostream>
#include <algorithm>

using namespace std;

struct Node{
    int a;
    int b;

    bool operator<(const Node &x )const{
        return a<x.a;
    }
};

int main(){
    freopen("C:/Users/Jyler/Documents/ProgrammingProjects/cplusplus/in.txt","r",stdin);

    int a1,b1;

    scanf("%d %d", &a1, &b1);
    //int X[b];
    Node X[b1];

    for (int idx=0; idx<b1; idx++){
        scanf("%d", &X[idx].a);
        X[idx].b = (idx + 1);
    }
    cout << "Done reading file.\n";
    cout << "X = " << X[0].a << " " << X[1].a << " " << X[2].a << " " << X[3].a << "\n";
    cout << "X = " << X[0].b << " " << X[1].b << " " << X[2].b << " " << X[3].b << "\n";

    sort( X, X + b1 );
    cout << "After sorting:\n";
    cout << "X = " << X[0].a << " " << X[1].a << " " << X[2].a << " " << X[3].a << "\n";
    cout << "X = " << X[0].b << " " << X[1].b << " " << X[2].b << " " << X[3].b;


    // the percent sign d is used to specify what kind of format to look
    // when reading the stream. %b means look for a non-whitespace
    // character of that is a signed decimal integer (0-9)
    //for (int idx = 0;idx < 3; idx++){
      //  scanf("%d",&X[idx]);
    //}
    //scanf("%d %d",&a,&b);
    //cout << "a = " << a << " b = " << b;
    //cout << X[0] << " " << X[1] << " " << X[2];

    //for(i=0;i<a;i++){\
        for(j=0;j<b;j++){
    //        scanf("")
     //   }
    //}
}
