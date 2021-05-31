/// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
// lc 1557
// nodes with 0 indegree


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        std::ios_base::sync_with_stdio(0); cin.tie(0);
        vector<int> res;
        vector<int> ans(n,0);
        
        for(int i=0;i<edges.size( );i++)
        {
           ans[edges[i][1]]=1;
            
        }
        for(int i=0;i<n;i++)
        {
            if(ans[i]==0)
                res.push_back(i);
        }
       return res;
      
    }
};