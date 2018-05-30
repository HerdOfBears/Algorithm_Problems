// Rosalind problem: detect acyclicity in a directed graph
// DFS problem.


#include <vector>
#include <iostream>

using namespace std;

vector<int>graph[1001];


int n; // number of vertices.

void init(int vrts){
    int i;
    for(i=0;i<=vrts;i++){
        graph[i].clear();
    }
}

int explore(int coloring_book[], int w, int prev ){

    int num_adj;
    int next_vertex;
    int r=-1;

    coloring_book[w] = 1; // mark that we have been to the vertex
    num_adj = graph[w].size(); // O(n)

    /*
    Room for PREVISIT operations
    Useful for when just arriving at a new vertex.
    */

    // move to next vertex, if there is one that hasn't been visited.
    for (int idx2 = 0; idx2 < num_adj; idx2++){
        //r = -1;
        next_vertex = graph[w][idx2];
        /*
        cout <<"prev vertex = " << prev << "\n";
        cout <<"current vertex = " << w << "\n";
        cout << graph[w][0] <<graph[w][1] <<graph[w][2] << "\n";
        cout <<"next vertex = " << next_vertex << "\n";
        cout << "r = " << r << "\n";
        cout <<"coloring book before = " << coloring_book[next_vertex]<<"\n";
        */
        if ( coloring_book[next_vertex] == 1){
            r = 1;
        }
        if ( coloring_book[next_vertex] == 0 ){
            r = explore(coloring_book, next_vertex, w);
          //  cout << "r after = " << r << "\n";
          //  cout <<"coloring book after = " << coloring_book[next_vertex]<<"\n";
        }
        if ( r==1){//(coloring_book[next_vertex] == 1) or (r == 1) ){
            //cout << "found a loop\n";
            return 1;
        }
    }

    /*
    Room for POSTVISIT operations
    Useful for when this vertex is being left for the last time.
    */

    return r; // if there is no cycle, then we never visited a node twice, hence r = -1
}

int DFS(int num_verts, int src){
    int coloring_book[num_verts];
    int num_connected_components = 0;
    int r2=-1;

    // initialize the visitation logbook. I.e. coloring book
    for (int idx1 = 0;idx1<num_verts;idx1++){
        coloring_book[idx1] = 0; // 0 --> not visited yet
    }

    // Get a stating point from which searching stems.
    // If we did not choose new starting points, we would never be
    // able to find components not connected to each other.
    if (1){//for (int idx1 = 0;idx1<num_verts; idx1++){
        if ( coloring_book[src] == 0 ){
  //          cout << "START = " << src <<"\n";
            //cout << "idx1 = " << idx1 << " num_verts = " << num_verts<<"\n";
            coloring_book[src] = 1;
    //        cout << "graph[src] = " << graph[src][0] <<"\n";
            r2 = explore(coloring_book, src,-1);
      //      cout << "r2 = "<<r2<<"\n";
            if (r2==1){
                return r2;
            }
            //num_connected_components += 1;
        }

    }

    //return num_connected_components;
    return r2;
}


int main(){


    freopen("C:/Users/Jyler/Documents/ProgrammingProjects/rosalind/rosalind_dag.txt","r",stdin);

    int k; // number of graphs that we have to look at.

    scanf("%d",&k);

    int u,v;
    int verts, edges;
    int storage[k];
    int result;
    int source;
//    cout <<"k = "<<k<<"\n";

    for (int idx1 = 0;idx1<k;idx1++){
        // read in graph idx1
        scanf("%d %d",&verts, &edges);
        //cout <<"idx1 = "<<idx1 << " verts = "<<verts<<" edges = "<<edges<<"\n";
        for (int idx2 = 0; idx2<edges; idx2++){
            scanf("%d %d",&u,&v);
            //cout <<"u v = " << u << " " << v << "\n";
            if (idx2 == 0){
                source = (u-1);
            }
            graph[u-1].push_back(v-1);
          //  cout << graph[u-1][0] << graph[u-1][1] <<"\n";
            //graph[v-1].push_back(u-1);
        }
        // depth-first search for cycle
        result = DFS(verts,source);
        //cout << "result = " << result <<"\n\n";
        // store result of cycle/no-cycle in storage
        storage[idx1] = (-1)*result;
        // initialize graph again
        init(verts);
    }

    cout << "are there cycles?\n";
    for (int idx1 = 0;idx1<k;idx1++){
        cout << " " << storage[idx1];
    }

    return 0;
}
