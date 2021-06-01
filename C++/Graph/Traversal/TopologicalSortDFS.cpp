////steps to find topological sort by DFS : create visited array as well as stack that will keep the nodes
// whose dfs call is over so that we know there are no outgoing edges from them,
// we will run the dfs code for all the unvisited nodes and as soon as the dfs call for the node
// ends we will push that node in stack, so that the sequence will be 0 indegree nodes at the top

//// Always prefer DFS approach for topological sort as BFS one is just a work around

#include <bits/stdc++.h>
#include "CreateGraph.cpp"
using namespace std;

class Solution
{
public:
    //Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        stack<int> st;
        vector<int> topologicalSort;
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                topoDFS(adj, st, visited, i);
        }

        while (!st.empty())
        {
            topologicalSort.push_back(st.top());
            st.pop();
        }
        return topologicalSort;
    }
    void topoDFS(vector<int> adj[], stack<int> &st, vector<bool> &visited, int node)
    {
        if (!visited[node])
            visited[node] = true;
        for (auto it : adj[node])
        {
            if (!visited[it])
                topoDFS(adj, st, visited, it);
        }
        st.push(node);
    }
};