
#include <bits/stdc++.h>
#include "CreateGraph.cpp"
using namespace std;

class Solution{
public:
	bool isBipartite(int V, vector<int>adj[]){
        vector<int>visited (V,-1);
        for (int i = 0; i < V; i++)
        {
            if (visited[i]==-1)
                if(!checkBipartite(adj, visited, i ,0))
                return false;
        }
        return true;
    }
    bool checkBipartite(vector<int> adj[], vector<int> &visited, int node , int pcolour)
    {
            for (auto it : adj[node])
            {
                if (visited[it]==-1)
                {
                    visited[it]= 1-visited[node];
                    if(!checkBipartite(adj,visited,it , visited[node]))//// if not bipartite return false
                    return false;
                }
                else 
                {
                    if (visited[it]==visited[node])/// condition that is is not bipartite as parent colour = child colour
                        return false;
                }
            }
             return true;
        }

};