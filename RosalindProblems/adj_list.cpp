// EXAMPLE BY SAMEE


#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;
vector<int>graph[10]; // assuming that maximum node can be 100000
int n,m;
void init(){
    int i;
    for(i=0;i<=n;i++){
        graph[i].clear();
    }
}

int main(){

        /*
        int i,u,v;
        scanf("%d %d",&n,&m);
        init();
        for(i=0;i<m;i++){
            scanf("%d %d",&u,&v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        */

        graph[0].push_back(100);
        graph[0].push_back(1);
        graph[0].push_back(2);
        graph[0].push_back(3);
        graph[0].push_back(4);
        cout << graph[0][0];
        init();
        graph[0].push_back(4);
        cout<<"\n"<<graph[0][0];

}
