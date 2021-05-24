

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
	   for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                q.push(i); /// graph starts with 0
                visited[i] = true;
                while (!q.empty())
                {
                    int k = q.front();
                    q.pop();
                    res.push_back(k);
                    for (auto it : adj[k])
                    {
                        if (!visited[it])
                        {
                            q.push(it);
                            visited[it] = true;
                        }
                    }
                }
            }
        }
        return res;
    }
};
