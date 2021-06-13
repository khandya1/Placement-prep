#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dp[9][9] = {-1};

    int knapsackRec(vector<int> value, vector<int> length, int rod_length, int n)
    {
        if (n == 0 || rod_length == 0) //base case
            return 0;

        if (rod_length < length[n - 1])
            return knapsackRec(value, length, rod_length, n - 1);
        else
            return max(value[n - 1] + knapsackRec(value, length, rod_length - length[n - 1], n), knapsackRec(value, length, rod_length, n - 1));
    }
    int knapsackMemo(vector<int> value, vector<int> length, int rod_length, int n)
    {
        if (n == 0 || rod_length == 0) //base case
            return 0;

        if (rod_length < length[n - 1])
            dp[n][rod_length] = knapsackRec(value, length, rod_length, n - 1);
        else
            dp[n][rod_length] = max(value[n - 1] + knapsackMemo(value, length, rod_length - length[n - 1], n), knapsackMemo(value, length, rod_length, n - 1));
        return dp[n][rod_length];
    }
    int knapsackDP(vector<int> value, vector<int> length, int rod_length, int n)
    {
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= rod_length; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (length[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(value[i - 1] + dp[i][j - length[i - 1]], dp[i - 1][j]);
            }
        }

        return dp[n][rod_length];
    }

    int cutRod(int price[], int n) //// 1D dp
    {
        if (n <= 0)
            return 0;
        int max_val = INT_MIN;

        // Recursively cut the rod in different pieces and compare different
        // configurations
        for (int i = 0; i < n; i++)
            max_val = max(max_val, price[i] + cutRod(price, n - i - 1));

        return max_val;
    }

    int cutRodR(int price[], int n)
    {
        int val[n + 1];
        val[0] = 0;
        int i, j;

        // Build the table val[] in bottom up manner and return the last entry
        // from the table
        for (i = 1; i <= n; i++)
        {
            int max_val = INT_MIN;
            for (j = 0; j < i; j++)
                max_val = max(max_val, price[j] + val[i - j - 1]);
            val[i] = max_val;
        }

        return val[n];
    }
};
int main()
{
    vector<int> arr = {1, 5, 8, 9, 10, 17, 17, 20};
    vector<int> length = {1, 2, 3, 4, 5, 6, 7, 8};
    Solution s;
    cout << s.knapsackDP(arr, length, 8, 8);
}