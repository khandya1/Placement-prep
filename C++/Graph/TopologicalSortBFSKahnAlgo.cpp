// Step-1: Compute in-degree (number of incoming edges) for each of the vertex present in the DAG and initialize the count of visited nodes as 0.

// Step-2: Pick all the vertices with in-degree as 0 and add them into a queue (Enqueue operation)

// Step-3: Remove a vertex from the queue (Dequeue operation) and then.

// Increment count of visited nodes by 1.
// Decrease in-degree by 1 for all its neighboring nodes.
// If in-degree of a neighboring nodes is reduced to zero, then add it to the queue.
// Step 5: Repeat Step 3 until the queue is empty.
// Step 5: If count of visited nodes is not equal to the number of nodes in the graph then the topological sort is not possible for the given graph.
// As graph contains cycle

#include <bits/stdc++.h>
#include "CreateGraph.cpp"
using namespace std;

class Solution
{
public:
    vector<int> topoSort(int V, vector<int> adj[])
    {
        queue<int> q;
        vector<int> indegree(V, 0);
        vector<int> topologicalSort;
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
                indegree[it]++;
        }
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        topoBFS(adj, q, indegree, topologicalSort);
        return topologicalSort;
    }
    void topoBFS(vector<int> adj[], queue<int> &q, vector<int> &indegree, vector<int> &topologicalSort)
    {
        while (!q.empty())
        {
            int node = q.front();
            topologicalSort.push_back(node);
            q.pop();
            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
    }
};