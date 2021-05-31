
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

bool hasPath(vector<int> adj[],int V, int src, int des)
{
    vector<bool> visited(V,false);
    if(DFS(adj,visited,src,des))
    return true;
    return false;
}
bool DFS(vector<int> adj[],vector<bool> &visited, int src, int des)
{
    if(src==des)
    return true;
    visited[src]=true;
    for(auto it : adj[src])
        {
            if(!visited[it])
                DFS(adj,visited,it,des);
        }
    return false;

}
};