#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node{
    int a;
    int b;

    bool operator<(const Node &x )const{
        return a<x.a;
    }

    bool operator<(const &y)const{
        return a<y;
    }

};

//Node A[1000005];
int main(){

    freopen("C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/rosalind_3sum.txt","r",stdin);


    int n,k;

    scanf("%d %d", &n, &k);
    //int X[b];
    Node A[k];


    for (int idx1=0; idx1<n; idx1++){
        cout << "iteration = " << idx1 + 1 << "\n";

        for (int idx=0; idx<k; idx++){
            scanf("%d", &A[idx].a);
            A[idx].b = idx + 1;
        }

    //            int A[];
                // Get all of the integers in the given array (a stringstream)
                // put all of them into a vector, A.
                //vector<int>A;
        int n;
        int num_A = 0;

            //sort( A.begin(), A.end() );
        sort( A, A + k );
       //         for (int idx=0;idx<A.size(); idx = idx + 1){
      //              cout << "stuff in array at pos " << idx << " is = " << A[idx] << "\n";
        //        }
                //cout << "word = " << word << "\n";
        int previously_seen;
        int temp_r;

        temp_r = 0;
        previously_seen = 1000000;
        // Size of Node object is k.
        for (int idx_a=0; idx_a < k; idx_a = idx_a + 1){
            int a1;

            a1 = A[idx_a].a;
                // Waste of time to recheck duplicates.
            if ( previously_seen == a1 ){
                continue;
            }
            previously_seen = a1;

            // Because the values are sorted, and because we are looking
            // for two numbers a,b, s.t. a=-b, once we won't have to look at the positive
            // values with this outer loop -- it is done by the inner loop.
            if (a1 > 0){
                break;
            }
            if (temp_r == 1){
                break;
            }

            for (int idx_b = idx_a+1; idx_b < k; idx_b = idx_b + 1){
                int b1;
                int c;
                int poten_pos;

                b1 = A[idx_b].a;
                c = (-1)*(a1 + b1); // Need to binary search on c.
                poten_pos = (lower_bound(A, A+k, c) - A);

                if ( (A[poten_pos].a == c) && (A[poten_pos].b != A[idx_b].b) && (A[poten_pos].b != A[idx_a].b) ){
                    cout << "Found THREE numbers s.t. a + b + c = 0\n";
                    cout << "a = " << a1 << "\n" << "b = " << b1 << "\n";
                    cout << "c = " << c << "\n";

                    ofstream output_file("C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/result_3sum.txt",ios_base::app);
                    int v[3];
                    v[0] = A[idx_a].b;
                    v[1] = A[idx_b].b;
                    v[2] = A[poten_pos].b;
                    sort( begin(v), end(v) );
                    output_file << v[0] << " " << v[1] << " " << v[2] << "\n";

                    temp_r = 1;
                    break;
                }

                if ( (poten_pos + 1) == k ){
                    if ( A[poten_pos-1].a == c ){
                        if ( (A[poten_pos-1].a == c) && (A[poten_pos-1].b != A[idx_b].b) && (A[poten_pos-1].b != A[idx_a].b) ){
                        cout << "Found THREE numbers s.t. a + b + c = 0\n";
                        cout << "a = " << a1 << "\n" << "b = " << b1 << "\n";
                        cout << "c = " << c << "\n";
                        temp_r = 1;

                        ofstream output_file("C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/result_3sum.txt",ios_base::app);
                        int v[3];
                        v[0] = A[idx_a].b;
                        v[1] = A[idx_b].b;
                        v[2] = A[poten_pos-1].b;
                        sort( begin(v), end(v) );
                        output_file << v[0] << " " << v[1] << " " << v[2] << "\n";

                        break;
                        }

                    }
                }
                if ( (poten_pos - 1) == -1 ){
                    if ( A[poten_pos+1].a == c ){
                        if ( (A[poten_pos+1].a == c) && (A[poten_pos+1].b != A[idx_b].b) && (A[poten_pos+1].b != A[idx_a].b) ){
                        cout << "Found THREE numbers s.t. a + b + c = 0\n";
                        cout << "a = " << a1 << "\n" << "b = " << b1 << "\n";
                        cout << "c = " << c << "\n";
                        temp_r = 1;

                        ofstream output_file("C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/result_3sum.txt",ios_base::app);
                        int v[3];
                        v[0] = A[idx_a].b;
                        v[1] = A[idx_b].b;
                        v[2] = A[poten_pos+1].b;
                        sort( begin(v), end(v) );
                        output_file << v[0] << " " << v[1] << " " << v[2] << "\n";

                        break;
                        }

                    }
                }


                if (0){//( a1 + b1 == 0){
                    cout << "Found two numbers s.t. their sum is zero\n";
                    cout << "a = " << a1 << "\n" << "b = " << b1 << "\n";
                    cout << "idx_a = " << idx_a << " idx_b = " << idx_b << "\n";
                    cout << "pos a = " << A[idx_a].b << " pos b = " << A[idx_b].b << "\n";
                    temp_r = 1;

                    ofstream output_file("C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/result_3sum.txt",ios_base::app);
                    int v[3];
                    v[0] = A[idx_a].b;
                    v[1] = A[idx_b].b;
                    v[2] = poten_pos + 1;
                    sort(begin(v), end(v) );
                    output_file << v[0] << " " << v[1] << " " << v[2] << "\n";

                    break;
                }
            }
        }
        if (temp_r == 0){
            cout << "There are no three numbers\n";
            cout << "-1\n";
            ofstream output_file("C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/result_3sum.txt",ios_base::app);
            output_file << "-1\n";
        }

    }
    cout << "\nn = " << n;
    return 0;
}


// TODO:
// 1. Make vector of 2-tuples, call each one tpl. tpl[0] will be the value at index tpl[1] of the given array.
// 2. Sort it.
// 3. Write index positions to a file.
