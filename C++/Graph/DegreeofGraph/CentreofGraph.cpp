// https://leetcode.com/problems/find-center-of-star-graph/
// lc 1791

// similar concept 
// https://leetcode.com/problems/find-the-town-judge/
// lc 997


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        int n=edges.size()+1;
       vector<int> x(n,0);
        for(auto t : edges)
        {
            x[t[0]-1]++;
            x[t[1]-1]++;
        }
          
        for(int i=0;i<x.size();i++)
        {
            if(x[i]==n-1)
                return i+1;
        }
        return -1;
        // one line solution 
        // the centre will be the common node in two edges
        //return e[0][0] == e[1][0] || e[0][0] == e[1][1] ? e[0][0] : e[0][1];
    }
};