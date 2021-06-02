// https://leetcode.com/problems/course-schedule/
// lc207 Medium
// related question  https://leetcode.com/problems/course-schedule-ii/solution/
// lc210 Medium
/// The solution is based on topological sort, topological sort because we can find the relations only if we have 
/// DAG. kahn algo implementation

#include <bits/stdc++.h>
#include "CreateGraph.cpp"
using namespace std;
class Solution { 
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {        
        
        vector<int> indegree(numCourses,0);
        stack<int> q;   // stack gave higher time
        vector<vector<int>> adj(numCourses);  
        for(int i=0; i<pre.size(); i++) // convert edge list to adjacency list
            adj[pre[i][1]].push_back(pre[i][0]);
      
       for(int i=0; i<numCourses; i++) // compute the indegree array
            for(int j=0; j<adj[i].size(); j++)
                indegree[adj[i][j]]++;
        
        for(int i=0; i<numCourses; i++) 
            if(indegree[i]==0) q.push(i);
        
        int nodes=0;
        while(!q.empty())
        {
            int front = q.top();
            q.pop();
            nodes++;           
                for(auto it : adj[front])
                        if(--indegree[it]==0)
                            q.push(it);
        }
        cout<<nodes;
       return nodes==numCourses;//checks for cycle too // if there is a cycle, nodes count will be less
    }
};