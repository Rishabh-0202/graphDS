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

    void bfs(int source){
        queue<int> q;
        bool *visited= new bool[V]{0};
        q.push(source);
        visited[source] = true;

        while(!q.empty()){
            int f = q.front();
            cout<<f<<" "<<endl;
            q.pop();
            for(auto nbrs:l[f]){
                if(!visited[nbrs]){
                q.push(nbrs);
                visited[nbrs] = true;
                }
            }
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
    
    g.printList();

    g.bfs(1);

    return 0;
}