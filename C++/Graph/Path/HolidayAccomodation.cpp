
// the question here states that 2 tourist will exchange their rooms when the distance between them is minimum 
// and we have to find the maximum sum of distance that will be possible. 
// The solution can be devised by finding recurrsively the no of nodes in each partition by dfs.
// Maximum number of movements from one part to another will be possible only when the minimum of number of nodes are 
// taken. 
// This minimum will be multiplied by distance between the connecting nodes*2 
// SPOJ Problem

#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int ans = 0;

public:
    void addEdge(vector<pair<int, int>> adj[4
    ], int u, int v, int d)
    {
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }
    void DFS(int n, vector<pair<int, int>> adj[], vector<bool> &visited, vector<int> &count, int node)
    {
        visited[node] = true;
        count[node] = 1;

        for (auto it : adj[node])
        {
            if (!visited[it.first])
            {
              //  cout<<"jhjh";
                DFS(n, adj, visited, count, it.first);
                ans += min(count[it.first], n - count[it.first]) * 2 * it.second;
                count[node] += count[it.first];
            }
        }
      //  cout<<"fgfg"<<ans;
    }
    int holidayAccomodation(int n, vector<pair<int,int>> rooms[])
    {

        vector<pair<int, int>> adj[n];
        // for (auto it : rooms)
        // {
        //     adj[it[0]].push_back({it[1], it[2]});
        //     adj[it[1]].push_back({it[0], it[2]});
        // }
        vector<bool> visited(n, false);
        vector<int> count(n, 1);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                DFS(n, rooms, visited, count, i);
            }
        }
      //  cout<<"jkj"<<ans;
        return ans;
    }
};

int main()
{
    int ans;
    int V = 4;
    vector<pair<int, int>> adj[4];
    Solution s;
    s.addEdge(adj,0,1,3);
    s.addEdge(adj,1,2,2);
    s.addEdge(adj,3,2,2);
    // s.addEdge(adj, 0, 1, 4);
    // s.addEdge(adj, 0, 7, 8);
    // s.addEdge(adj, 1, 2, 8);
    // s.addEdge(adj, 1, 7, 11);
    // s.addEdge(adj, 2, 3, 7);
    // s.addEdge(adj, 2, 8, 2);
    // s.addEdge(adj, 2, 5, 4);
    // s.addEdge(adj, 3, 4, 9);
    // s.addEdge(adj, 3, 5, 14);
    // s.addEdge(adj, 4, 5, 10);
    // s.addEdge(adj, 5, 6, 2);
    // s.addEdge(adj, 6, 7, 1);
    // s.addEdge(adj, 6, 8, 6);
    // s.addEdge(adj, 7, 8, 7);

    // cin >> start >> end;
    ans = s.holidayAccomodation(4, adj);

    
    cout <<ans<< endl;
}