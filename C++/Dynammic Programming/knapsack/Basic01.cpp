#include <bits/stdc++.h>
using namespace std;
class Solution
{
    
    int dp[11][11] = {-1};
   
    int knapsackRec(vector<int> value , vector<int> weight , int W, int n)
    {
        if(n==0 || W==0)//base case
        return 0;

        if(W<weight[n-1])
        return knapsackRec(value, weight, W , n-1);
        else
        return max(value[n-1]+ knapsackRec(value, weight, W-weight[n-1] , n-1) , knapsackRec(value, weight, W, n-1 ));

    }
    int knapsackMemo(vector<int> value , vector<int> weight , int W, int n)
    {
        if(n==0 || W==0)//base case
        return 0;

        if(dp[n][W]!=-1)
        return dp[n][W];

        if(W<weight[n-1])
        dp[n][W] = knapsackRec(value, weight, W , n-1);
        else
        dp[n][W] =  max(value[n-1]+ knapsackMemo(value, weight, W-weight[n-1] , n-1) , knapsackMemo(value, weight, W, n-1 ));

    }
    int knapsackDP(vector<int> value , vector<int> weight , int W, int n)
    {
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<W;j++)
            {
                if(i==0 || j== 0)
                dp[i][j] =0;
                else if(weight[i-1]>j)
                dp[i][j] = dp[i-1][j];
                else
                dp[i][j] = max(value[i-1]+dp[i-1][j-weight[i-1]], dp[i-1][j]);
            }
        }

        return dp[n][W];

    }

};