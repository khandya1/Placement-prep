//// https://leetcode.com/problems/all-paths-from-source-to-target/
/// 797 lc

#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> x;

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {

        DFS(graph, 0, graph.size() - 1, x);
        return res;
    }

    void DFS(vector<vector<int>> &adj, int src, int des, vector<int> &x)
    {
        x.push_back(src);
        if (src == des)
        {
            res.push_back(x);
        }

        for (auto it : adj[src])
        {
            DFS(adj, it, des, x);
        }
        x.pop_back();  //// removing single node just while keeping rest of the nodes
        return;
    }
};