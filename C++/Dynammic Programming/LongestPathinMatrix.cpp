
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int DFS(vector<vector<int>> &dp, vector<vector<int>> mat, int i, int j, int n)
    {
        if (i >= n || j >= n || j < 0 || i < 0)
            return 0;

      //  cout << dp[i][j] << " " << i << " " << j << "\n";
        if (dp[i][j] != -1)
            return dp[i][j];

        int x = INT_MIN, y = INT_MIN, z = INT_MIN, w = INT_MIN;

        if (i > 0 && (mat[i - 1][j] == mat[i][j] + 1))
            x = 1 + DFS(dp, mat, i - 1, j, n);

        if ((j > 0 && mat[i][j - 1] == mat[i][j] + 1))
            y = 1 + DFS(dp, mat, i, j - 1, n);

        if (i < n - 1 && (mat[i + 1][j] == mat[i][j] + 1))
            w = 1 + DFS(dp, mat, i + 1, j, n);

        if (j < n - 1 && (mat[i][j + 1] == mat[i][j] + 1))
            z = 1 + DFS(dp, mat, i, j + 1, n);

        dp[i][j] = max(x, max(y, max(w, max(z, 1))));
        //   cout<<dp[i][j] <<" "<<i<< " "<<" ";
        return dp[i][j];
    }
};

int main()
{
    int n = 3;
    vector<vector<int>> mat = {{1, 10, 9},
                               {5, 3, 8},
                               {4, 6, 7}};
    vector<vector<int>> dp = {{-1, -1, -1},
                              {-1, -1, -1},
                              {-1, -1, -1}};
    Solution s;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) /////// these 2 loops are imp as cycle can start from any point not just first point and we are storing result in different matrix
        {
            res = max(res, s.DFS(dp, mat, i, j, 3));
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        cout<<dp[i][j]<<" ";
    
    cout<<"\n";
    }
    cout << "Length of the longest path is " << res;
    return 0;
}
