// F(i, j) represents the maximum value the user
// can collect from i'th coin to j'th coin.

// F(i, j) = Max(Vi + min(F(i+2, j), F(i+1, j-1) ),
//               Vj + min(F(i+1, j-1), F(i, j-2) ))
// As user wants to maximise the number of coins.

// Base Cases
//     F(i, j) = Vi           If j == i
//     F(i, j) = max(Vi, Vj)  If j == i + 1

// https://www.geeksforgeeks.org/optimal-strategy-for-a-game-dp-31/

using namespace std;
#include <bits\stdc++.h>

class Solution
{
public:
    int GameStrategy(vector<int> arr, int i, int j)
    {
        if (i == j)
            return arr[i];

        if (j == i + 1)
            return max(arr[i], arr[j]);

        return max(arr[i] + min(GameStrategy(arr, i + 2, j), GameStrategy(arr, i + 1, j - 1)),
                   arr[j] + min(GameStrategy(arr, i, j - 2), GameStrategy(arr, i + 1, j - 1)));
    }
    int GameStrategyDP(vector<int> arr)
    {
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 0));

        for (int gap = 0; gap < arr.size(); gap++)
        {
            for (int i = 0, j = gap; j < arr.size(); i++, j++)
            {
                int x = ((i + 2) <= j) ? dp[i + 2][j] : 0;
                int y = ((i + 1) <= j - 1) ? dp[i + 1][j - 1] : 0;
                int z = (i<= j - 2) ? dp[i][j - 2] : 0;

                dp[i][j] = max(arr[i]+min(x, y), arr[j]+min(y, z));
                cout<<dp[i][j];
            }
            cout<<"\n";
        }
        return dp[0][arr.size() - 1];
    }
};
int main()
{
    vector<int> arr1 = {8, 15, 3 ,7};
    Solution s;
    cout << s.GameStrategy(arr1,0,3);
}