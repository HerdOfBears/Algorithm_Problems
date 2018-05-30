// Rosalind problem: Merge Sort
// Author: Jyler Menard
// Date: Feb 2018

#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>

using namespace std;
int tester=0;

void print_arr(int y[]){

    cout << "array = ";
    for ( int ii = 0; ii < 10; ii++ ){
        //cout << "tst ";
        cout << y[ii] << " ";
    }
    cout << "\n";
}

void merge_sort(int x[], int a, int b, int size_arr){

    // if size == 1: do nothing
    if (size_arr < 2 ){
        print_arr(x);
    }
    // if size == 2: check if the elems need swapping.
    if (size_arr == 2 ){
        if ( x[a] < x[b] ){
            tester = 0;
        }
        if ( x[b] < x[a] ){
            swap( x[a], x[b] );
            tester = 1;
        }
    }

    // if size > 2: we have to recurse.
    if (size_arr > 2){
        int mid_pt;

        mid_pt = (b + a)/2;

        // Recurse
        merge_sort(x, a, mid_pt, (mid_pt - a + 1) );
        merge_sort(x, (mid_pt+1), b, (b - mid_pt) );

        // Do work on combining sub sequences.
        int temp_lhs[mid_pt-a+1];
        int temp_rhs[b-mid_pt];

        for (int temp_idx = a; temp_idx < b+1; temp_idx++){
            if ( temp_idx <= mid_pt ){
                temp_lhs[ (temp_idx - a) ] = x[temp_idx];
            }
            if ( temp_idx > mid_pt ){
                temp_rhs[temp_idx-mid_pt-1] = x[temp_idx];
            }

        }

        int cts_lhs = 0;
        int cts_rhs = 0;
        int N_lhs = (sizeof(temp_lhs)/sizeof(int));
        int N_rhs = (sizeof(temp_rhs)/sizeof(int));

        // if there are more elements in the lhs, iterate up to the
        // size of the rhs.
        if (1){//( (mid_pt + 1 - a) > (b - mid_pt + 1) ){
            for (int temp_idx=0; temp_idx < (b - a +1 ); temp_idx++ ){
                // Check if one of the sorted subseqs has been used.
                if ( ((cts_lhs ) == N_lhs) or ((cts_rhs) == N_rhs) ){
                    if ( (cts_lhs ) == N_lhs ){
                        x[a+temp_idx] = temp_rhs[cts_rhs];
                        cts_rhs = cts_rhs + 1;
                        continue;
                    }
                    if ( (cts_rhs ) == N_rhs ){
                        x[a+temp_idx] = temp_lhs[cts_lhs];
                        cts_lhs = cts_lhs + 1;
                        continue;
                    }
                }

                if ( temp_lhs[cts_lhs] < temp_rhs[cts_rhs]){
                    x[a+temp_idx] = temp_lhs[cts_lhs];
                    cts_lhs = cts_lhs + 1;
                    continue;
                }
                if ( temp_lhs[cts_lhs] > temp_rhs[cts_rhs] ){
                    x[a+temp_idx] = temp_rhs[cts_rhs];
                    cts_rhs = cts_rhs + 1;
                    continue;
                }
                if ( temp_lhs[cts_lhs] == temp_rhs[cts_rhs] ){
                    x[a+temp_idx] = temp_lhs[cts_lhs];
                    cts_lhs = cts_lhs + 1;
                    continue;
                }
            }
        }

    }
}


int main(){

    freopen("C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/rosalind_ms.txt","r",stdin);

    cout << "Found file.";
    int N;
    scanf("%d",&N);
    //N = 9;
    cout << "First line. N = " << N << "\n";
    int A[N];
    //int B[N/2];
    cout << "Constructing array: \n";
    for (int idx = 0; idx < N; idx++){
        scanf( "%d", &A[idx] );
    }

    cout << "size of A = " << (sizeof(A)/sizeof(int)) << "\n";
    merge_sort( A,0,(N-1),N);

    ofstream output_file("C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/result_ms.txt",ios_base::app);
    for (int idx = 0; idx < N; idx++){
        if ( (idx+1) == N ){
            output_file << A[idx];
            break;
        }
        output_file << A[idx] << " ";
    }

    cout << "DONE";
    return 0;
}
