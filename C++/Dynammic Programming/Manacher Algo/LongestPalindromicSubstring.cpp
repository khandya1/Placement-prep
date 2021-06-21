
using namespace std;
#include <bits\stdc++.h>

class Solution
{
public:
    string longestPalindrome(string s)      ////// 2D DP solution 
    {

        int n = s.size();
     //   int dp[n][n];
        vector<vector<bool>>dp(n, vector<bool>(n,0));
        string p = "";
        int maxi = 0, len = 0;

        for (int gap = 0; gap < n; gap++)
        {
            for (int i = 0, j = gap; j < n; i++, j++)
            {

                if (i == j)
                    {
                        len =0;
                        maxi=i;
                        dp[i][j] = 1;
                    }
                else if (j - i == 1 && s[i] == s[j])
                {
                    dp[i][j] = 1;
                    maxi = i;
                    len = 1;
                }

                else if (s[i] == s[j] && dp[i + 1][j - 1] != 0)
                {

                    dp[i][j] = 1;
                    maxi = i;
                    len = max(len, gap);
                }
            }
        }
        cout << maxi << len;
        return s.substr(maxi, len + 1);
    }
};
int main()
{
    
    Solution s;
   // vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    cout << s.longestPalindrome("aacabdkacaa") << endl;
    return 0;
}