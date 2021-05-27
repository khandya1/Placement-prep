

#include <bits/stdc++.h>
#include "CreateGraph.cpp"

using namespace std;

class Solution
{
    public:
    //Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int>adj[])
	{
	    bool t;
	    map<int, bool> visited;
	    for(int i=0;i<V;i++)
	    {
	        if(!visited[i])
	        t = detectcycledfs(adj,visited, i, -1);
	        if(t==true)
	        return true;
	    }
	    return false;
	}
	bool detectcycledfs( vector<int>adj[] ,map<int,bool>&visited, int node, int parent)
	{
	   if(!visited[node])
	   visited[node]=true;
	   
	   for(auto it : adj[node])
	   {
	      // cout<<node<<"node "<<parent<<"parent "<<it<<"it\n";
	       if(!visited[it])
	       {
	           if(detectcycledfs(adj,visited,it,node))
	           return true;
	           
	       }
	       else
	       {
	           if(it !=parent)
	           return true;
	       }
	   }
	   return false;
	}
};