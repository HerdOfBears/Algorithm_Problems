// Author: Jyler
// Date: Feb 2018
// Rosalind problem: Permutations
// Given n <= 7, return (1) number of permutations, and (2) each permutation on a new line (in any order).

#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;

int get_factorial( int n ){
    if ( (n == 1) or (n == 0) ){
        return 1;
    }
    if ( n > 1 ){
        return ( n * get_factorial(n-1) );
    }
}

void print_arr( int arr[], int N ){
    ofstream output_file("C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/result_perm.txt",ios_base::app);

    for (int idx = 0; idx<N+1; idx++){
        cout << arr[idx] << " ";
        output_file << arr[idx] << " ";
    }
    cout << "\n";
    output_file << "\n";
}

void get_permute( int arr[], int i, int n ){

    if ( i==n ){
        // done
        cout << "arr = \n";
        print_arr(arr,n);
    }
    for (int j = i; j <= n; j++){
        swap(arr[i], arr[j]);
        get_permute(arr, i+1, n);
        swap(arr[i],arr[j]);
    }
}

int main(){

    int N;
    int p;

    freopen("C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/rosalind_perm.txt","r",stdin);
    scanf("%d", &N);

    //N = 3;
    p = get_factorial(N);

    cout << "Permutations = " << p << "\n";
    int perm_arr[N];
    for (int idx=0;idx<N;idx++){
        perm_arr[idx] = (idx+1);
    }

    get_permute(perm_arr, 0, (N-1));


    return 0;
}
