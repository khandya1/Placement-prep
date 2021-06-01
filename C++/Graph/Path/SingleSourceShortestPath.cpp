//// Dijkstra Algorithm


#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void addEdge(vector<pair<int, int>> adj[9], int u, int v, int d)
    {
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }
    vector<int> shortestDistance(int V, vector<pair<int, int>> adj[], pair<int, int> src)
    {
        vector<int> distance(V, INT_MAX);
        BFS(adj, distance, src);
        return distance;
    }
    void BFS(vector<pair<int, int>> adj[], vector<int> &distance, pair<int, int> node)//{node, dist}
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push(node);
        distance[node.first] = 0;
        //cout<<node.first;/// vertex
        while (!q.empty())
        {
                int n = q.top().second;//// prio q (distance , node)
                q.pop();
                for (auto it : adj[n])  /// but node "it" has {node , distance}
                {
                    if (distance[it.first] > distance[n] + it.second)
                    {
                        distance[it.first] = distance[n] + it.second;
                        q.push({distance[it.first],it.first});
                    }
                }
        }
    }
};
int main()
{

    int V = 9;
    vector<pair<int, int>> adj[9];
    Solution s;
    s.addEdge(adj, 0, 1, 4);
    s.addEdge(adj, 0, 7, 8);
    s.addEdge(adj, 1, 2, 8);
    s.addEdge(adj, 1, 7, 11);
    s.addEdge(adj, 2, 3, 7);
    s.addEdge(adj, 2, 8, 2);
    s.addEdge(adj, 2, 5, 4);
    s.addEdge(adj, 3, 4, 9);
    s.addEdge(adj, 3, 5, 14);
    s.addEdge(adj, 4, 5, 10);
    s.addEdge(adj, 5, 6, 2);
    s.addEdge(adj, 6, 7, 1);
    s.addEdge(adj, 6, 8, 6);
    s.addEdge(adj, 7, 8, 7);

    // cin >> start >> end;
    vector<int> ans;
    ans = s.shortestDistance(9, adj, {0, 0});

    if (ans.size() == 0)
    {
        cout << "path didn't exist";
    }
    else
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }
    cout << endl;
}