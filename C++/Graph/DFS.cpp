

#include <bits/stdc++.h>
#include "CreateGraph.cpp"

using namespace std;
class Solution
{
    vector<int> DFShelper(vector<vector<int>> adj, int nodes)
    {
        vector<int> res;
        stack<int> s;
        unordered_map<int, bool> visited;
        for(int i=0;i<nodes;i++)
        {
            if(!visited[i])
            DFS(i, adj, visited, res);
        }
        return res;

    }
    void DFS(int node, vector<vector<int>> adj , unordered_map<int, bool> &visited, vector<int>& res)
    {
        res.push_back(node);
        visited[node]=true;
        for(auto it : adj[node])
        {
            if(!visited[it])
            {
                DFS(it, adj, visited,res);
            }
        }

    }

};