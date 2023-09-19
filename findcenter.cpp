#include<iostream>
#include<list>
#include<vector>
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

};

int findCenter(vector<vector<int>> edges){
    int k = edges[0][0];
    int j = edges[0][1];

    if(k==edges[1][0] or k== edges[1][1]){
        return k;
    }

    if(j==edges[1][0] or j== edges[1][1]){
        return j;
    }
    else{
        return -1;
    }
}

int main(){
    // Graph g(6);
    // g.addEdge(0,1);
    // g.addEdge(0,4);
    // g.addEdge(2,1);
    // g.addEdge(3,4);
    // g.addEdge(4,5);
    // g.addEdge(2,3);
    // g.addEdge(3,5);

    // g.printList();

    vector<vector<int>> edges;

    vector<int> k;
    k.push_back(1);
    k.push_back(2);

    int ar[] = {1,2,2,3,4,2};
    int l=0;

    for (int i = 0; i < 3; i++)
    {
        /* code */
        for (int j = 0; j < 2; j++)
        {
            /* code */
            edges[i].push_back(ar[l]);
            l++;
        }
        
    }

    

    cout<<findCenter(edges)<<endl;

    return 0;
}

