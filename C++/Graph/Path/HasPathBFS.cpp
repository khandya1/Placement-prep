
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

bool hasPath(vector<int> adj[],int V, int src, int des)
{
    vector<bool> visited(V,false);
    if(BFS(adj,visited,src,des))
    return true;
    return false;
}
bool BFS(vector<int> adj[],vector<bool> &visited, int src, int des)
{
    if(src==des)
    return true;
    queue<int> q;
    q.push(src);
    visited[src]=true;
    while(!q.empty())
    {
        int node= q.front();
        q.pop();
        for(auto it : adj[node])
        {
            if(it==des)
            return true;
            if(!visited[it])
            {
                visited[it]=true;
                q.push(it);
            }

        }
    }
    return false;

}


};