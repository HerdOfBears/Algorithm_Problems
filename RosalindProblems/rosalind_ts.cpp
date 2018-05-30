// Rosalind problem: topological sorting
// idea: use DFS plus a 'dynamic programming' (ask Samee if counts as DP) array to keep track of where we have searched already.
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int>graph[1001];

void init(int n){ // n is number of vertices in graph

    for (int idx=0; idx<n;idx++){
        graph[idx].clear();
    }
}


void explore(int coloring_book[], int w, int previ ){

    int num_adj;
    int next_vertex;

    // it should only equal the previous vector at the starting point.
    if (w != previ){
        coloring_book[w] += coloring_book[previ];//1; // mark that we have been to the vertex
    }
    num_adj = graph[w].size(); // O(n)

    /*
    Room for PREVISIT operations
    Useful for when just arriving at a new vertex.
    */

    // move to next vertex, if there is one that hasn't been visited.
    for (int idx2 = 0; idx2 < num_adj; idx2++){
        next_vertex = graph[w][idx2];
        if (1){//( coloring_book[next_vertex] == 0 ){
            explore(coloring_book, next_vertex, w);
        }
    }

    /*
    Room for POSTVISIT operations
    Useful for when this vertex is being left for the last time.
    */
}

void DFS(int coloring_book[], int num_verts, int strt){
    //int coloring_book[num_verts];

    // initialize the visitation logbook. I.e. coloring book
    // the coloring book is going to be dynamically filled.
    for (int idx1 = 0;idx1<num_verts;idx1++){
        coloring_book[idx1] = 1; // 0 --> not visited yet
    }

    // Get a stating point from which searching stems.
    // If we did not choose new starting points, we would never be
    // able to find components not connected to each other.
    if ( coloring_book[strt] == 1 ){
        cout << "strt = " << strt << " num_verts = " << num_verts<<"\n";
        explore(coloring_book, strt,strt);
    }

}



int main(){

    // read in the graph
    // input file fmt: simple edge list.
    freopen("C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/ex_ts.txt","r",stdin);

    int N; // number of vertices
    int k; // number of edges
    scanf("%d %d",&N,&k);

    // make graph/adj_list
    int u;
    int v;
    int start;
    for (int idx1=0;idx1<k;idx1++){
        scanf("%d %d", &u, &v);
        graph[u-1].push_back(v-1); // directed graph.

        // directed graph, so we want the starting point.
        if ( idx1 == 0 ){
            start = (u-1);
        }
    }

    int logbook[N];
    DFS(logbook, N, start);

    sort( logbook, logbook + N );

    for (int idx1 = 0; idx1<N; idx1++){
        cout << logbook[idx1] << " ";
    }


    return 0;
}



