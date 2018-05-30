#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;


int main(){

    freopen("C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/rosalind_inv.txt","r",stdin);

    int N;

    scanf("%d", &N );

    int A[N];

    for (int idx=0; idx<N; idx++){
        scanf("%d", &A[idx] );
    }

    // Count inversions. I.e. number of indice pairs s.t. 1<=i<j<=N AND A[j]<A[i]
    // Nested loops O(n^2)?
    vector<int> v;
    int a1;
    int b1;
    __int64 ct_invs=0;
    for ( int idx1=0; idx1 < N; idx1 ++){
        a1 = A[idx1];

        for (int idx2=idx1; idx2 < N; idx2 ++ ){
            b1 = A[idx2];

            if ( a1 > b1 ){
                //cout << "We are finding inversions, right?\n";
                ct_invs = ct_invs + 1;
            }
        }
    }

    v.push_back(5);
    v.push_back(6);
    cout << "vec size = " << v.size();

    cout << std::setprecision(11);
    //cout << "large num = " << () << "\n";
    //cout << "'1' is now 0.0001 (divided by 10000)\n";
    cout << "\n";
    cout << "DONE\n";
    cout << "no. inversions = " << ct_invs << "\n";

    return 0;
}
