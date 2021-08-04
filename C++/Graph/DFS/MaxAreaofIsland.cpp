//// https://leetcode.com/problems/max-area-of-island/
//// lc 695 M
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
         int row = grid.size();
        int col = grid[0].size();
        int count=0,area=0,maxarea=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                area=0;
                if(grid[i][j]==1)
                {                    
                    count++;
                    DFS(grid, i,j,row,col,area);
                    
                }
                maxarea=max(maxarea,area);
            }
        }
        return maxarea;        
    }
    void DFS(vector<vector<int>>& grid,int x,int y, int row, int col,int &area)
    {
        if(x>=row || x<0 || y>=col || y<0 || grid[x][y]!=1)
            return;
        
        grid[x][y]=2;
        area++;
        DFS(grid,x+1,y,row,col,area);
        DFS(grid,x-1,y,row,col,area);
        DFS(grid,x,y-1,row,col,area);
        DFS(grid,x,y+1,row,col,area);
        
    }
};