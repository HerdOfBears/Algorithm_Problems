// Rosalind problem: Connected Components
// Uses Depth-First Search
/// DEPTH-FIRST SEARCH algorithm herein

#include <vector>
#include <iostream>

using namespace std;

vector<int>graph[1001];


void explore(int coloring_book[], int w ){

    int num_adj;
    int next_vertex;

    coloring_book[w] = 1; // mark that we have been to the vertex
    num_adj = graph[w].size(); // O(n)

    /*
    Room for PREVISIT operations
    Useful for when just arriving at a new vertex.
    */

    // move to next vertex, if there is one that hasn't been visited.
    for (int idx2 = 0; idx2 < num_adj; idx2++){
        next_vertex = graph[w][idx2];
        if ( coloring_book[next_vertex] == 0 ){
            explore(coloring_book, next_vertex);
        }
    }

    /*
    Room for POSTVISIT operations
    Useful for when this vertex is being left for the last time.
    */

}

int DFS(int num_verts){
    int coloring_book[num_verts];
    int num_connected_components = 0;

    // initialize the visitation logbook. I.e. coloring book
    for (int idx1 = 0;idx1<num_verts;idx1++){
        coloring_book[idx1] = 0; // 0 --> not visited yet
    }

    // Get a stating point from which searching stems.
    // If we did not choose new starting points, we would never be
    // able to find components not connected to each other.
    for (int idx1 = 0;idx1<num_verts; idx1++){
        if ( coloring_book[idx1] == 0 ){
            cout << "idx1 = " << idx1 << " num_verts = " << num_verts<<"\n";
            explore(coloring_book, idx1);
            num_connected_components += 1;
        }

    }

    return num_connected_components;

}


int main(){

    // input: edgelist fmt. The first line is n k
    // n <= 1000; the number of vertices
    // k is the number of edges

    freopen("C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/rosalind_cc.txt","r",stdin);

    int N;
    int k;
    // get number of vertices and number of edges
    scanf("%d %d",&N,&k);

    // make adjacency list
    // each row idx is a vertex, and the row contents are the adjacent vertices
    // limitation: vector structure is slower compared to an array

    //vector<int>graph[N];

    int v;
    int u;
    for (int idx1 = 0; idx1 < k; idx1++){
        scanf("%d %d",&v,&u);
        // the graph is undirected, adjacency is symmetric
        // i.e. if v~u, u~v
        // the given numbers are one indexed
        graph[v-1].push_back(u-1);
        graph[u-1].push_back(v-1);
    }
    // adjacency list built.

    // need a way to track what vertex we have been to,
    // and what vertices are nearby.
    // Untouched vertex = White = 0
    // Adjacent vertex = Gray = 1
    // Touched vertex = Black = 2
    //int coloring_book[N] = 0; // initially no vertext has been visited.

    int result;
    // depth-first search the graph called "graph"
    // Function input is number of vertices.
    result = DFS(N);

    cout << "number of connected components =\n" << result << "\n";

    return 0;
}
