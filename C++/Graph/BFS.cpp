

#include <bits/stdc++.h>
#include "CreateGraph.cpp"

using namespace std;
class Solution
{
    vector<int> BFS(vector<vector<int>> adj, int nodes)
    {
        vector<int> res;
        queue<int> q;
        unordered_map<int, bool> visited;

        q.push(0); /// graph starts with 0
        visited[0] = true;
        res.emplace_back(0);
        while (!q.empty())
        {
            int k = q.front();
            q.pop();
            if (!visited[k])
            {
                visited[k] = true;
                res.push_back(k);
            }
            for (int x = 0; x < adj[k].size(); x++)
            {
                if (!visited[adj[k][x]])
                    q.push(adj[k][x]);
            }
        }
        return res;
    }
};
