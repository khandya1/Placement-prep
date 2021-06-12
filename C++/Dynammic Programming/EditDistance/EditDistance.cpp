#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int editDist(string str1, string str2, int m, int n)
    {

        if (m == 0)
            return n;
        if (n == 0)
            return m;

        if (str1[m - 1] == str2[n - 1])
            return editDist(str1, str2, m - 1, n - 1);

        return 1 + min(editDist(str1, str2, m, n - 1),         // Insert
                       min(editDist(str1, str2, m - 1, n),     // Remove
                           editDist(str1, str2, m - 1, n - 1))); // Replace
    }

    int editDistDP(string X, string Y, int m , int n)
    {
        int dp[m+1][n+1]={0};
        if(m==0)
        return n;
        if(n==0)
        return m;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==0)
                dp[i][j]=j;
                else if(j==0)
                dp[i][j]=i;
                else if(X[i-1]==Y[j-1])
                dp[i][j]=dp[i-1][j-1];

                else
                dp[i][i]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
            }
        }
        return dp[m][n];
    }
};