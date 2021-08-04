//  https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1#

// one is the DFS solution , which will give run time error as it would take up stack space.
// other is bfs which is optimal as we have to find the shortest path , 
//dfs would traverse all paths and is suitable to check if any path exists

#include <bits/stdc++.h>
#include "CreateGraph.cpp"
using namespace std;
class Solution 
{
    public:
    int finalans =INT_MAX;
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&s,vector<int>&t,int N)
	{
	    vector<vector<int>> vis(N, vector<int>(N, INT_MAX));
	    int x =0;
	    vis[s[0]][s[1]]=INT_MAX;
	    dfs(vis, s[0]-1,s[1]-1 , t[0]-1 , t[1]-1 , N ,x);
	    return finalans;
	    
	    
	}
	void dfs(vector<vector<int>>&vis , int s0, int s1, int t0, int t1, int n , int x)
	{
	    if(s0<0 || s1<0 || s0>=n || s1>=n || vis[s0][s1]<=x)
	    
	        return ;
	   
	    if(s0==t0  && s1==t1)
	    {
	        finalans =x;
	     
	    }
	    else
	    {
	      
	        vis[s0][s1]=min(vis[s0][s1] ,x);
	        x= vis[s0][s1];
	        
	        dfs(vis, s0-1, s1+2,t0,t1,n,x+1);
	      
	        dfs(vis, s0-1, s1-2,t0,t1,n,x+1);
	      
	        dfs(vis, s0+2, s1-1,t0,t1,n,x+1);
	       
	        dfs(vis, s0+2, s1+1,t0,t1,n,x+1);
	       
	        dfs(vis, s0+1, s1-2,t0,t1,n,x+1);
	      
	        dfs(vis, s0+1, s1+2,t0,t1,n,x+1);
	       
	        dfs(vis, s0-2, s1-1,t0,t1,n,x+1);
	       
	        dfs(vis, s0-2, s1+1,t0,t1,n,x+1);
	      
	        
	    }
	}
	
	
};