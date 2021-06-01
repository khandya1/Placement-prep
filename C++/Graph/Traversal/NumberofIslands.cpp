////////////////  https://leetcode.com/problems/number-of-islands/
///////// lc 200
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    ////// BFS method  /////////////////////////
    int numIslandsBFS(vector<vector<char>> &grid)
    {
        int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0, offsets[] = {0, 1, 0, -1, 0};
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    islands++;
                    grid[i][j] = '0';
                    queue<pair<int, int>> todo;
                    todo.push({i, j});
                    while (!todo.empty())
                    {
                        pair<int, int> p = todo.front();
                        todo.pop();
                        for (int k = 0; k < 4; k++)
                        {
                            int r = p.first + offsets[k], c = p.second + offsets[k + 1];
                            if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1')
                            {
                                grid[r][c] = '0';
                                todo.push({r, c});
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }

    /////////////// DFS Methos ///////////////
    int numIslands(vector<vector<char>> &grid)
    {

        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    DFS(grid, i, j, row, col);
                }
            }
        }
        return count;
    }
    void DFS(vector<vector<char>> &grid, int x, int y, int row, int col)
    {
        if (x >= row || x < 0 || y >= col || y < 0 || grid[x][y] != '1')
            return;

        grid[x][y] = '2';

        DFS(grid, x + 1, y, row, col);
        DFS(grid, x - 1, y, row, col);
        DFS(grid, x, y - 1, row, col);
        DFS(grid, x, y + 1, row, col);
    }
};