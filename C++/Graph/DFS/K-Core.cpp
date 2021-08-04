// find the indegree of all the vertex, and for all indegree less than k , reduce the indegree 
// https://www.geeksforgeeks.org/find-k-cores-graph/ 


#include <bits/stdc++.h>

using namespace std;
class Solution
{
    void DFSUtil(vector<int> adj[], int v, vector<bool> &visited, vector<int> &vDegree, int k)
    {
        visited[v] = true;
        for (auto it : adj[v])
        {
            if (vDegree[v] < k)
                vDegree[it]--;

            if (!visited[it])
            {
                DFSUtil(adj, it, visited, vDegree, k);
            }
        }
    }

    void printKCores(vector<int> adj[], int k, int V)
    {

        vector<bool> visited(V, false);
        vector<bool> processed(V, false);

        int mindeg = INT_MAX;
        int startvertex;

        vector<int> vDegree(V);
        for (int i = 0; i < V; i++)
            vDegree[i] = adj[i].size();

        for (int i = 0; i < V; i++)
            if (visited[i] == false)
                DFSUtil(adj,i, visited, vDegree, k);

        cout << "K-Cores : \n";
        for (int v = 0; v < V; v++)
        {

            if (vDegree[v] >= k)
            {
                cout << "\n[" << v << "]";
                for (auto it : adj[v])
                    if (vDegree[it] >= k)
                        cout << " -> " << it;
            }
        }
    }
};