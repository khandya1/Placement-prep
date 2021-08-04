// finding mother vertex can be done in two ways , one -> whenever the dfs call of a vertex node ends push that node to stack.
// The stack will always have the mother vertex at the top of the stack if it exists. to cross check of the top of the stack
// vertex is mother vertex we will run the dfs call again, if that node can visit all vertex it is the mother vertex , else we will return -1

// https://www.youtube.com/watch?v=gNn0L18DUvga

// There is another space saving method instead if saving the nodes in stack, the last call of dfs will be the 
// top vertex, and we can call it motherV

#include <bits/stdc++.h>


using namespace std;
class Solution
{


int findMothervertex(vector<int> adj[],int V)
{
    vector<bool> visited(V,false);
    int motherV = 0;
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        checkDFS(adj,visited,i);
        motherV=i;
    }
    fill(visited.begin(),visited.end(),false);
    checkDFS(adj,visited,motherV);/// to check if it is the motherV
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        return -1;
    }
    return motherV;
}
void checkDFS(vector<int> adj[],vector<bool> &visited ,int node)
{
    if(!visited[node])
    visited[node]=true;
    for(auto it : adj[node])
    {
        if(!visited[it])
        checkDFS(adj,visited,it);
    }
}

};