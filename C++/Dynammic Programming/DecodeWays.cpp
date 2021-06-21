// https://leetcode.com/problems/decode-ways/submissions/
// lc 91 M

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numDecodings(string s)
    {
        if (s[0] == '0')
            return 0;
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= s.size(); i++)
        {
            int x = 0, y = 0;
            if (s[i - 1] > '0')
                x = dp[i - 1];
            int p = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
            cout << s[i - 2];
            if (p >= 10 && p < 27)
                y = dp[i - 2];

            dp[i] = x + y;
        }
        return dp[s.size()];
        // return numD(s,s.size());
    }
    int res1 = 0, res2 = 0;
    int numD(string s, int n)
    {

        if (s[0] == '0' || n == 0)
            return 0;
        else if (n == 1)
            return 1;

        if (s[n - 1] > '0')
            res1 = numD(s, n - 1);

        int p = (s[n - 2] - '0') * 10 + s[n - 1] - '0';

        if (p >= 10 && p < 27)
            res2 = numD(s, n - 2);

        return res1 + res2;
    }
};