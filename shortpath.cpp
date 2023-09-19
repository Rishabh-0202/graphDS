#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int V;
    list<int> *l;

public:
    Graph(int v){
        V=v;
        l = new list<int>[V];
    }

    void addEdge(int i, int j, bool undirect = true){
        l[i].push_back(j);
        if(undirect){
            l[j].push_back(i);
        }
    }

    void printList(){

        for (int i = 0; i < V; i++)
        {
            cout<<i<<"-->";
            /* code */
            for (auto node: l[i])
            {
                /* code */
                cout<< node <<",";
            }
            cout<<endl;
        }   
    }

    void shortest_distance(int source,int destin){
        queue<int> q;
        bool *visited= new bool[V]{0};
        int *dist = new int[V]{0};
        int *parent = new int[V];

        for (int i = 0; i < V; i++)
        {
            /* code */
            parent[i] = -1;
        }
        
        q.push(source);
        visited[source] = true;
        
        parent[source] = source;
        dist[source] = 0;


        while(!q.empty()){
            int f = q.front();
            //cout<<f<<" "<<endl;
            q.pop();
            for(auto nbrs:l[f]){
                if(!visited[nbrs]){
                q.push(nbrs);
                parent[nbrs] = f;
                dist[nbrs] = dist[f] + 1;
                visited[nbrs] = true;
                }
            }
        }

        //printing shortest distance
        for (int i = 0; i < V; i++)
        {
            /* code */
            cout<<"shortest distance to "<< i << " is "<<dist[i]<<endl;
        }

        //printing the path from source to destination
        if(destin!=-1){
            int temp = destin;
            while(temp!=source){
                cout<<temp<<"--";
                temp = parent[temp];
            }
            cout<<source<<endl;
        }
        
    }

};



int main(){
    Graph g(7);
    g.addEdge(1,0);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(3,5);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(4,0);
    
    //g.printList();

    g.shortest_distance(1,6);

    return 0;
}