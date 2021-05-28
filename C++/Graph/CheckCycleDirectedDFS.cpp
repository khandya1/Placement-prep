#include <bits/stdc++.h>
#include "CreateGraph.cpp"
using namespace std;

class Solution{
    public:
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	    vector<bool> visited(V,false);
	    vector<bool> insidedfs(V,false);
	    for(int i=0;i<V;i++)
	    {
	        if(!visited[i])
	            {
	                if(iscycledfs(adj,visited,insidedfs,i))
	                return true;
	                
	            }
	    }
	    return false;
	}
	bool iscycledfs(vector<int> adj[] ,vector<bool> &visited, vector<bool> &insidedfs,int node)
	{
	   
	        visited[node]=true;
	        insidedfs[node]=true;
	    for(auto it : adj[node])
	    {
	        if(!visited[it])
	        {
	            if(iscycledfs(adj,visited,insidedfs,it))
	            return true;
	        }
	        else
	        {
	            if(insidedfs[it]==true)  /////// if the inside dfs recurrsion is not complete and it sees the node is visited
	            return true;
	        }
	    }
	    insidedfs[node]=false;  /////// if recurrsion is complete for that node and it goes sequentially
	    return false;
	}
};