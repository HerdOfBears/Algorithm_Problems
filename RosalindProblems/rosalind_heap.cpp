// Rosalind problem: Building a heap NOT FINISHED
// Author: Jyler Menard
// Date: Feb 2018

#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    freopen("C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/ex_heap.txt")

    int N;
    scanf("%d",N);

    int A[N];

    for (int idx = 0; idx<N; idx++){
        scanf( "%d", A[idx] );
    }

    sort( A.begin(), A.end() );

    for (int idx=N-1;idx>-1;idx = idx - 1){

    }

    return 0;
}
