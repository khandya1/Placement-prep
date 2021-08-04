#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    
    
   
    void createAdjacencyMatrix(int nodes, int edges)
    {
        int adj[nodes+1][nodes+1];

        for(int i=0;i<edges;i++)
        {
            int u, v;
            cin>>u>>v; // nodes in btw
            adj[u][v] = 1; // 1 for the weight , else add the weight
            adj[v][u] = 1; // in case of directed only one edge will come
        }
    }
    vector<int>*  createAdjacencyList(int nodes, int edges)
    {
         vector<int> *adj; /// for weighted vector<vector<pair<int,int>>> adj[nodes+1]
        //vector<vector<pair<int,int>>> adj1[nodes+1];
        for(int i=0;i<edges;i++)
        {
            int u, v, w;
            cin>>u>>v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
            //adj1[u].emplace_back(u,w);
        }
       // vector<vector<int>> x = adj;
        return adj;
    }    
};

int main()
{
    int n, e;
    cin>> n>>e;
  //  Graph g;

     vector<int> adj[n+1]; /// for weighted vector<vector<pair<int,int>>> adj[nodes+1]
        //vector<vector<pair<int,int>>> adj1[nodes+1];
        for(int i=0;i<e;i++)
        {
            int u, v, w;
            cin>>u>>v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
            //adj1[u].emplace_back(u,w);
        }
   
   // vector<int> *x = g.createAdjacencyList(n,e);

    for(int i=0;i<n;i++)
    {
      for(auto it : adj[i])
        cout<<it;
        cout<<"\n";
    }
 //  delete(g);
}
