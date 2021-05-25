
#include <bits/stdc++.h>
#include "CreateGraph.cpp"

using namespace std;

class Solution
{
public:
    //Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        bool t;
        map<int, bool> visited;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                t = detectcyclebfs(adj, visited, i, -1);
            if (t == true)
                return true;
        }
        return false;
    }
    bool detectcyclebfs(vector<int> adj[], map<int, bool> &visited, int node, int parent)
    {
        queue<pair<int, int>> q;
        if (!visited[node])
        {
            visited[node] = true;
            q.push({node, parent});
        }
        while (!q.empty())
        {
            int val = q.front().first;
            int par = q.front().second;
            q.pop();
            for (auto it : adj[val])
            {
                if (!visited[it])
                {
                    visited[it] = true;
                    q.push({it, val});
                }
                else
                {
                    if (par != it)
                        return true;
                }
            }
        }
        return false;
    }
};