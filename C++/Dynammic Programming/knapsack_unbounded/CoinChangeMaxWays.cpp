#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dp[4][6] = {-1};

    int knapsackRec(vector<int> length, int amount, int n)
    {
        if (amount == 0) //base case
            return 1;
        if (n == 0)
            return 0;

        if (amount < length[n - 1])
            return knapsackRec(length, amount, n - 1);
        else
            return knapsackRec(length, amount - length[n - 1], n) + knapsackRec(length, amount, n - 1);
    }

    int knapsackMemo(vector<int> length, int amount, int n)
    {
        if (amount == 0) //base case
            return 1;

        if (n == 0)
            return 0;

        if (amount < length[n - 1])
            dp[n][amount] = knapsackMemo(length, amount, n - 1);
        else
            dp[n][amount] = knapsackMemo(length, amount - length[n - 1], n) + knapsackMemo(length, amount, n - 1);
        return dp[n][amount];
    }

    int knapsackDP(vector<int> length, int amount, int n)
    {
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                if (j == 0)
                    dp[i][j] = 0;
                if (i == 0)
                    dp[i][j] = 1;
                else if (length[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i][j - length[i - 1]] + dp[i - 1][j];
            }
        }
        return dp[n][amount];
    }

    // int coinChange(int price[], int n) //// 1D dp
    // {
    //     if (n <= 0)
    //         return 0;
    //     int max_val = INT_MIN;
    //     int val[n + 1];
    //     // Recursively cut the rod in different pieces and compare different
    //     // configurations
    //     for (int i = 0; i < n; i++)
    //         val[i] = price[i] + coinChange(price, n - i - 1);

    //     return max_val;
    // }

    // int coinChangeDP(int price[], int n)
    // {
    //     int val[n + 1];
    //     val[0] = 0;
    //     int i, j;

    //     // Build the table val[] in bottom up manner and return the last entry
    //     // from the table
    //     for (i = 1; i <= n; i++)
    //     {
    //         int max_val = INT_MIN;
    //         for (j = 0; j < i; j++)
    //             val[i] = price[j] + val[i - j - 1];
    //     }

    //     return val[n];
    // }
};
int main()
{

    vector<int> length = {1, 2, 3};
    Solution s;
    cout << "mm" << s.knapsackMemo(length, 5, 3);
}