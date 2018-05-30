#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

int main(){

    freopen("C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/rosalind_med.txt","r",stdin);

    int N;

    scanf("%d", &N );

    int A[N];

    for (int idx=0; idx < N; idx++ ){
        scanf("%d", &A[idx] );
    }

    int k;
    scanf("%d", &k );

    sort( A, A+N );

    int previous;
    int counter=1;
    int result_k;

    previous = 200000;
    for (int idx=0; idx<N; idx++){
        if ( counter == k ){
            result_k = A[idx];
            break;
        }
        //if ( previous == A[idx] ){
        //    continue;
        //}
        //previous = A[idx];
        counter = counter + 1;

    }

    cout << "Done\n";
    cout << "result = " << result_k;
    ofstream output_file("C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/result_med.txt", ios_base::app);
    output_file << result_k;

    return 0;
}
