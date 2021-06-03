// https://www.hackerrank.com/challenges/journey-to-the-moon/problem
// the concept for solving the problem is to find the number of nodes in each component 
// here these number of nodes are stored in  sizeofcomp vector
// to find the combination -> it would be nc2 -summation of(no_of_nodes_in_each_coponent C2)

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int DFS(vector<int> adj[], vector<bool> &visited, int node)
    {
        int size = 1;
        visited[node] = true;
        for (auto it : adj[node])
        {
            if (!visited[it])
                size = size + DFS(adj, visited, it);
        }
        return size;
    }
    int journeyToMoon(int n, vector<vector<int>> astronaut)
    {

        vector<int> adj[n];
        for (auto it : astronaut)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool> visited(n, false);
        vector<int> sizeofcomp;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                sizeofcomp.push_back(DFS(adj, visited, i));
            }
        }
        int n1 = n * (n - 1) / 2;
        cout << n1;
        for (auto it : sizeofcomp)
        {
            n1 -= it * (it - 1) / 2;
        }

        return n1;
    }
};