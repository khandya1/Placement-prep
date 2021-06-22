#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        int k = words.size();

        vector<int> adj[26];
        for (int i = 0; i < s.size(); i++)
        {
            adj[s[i] - 'a'].push_back(i);
        }
        int count = 0;
        for (auto word : words)
        {
            int curpos = -1;
            bool found = true;
            for (auto c : word)
            {
                auto it = upper_bound(adj[c - 'a'].begin(), adj[c - 'a'].end(), curpos);////// finds in log n time
                if (it == adj[c - 'a'].end())
                {
                    found = false;
                    break;
                }
                else
                    curpos = *it;
            }
            if (found == true)
                count++;
        }
        return count;
    }

    /////////////TLE solution 

    int numMatchingSubseqLCS(string s, vector<string> &words)
    {
        int k = words.size();

        int count = 0;
        while (k--)
        {
            int n = s.size();
            int m = words[k].size();
            vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
            for (int i = 0; i <= n; i++)
            {

                for (int j = 0; j <= m; j++)
                {
                    if (i == 0 || j == 0)
                        dp[i][j] = 0;
                    else if (s[i - 1] == words[k][j - 1])
                        dp[i][j] = dp[i - 1][j - 1] + 1;

                    else
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
            if (dp[n][m] == m)
                count++;
        }
        return count;
    }
};