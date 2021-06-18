using namespace std;
#include <bits\stdc++.h>

class Solution
{
public:
    int PalindromeRecr(string s, int l, int r)
    {
        if (l >= r)
            return 0;

        if (isPalindrome(s, l, r))
            return 0;

        int minn = INT_MAX;
        int temp;
        for (int k = l; k <= r; k++)
        {
            minn = min(minn, PalindromeRecr(s, l, k) + PalindromeRecr(s, k + 1, r) + 1);
        }
        return minn;
    }

    bool isPalindrome(string String, int i, int j)
    {
        while (i < j)
        {
            if (String[i] != String[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int MCMMemo(string s, int l, int r, vector<vector<int>> &dp)
    {

        if (l == r || isPalindrome(s,l,r))
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        dp[l][r] = INT_MAX;

        for (int k = l; k <= r; k++)
        {
            dp[l][r] = min(dp[l][r], MCMMemo(s, l, k, dp) + MCMMemo(s, k + 1, r, dp) + 1);
        }
        return dp[l][r];
    }

    int MCMDP(string s, int l, int r, vector<vector<int>> &dp)
    {

    for(int i=0;i<=l;i++)
    {
        for(int j =0;j<=i;j++)
        {
            dp[i][j]=INT_MAX;
        for (int k = i; k <=j; k++)
        {
            dp[i][j] = min(dp[i][j] , dp[i][k]+ dp[k + 1][j]+1);
        }
        }
    }
        return dp[l][r];
    }
};
int main()
{
    //vector<int> arr = {1, 2, 3, 4, 3};
    string s ="nitin";
    Solution s1;
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));

    cout << "Minimum number of multiplications is " << s1.MCMDP(s, 0, s.size() - 1, dp);
}