
#include <bits/stdc++.h>
#include "CreateGraph.cpp"
using namespace std;

class Solution
{
public:
    bool isBipartite(int V, vector<int> adj[])
    {
        bool t;
        vector<int> visited(V, -1);
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == -1)
                t = checkBipartite(adj, visited, i);/// true is when it is not bipartite as same colour of child and parent
            if (t == true)
                return false;
        }
        return true;
    }
    bool checkBipartite(vector<int> adj[], vector<int> &visited, int node)
    {
        queue<int> q;
        visited[node] = 1;
        q.push(node);
        while (!q.empty())
        {
            int val = q.front();
            q.pop();
            for (auto it : adj[val])
            {
                if (visited[it] == -1)
                {
                    visited[it] = 1 - visited[val];
                    q.push(it);
                }
                else
                {
                    if (visited[it] == visited[val])
                        return true;//// same colour detected so it is not bipartite
                }
            }
        }
        return false;
    }
};