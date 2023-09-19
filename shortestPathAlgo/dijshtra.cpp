#include<iostream>
#include<list>
#include<set>
#include<vector>
#include<climits>
using namespace std;

class Graph{
    int V;
    list<pair<int,int>>*l;

public:
    Graph(int v){
        V=v;
        l = new list<pair<int,int> >[V];
    }

    void addEdge(int u, int v,int wt, bool undirect = true){
        l[u].push_back({wt,v});
        if(undirect){
            l[v].push_back({wt,u});
        }
    }
    
    int dijkstra(int src,int des){
        vector<int> dist(V,INT8_MAX);
        set<pair<int,int>> s;

        // 1. Init
        dist[src] = 0;
        s.insert({0,src});

        while(!s.empty()){
            auto it = s.begin();
            
            int node = it->second;
            int distTillNow = it->first;

            s.erase(it); //pop operation

            //iterate over nbrs of node
            for(auto nbrsPair : l[node]){
                int nbr = nbrsPair.second;
                int currentEdge = nbrsPair.first;

                if(distTillNow + currentEdge < dist[nbr]){
                    // remove if nbr already exists in the set
                    auto k = s.find({dist[nbr],nbr});
                    
                    if(k!=s.end()){
                        s.erase(k);
                    }


                    dist[nbr] = distTillNow + currentEdge;
                    s.insert(make_pair(dist[nbr],nbr));
                }
            }
        }
        return dist[des];
    }   
    
};



int main(){
    Graph g(5);
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(0,2,4);
    g.addEdge(0,3,7);
    g.addEdge(3,2,2);
    g.addEdge(3,4,3);
    // g.addEdge(5,6);
    // g.addEdge(4,0);
    cout<<g.dijkstra(0,4)<<endl;

    return 0;
}