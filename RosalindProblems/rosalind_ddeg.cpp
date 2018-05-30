#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

// Ask Samee about building an adjacency list, and maybe a better way of doing
// this in general.


int main(){

    freopen("C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/rosalind_ddeg.txt","r",stdin);

    int n_vert;
    int n_edges1;
    int n_edges;
    n_edges = 9877;

    scanf("%d %d", &n_vert, &n_edges1);

    cout << "n_vert = " << n_vert << " n_edges = " << n_edges << "\n";

    int num_adj[n_vert] = { 0 }; // To count number of neighbours
    //int v_adj[n_vert][n_edges] = { 0 }; // To keep track of who is connected to whom.

    int(*v_adj)[9877] = new int[n_vert][9877];

    cout <<"hello\n";

    int v1;
    int v2;

    for (int idx=0; idx < n_edges; idx++){
        scanf( "%d %d", &v1, &v2 );

        num_adj[v1-1] = num_adj[v1-1] + 1;
        num_adj[v2-1] = num_adj[v2-1] + 1;

        cout << "v1 = " << v1 << " v2 = " << v2 << "\n";

        for (int idx2=0; idx2 < n_edges; idx2++ ){
            // v1-1 and not v1 because the given list calls the first vertex
            // 1, while the array stores it as 0.

            if ( v_adj[v1-1][idx2] == v2 ){
                // Can't be connected to the same vertext twice.
                break;
            }
            if ( v_adj[v1-1][idx2] == 0 ){
                // add vertex v2 to the list of vertices connected to vertex v1.
                v_adj[v1-1][idx2] = v2;
                break;
            }
        }
        for (int idx2=0; idx2 < n_edges; idx2++ ){
            // Why v2-1? See previous loop.
            if ( v_adj[v2-1][idx2] == v1 ){
                // Can't be connected to the same vertext twice.
                break;
            }
            if ( v_adj[v2-1][idx2] == 0 ){
                // add vertex v1 to the list of vertices connected to vertex v2.
                v_adj[v2-1][idx2] = v1;
                break;
            }
        }
    }
    int tot_ddeg[n_vert] = { 0 };
    // Now need to count up the number of neighbours every neighbour has.
    for ( int idx=0; idx < n_vert; idx++ ){
        // fix vertex
        for ( int idx2=0; idx2 < num_adj[idx]; idx2++ ){
            // count which vertices the fixed one is attached to.
            if ( v_adj[idx][idx2] == 0 ){
                break;
            }

            tot_ddeg[idx] = tot_ddeg[idx] + num_adj[ (v_adj[idx][idx2] - 1) ];
        }
    }

    cout << "Done\n";
    cout << "writing\n";

    ofstream output_file("C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/result_ddeg.txt",ios_base::app);

    for (int idx=0; idx < n_vert; idx++ ){
        output_file << tot_ddeg[idx] << " ";
    }
    cout << "Done writing.";
    return 0;
}
