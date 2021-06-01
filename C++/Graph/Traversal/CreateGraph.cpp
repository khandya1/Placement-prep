#include <bits/stdc++.h>
using namespace std;

class Graph{
    int nodes;
    int edges;

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
    void createAdjacencyList(int nodes, int edges)
    {
        vector<vector<int>> adj[nodes+1]; /// for weighted vector<vector<pair<int,int>>> adj[nodes+1]
        //vector<vector<pair<int,int>>> adj1[nodes+1];
        for(int i=0;i<edges;i++)
        {
            int u, v, w;
            cin>>u>>v>>w;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
            //adj1[u].emplace_back(u,w);
        }
    }

    
};
