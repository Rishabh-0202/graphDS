#include<iostream>
#include<vector>
using namespace std;

vector<int> bellman_ford(int V, int src, vector<vector<int>> edges){

    vector<int> dist(V+1,INT16_MAX);
    dist[src] = 0;

    //relax all edges v-1 times
    for (int i = 0; i < V-1; i++)
    {
        /* code */
        for (auto edge : edges)
        {
            /* code */
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if(dist[u]!=INT16_MAX and dist[u]+wt<dist[v]){
                dist[v] = dist[u]+wt;
            }
        }
    }
    //check negative wt cycle
    for (auto edge: edges)
    {



        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        if(dist[u]!=INT16_MAX and dist[u]+wt<dist[v]){
            cout<<"negative wt cycle detected";
            exit(0);
        }
    }
    
    return dist;
}

int main(){
    //using edge list

    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        /* code */
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({u,v,wt});
    }
    
    // calling bellman ford Algorithm
    vector<int> distance = bellman_ford(n,1,edges);

    for (int i = 1; i <= n; i++)
    {
        /* code */
        cout<<"Node "<<i<<" is at a distance "<<distance[i]<<endl;
    }
    

    return 0;
}